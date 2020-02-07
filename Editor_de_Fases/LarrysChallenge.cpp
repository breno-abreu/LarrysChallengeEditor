#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge():
	alturaView(480),
	comprimentoView(800)
{
	window = new RenderWindow(VideoMode(800, 480), "Larry's Challenge Editor", Style::Close | Style::Resize);
	window->setFramerateLimit(60);
	gerenciadorFase = new GerenciadorFase(window);
	gerenciadorEntidades = new GerenciadorEntidades(window);
	texturaMouse = new Texture();
	texturaMouse = gerenciadorEntidades->getTextura(0);
	view = new View(Vector2f(0.0f, 0.0f), Vector2f(comprimentoView, alturaView));
	view->setCenter(comprimentoView / 2, alturaView / 2);
	mouse = new RectangleShape(Vector2f(0, 0));
	menu = new Menu(window, view);
	imagemMouse = NULL;

	tipoEntidade = -1;
	tipoMouse = 1;
	xMouse = 0;
	yMouse = 0;
	acao = -1;
	auxVertical = 0;
	auxHorizontal = 0;
	vel = 48;
	comprimentoMouse = 0;
	alturaMouse = 0;
	mouseLeft = false;
	mouseRight = false;
	excluir = false;
	done = false;
	cont = 0;
	opcao = "";
	arquivo = "";

	executar();
}


LarrysChallenge::~LarrysChallenge()
{
	delete window;
	delete gerenciadorEntidades;
	delete gerenciadorFase;
	delete view;
}
//Loop principal.
void LarrysChallenge::executar()
{
	while (window->isOpen()) {

		Event event;
		while (window->pollEvent(event)) {
			switch (event.type)
			{
			case Event::Closed:
				window->close();
				break;
			case Event::Resized:
				view->setSize((float) event.size.width ,(float)event.size.height);
				break;
			}
			
		}

		if (cont == 3) {
			if (Keyboard::isKeyPressed(Keyboard::Key::Right)) 
				auxHorizontal -= vel;
			if (Keyboard::isKeyPressed(Keyboard::Key::Left)) 
				auxHorizontal += vel;
			if (Keyboard::isKeyPressed(Keyboard::Key::Up)) 
				auxVertical += vel;
			if (Keyboard::isKeyPressed(Keyboard::Key::Down)) 
				auxVertical -= vel;

			cont = 0;
		}
		cont++;

		window->clear(Color(50, 90, 80, 255));
		window->setView(*view);
		acao_mouse();
		gerenciadorFase->executar_fase(xMouse, yMouse, auxHorizontal, auxVertical);
		view->setCenter(comprimentoView / 2, alturaView / 2);
		menu->executar(auxHorizontal, auxVertical);
		desenhar_mouse();
		window->display();
	}
}
//Mouse agirá de formas diferentes dependendo de sua posição na tela.
void LarrysChallenge::desenhar_mouse()
{
	Vector2i mousePos = Mouse::getPosition(*window);
	Vector2f mouse_world = window->mapPixelToCoords(mousePos);

	//Caso o mouse esteja fora do menu.
	if (xMouse < view->getCenter().x + (view->getSize().x / 2) - menu->getLarguraMenu()) {
		//Caso o modo de exclusão não está ativo.
		if (!excluir) {
			xMouse = static_cast<int>(mouse_world.x / 24) * 24;
			yMouse = static_cast<int>(mouse_world.y / 24) * 24;

			if (tipoEntidade != -1) {
				window->setMouseCursorVisible(false);
				mouse->setSize(Vector2f(comprimentoMouse, alturaMouse));
			}
			else
				window->setMouseCursorVisible(true);
		}
		else {
			xMouse = mouse_world.x;
			yMouse = mouse_world.y;
			window->setMouseCursorVisible(true);
			mouse->setSize(Vector2f(0, 0));
		}
	}
	//Caso o mouse esteja dentro do menu.
	else {
		xMouse = mouse_world.x;
		yMouse = mouse_world.y;
		window->setMouseCursorVisible(true);
		mouse->setSize(Vector2f(0, 0));
	}

	mouse->setPosition((float)xMouse, (float)yMouse);
	window->draw(*mouse);
}

