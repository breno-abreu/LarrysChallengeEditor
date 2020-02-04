#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge():
	VIEW_HEIGHT(900),
	VIEW_WITDH(1600)
{
	window = new RenderWindow(VideoMode(1600, 900), "Larry's Challenge Editor", Style::Close | Style::Resize);
	gerenciadorFase = new GerenciadorFase(window);
	tipoMouse = 1;
	imagemMouse = NULL;
	tipoEntidade = -1;
	mouse = new RectangleShape(Vector2f(0, 0));
	//mouse->setFillColor(Color::Blue);
	//texturaMouse = new Texture();
	//texturaMouse->loadFromFile("Tiny Dungeon Pack/Character/Char_one/Char_4_sides.png");
	
	gerenciadorEntidades = new GerenciadorEntidades(window);
	/*gerenciadorFase->adicionar_entidade(100, 100, "Chao");
	gerenciadorFase->adicionar_entidade(100, 150, "Chao");
	gerenciadorFase->adicionar_entidade(100, 150, "Chao");*/
	texturaMouse = new Texture();
	texturaMouse = gerenciadorEntidades->getTextura(0);
	/*mouse->setTexture(texturaMouse);
	mouse->setSize(Vector2f(texturaMouse->getSize().x * 3, texturaMouse->getSize().y * 3));
	mouse->setOrigin(Vector2f(texturaMouse->getSize().x * 3 / 2, texturaMouse->getSize().y * 3 / 2));*/
	magnetico = true;
	xMouse = 0;
	yMouse = 0;
	window->setFramerateLimit(60);
	auxVertical = 0;

	acao = -1;
	auxHorizontal = 0;

	opcao = "";
	aspectRatio = 0;
	vel = 48;
	mouseLeft = false;
	mouseRight = false;
	comprimentoMouse = 0;
	done = false;
	alturaMouse = 0;
	view = new View(Vector2f(0.0f, 0.0f), Vector2f(VIEW_WITDH, VIEW_HEIGHT));
	excluir = false;
	confirmar = false;
	recusar = false;
	
	auxMouse = false;
	view->setCenter(VIEW_WITDH / 2, VIEW_HEIGHT / 2);

	menu = new Menu(window, view);

	arquivo = "";


	//window->setMouseCursorVisible(false);
	executar();
}


LarrysChallenge::~LarrysChallenge()
{
	delete window;
	delete gerenciadorEntidades;
	delete gerenciadorFase;
	delete view;
}

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
			case Event::TextEntered:
				if (acao == 2) {
					
					/*system("cls");

					if (!arquivo.empty() && Keyboard::isKeyPressed(Keyboard::Key::BackSpace)) {
						arquivo.pop_back();
						arquivo.pop_back();
					}

					arquivo += event.text.unicode;
					menu->setNomeArquivo(arquivo);
					cout << arquivo << endl;*/
						
				}
				break;
			}
			
		}

		if (cont == 3) {
			if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
				auxHorizontal -= vel;
				//view->move(10, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
				auxHorizontal += vel;
				//view->move(-10, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
				auxVertical += vel;
				//view->move(0, -10);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
				auxVertical -= vel;
				//view->move(0, 10);
			}
			cont = 0;
		}






		cont++;



		
		Time time = clock.getElapsedTime();
		//cout << 1.0f / time.asSeconds() << endl;
		clock.restart().asSeconds();
		//Vector2i mousePos = Mouse::getPosition(*window);
		//Vector2i mousePos = Mouse::getPosition();
		//xMouse = mousePos.x;
		//yMouse = mousePos.y;
		//xMouse = (float)mousePos.x / 16 * 16;
		//yMouse = (float)mousePos.y / 16 * 16;
		//cout << tipoEntidade << endl;

		acao_mouse();
		window->clear(Color(50, 90, 80, 255));
		window->setView(*view);
		//view->setCenter(Vector2f(auxHorizontal, auxVertical));

		gerenciadorFase->executar_fase(xMouse, yMouse, auxHorizontal, auxVertical);
		view->setCenter(VIEW_WITDH / 2, VIEW_HEIGHT / 2);
		
		menu->executar(auxHorizontal, auxVertical);
		desenhar_mouse();
		window->display();
	}
}
void LarrysChallenge::desenhar_mouse()
{
	//mousePos = Mouse::getPosition(*window);
	//xMouse = (float)mousePos.x / 48 * 48;
	//yMouse = (float)mousePos.y / 48 * 48;
	//mousePos = Mouse::getPosition(*window);
	Vector2i mousePos = Mouse::getPosition(*window);
	//Mouse::setPosition(Vector2i(100, 100));
	Vector2f mouse_world = window->mapPixelToCoords(mousePos);

	if (xMouse < view->getCenter().x + (view->getSize().x / 2) - menu->getLarguraMenu()) {

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
	//Vector2i mousePos = Mouse::getPosition(*window);

	imagemMouse = gerenciadorEntidades->criar_entidade(xMouse, yMouse, tipoMouse);
}

void LarrysChallenge::acao_mouse()
{
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
	else if (xMouse >= view->getCenter().x + (view->getSize().x / 2) - menu->getLarguraMenu()) {
		if (Mouse::isButtonPressed(Mouse::Left) && !mouseLeft) {



			menu->verificar_botoes(xMouse, yMouse);
			menu->verificar_botoes_entidade(xMouse, yMouse);
			tipoEntidade = menu->getTipoEntidade();
			mouseLeft = true;
			texturaMouse = gerenciadorEntidades->getTextura(tipoEntidade);
			comprimentoMouse = texturaMouse->getSize().x * 3;
			alturaMouse = texturaMouse->getSize().y * 3;
			//mouse->setSize(Vector2f(comprimentoMouse, alturaMouse));
			//cout << texturaMouse->getSize().y << endl;


			RectangleShape* aux = new RectangleShape();
			mouse = aux;
			mouse->setTexture(texturaMouse);
			//mouse->setTextureRect(IntRect(mouse->getPosition().x, mouse->getPosition().y, comprimentoMouse, alturaMouse));
			mouse->setSize(Vector2f(comprimentoMouse, alturaMouse));
			mouse->setOrigin(Vector2f(comprimentoMouse / 2, alturaMouse / 2));

			acao = menu->getAcao();
			/*confirmar = menu->getConfirmar();
			recusar = menu->getRecusar();*/

			/*if (acao < 3) {
				if (confirmar) {
					if (acao == 0) 
						gerenciadorFase->limpar_fase();
					else if (acao == 1)
						gerenciadorFase->carregar_fase(arquivo);
					else if (acao == 2) {
						//gerenciadorFase->salvar_fase(arquivo);
					}
						

					menu->setConfirmar(false);
					menu->setAcao(3);
					confirmar = false;
					acao = -1;
				}
				if (recusar) {
					menu->setRecusar(false);
					menu->setAcao(3);
					recusar = false;
					acao = -1;
				}
			}*/

			if (acao != -1) {

				while (!done) {
					cout << "O que deseja fazer?: " << endl;
					cin >> opcao;
					system("cls");

					string novaAcao = "";
					if (opcao == "novo" || opcao == "Novo") {

						cout << "Criar nova fase?\nO conteudo da fase atual sera apagado definitivamente. " << endl;
						cin >> novaAcao;
						system("cls");
						if (novaAcao == "y" || novaAcao == "s" || novaAcao == "sim" || novaAcao == "Sim") {
							gerenciadorFase->limpar_fase();
							break;
						}
					}
					else if (opcao == "carregar" || opcao == "Carregar") {
						cout << "carregar" << endl;
					}
					else if (opcao == "salvar" || opcao == "Salvar") {
						cout << "Digite o nome do arquivo: " << endl;
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
							cout << "Fase salva com sucesso!" << endl;
							break;
						}
					}
					else if (opcao == "cancelar" || opcao == "Cancelar" || opcao == "sair" || opcao == "Sair") {
						acao = -1;
						break;
					}
					else
						cout << "Nao ha nenhuma acao com o nome '" << opcao << "'" << endl;
					//done = true;
				}
			}
		}
	}
	
	if (!Mouse::isButtonPressed(Mouse::Left) && mouseLeft){
		mouseLeft = false;
	}
	if (!Mouse::isButtonPressed(Mouse::Right) && mouseRight) {
		mouseRight = false;
	}
}