void LarrysChallenge::mudar_imagem_mouse()
{
	imagemMouse = gerenciadorEntidades->criar_entidade(xMouse, yMouse, tipoMouse);
}
//Caso o mouse seja pressionado, efetuará alguma das seguintes ações.
void LarrysChallenge::acao_mouse()
{
	//Caso o clique do mouse esteja fora do menu.
	if (xMouse < view->getCenter().x + (view->getSize().x / 2) - menu->getLarguraMenu() && tipoEntidade != -1) {
		if (Mouse::isButtonPressed(Mouse::Left) && !mouseLeft) {
			if (!excluir)
				gerenciadorFase->adicionar_entidade(xMouse, yMouse, tipoEntidade, auxHorizontal, auxVertical, 3);
			else
				gerenciadorFase->excluir_entidade(xMouse, yMouse, auxHorizontal, auxVertical);

			mouseLeft = true;
		}
		if (Mouse::isButtonPressed(Mouse::Right) && !mouseRight) {

			mouseRight = true;
			if (excluir == true)
				excluir = false;
			else
				excluir = true;
		}
	}
	//Caso o clique do mouse esteja no menu.
	else if (xMouse >= view->getCenter().x + (view->getSize().x / 2) - menu->getLarguraMenu()) {
		if (Mouse::isButtonPressed(Mouse::Left) && !mouseLeft) {

			menu->verificar_botoes(xMouse, yMouse);
			menu->verificar_botoes_entidade(xMouse, yMouse);
			tipoEntidade = menu->getTipoEntidade();
			mouseLeft = true;
			texturaMouse = gerenciadorEntidades->getTextura(tipoEntidade);
			comprimentoMouse = texturaMouse->getSize().x * 3;
			alturaMouse = texturaMouse->getSize().y * 3;
			RectangleShape* aux = new RectangleShape();

			mouse = aux;
			mouse->setTexture(texturaMouse);
			mouse->setSize(Vector2f(comprimentoMouse, alturaMouse));
			mouse->setOrigin(Vector2f(comprimentoMouse / 2, alturaMouse / 2));

			acao = menu->getAcao();

			//O seguinte código é relativo às funcionalidades que serão efetuadas no terminal...
			//... como carregar, salvar e criar nova fase.
			if (acao != -1) {

				while (!done) {
					system("cls");
					cout << "O que deseja fazer?: " << endl;
					cin >> opcao;
					system("cls");

					string novaAcao = "";
					if (opcao == "novo" || opcao == "Novo") {

						cout << "Criar nova fase?\nO conteudo da fase atual sera apagado definitivamente. " << endl;
						cin >> novaAcao;
						system("cls");
						if (novaAcao == "y" || novaAcao == "s" || novaAcao == "sim" || novaAcao == "Sim") {
							auxHorizontal = 0;
							auxVertical = 0;
							gerenciadorFase->limpar_fase();
							break;
						}
					}
					else if (opcao == "carregar" || opcao == "Carregar") {
						gerenciadorFase->listar_arquivos();
						cout << "\nDigite o nome do arquivo: " << endl;
						cin >> arquivo;

						if (gerenciadorFase->pesquisar_lista_arquivos(arquivo)) {
							auxHorizontal = 0;
							auxVertical = 0;
							gerenciadorFase->carregar_fase(arquivo);
							cout << "Fase '" << arquivo << "' carregada com sucesso!" << endl;
							break;
						}
							
						else
							cout << "\nArquivo nao existente." << endl;
					}
					else if (opcao == "salvar" || opcao == "Salvar") {
						gerenciadorFase->listar_arquivos();
						cout << "\nDigite o nome do arquivo: " << endl;
						cin >> arquivo;

						if (gerenciadorFase->pesquisar_lista_arquivos(arquivo)) {
							cout << "Arquivo com nome '" << arquivo << "' ja existe\nDeseja sobreescreve-lo?: " << endl;
							cin >> novaAcao;

							if (novaAcao == "y" || novaAcao == "s" || novaAcao == "sim" || novaAcao == "Sim") {
								gerenciadorFase->salvar_fase(arquivo);
								cout << "Fase salva com sucesso!" << endl;
								break;
							}
						}
						else {
							gerenciadorFase->salvar_fase(arquivo);
							break;
						}
					}
					else if (opcao == "cancelar" || opcao == "Cancelar" || opcao == "sair" || opcao == "Sair") {
						acao = -1;
						break;
					}
					else if (opcao == "conexao" || opcao == "Conexao") {
						int conexao;
						cout << "Definir conexao: " << endl;
						cin >> conexao;
						gerenciadorFase->setConexao(conexao);
						break;
					}
					else {
						cout << "Nao ha nenhuma acao com o nome '" << opcao << "'" << endl;
						system("pause");
					}
				}
			}
			system("cls");
		}
	}
	//Permite que seja executado apenas um clique do mouse, do contrário...
	//... caso um botão do mouse fosse pressionado, mais de um clique seria executado.
	if (!Mouse::isButtonPressed(Mouse::Left) && mouseLeft){
		mouseLeft = false;
	}
	if (!Mouse::isButtonPressed(Mouse::Right) && mouseRight) {
		mouseRight = false;
	}
}