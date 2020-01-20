#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge():
	VIEW_HEIGHT(900.f),
	VIEW_WITDH(1600.f)
{
	window = new RenderWindow(VideoMode(1600, 900), "Larry's Challenge Editor", Style::Close | Style::Resize);
	gerenciadorFase = new GerenciadorFase(window);
	tipoMouse = "Jogador";
	imagemMouse = NULL;
	tipoEntidade = "Chao";
	mouse = new RectangleShape(Vector2f(16.0f, 16.0f));
	texturaMouse = new Texture();
	texturaMouse->loadFromFile("Tiny Dungeon Pack/Character/Char_one/Char_4_sides.png");
	mouse->setTexture(texturaMouse);
	gerenciadorEntidades = new GerenciadorEntidades(window);
	gerenciadorFase->adicionar_entidade(100, 100, "Chao");
	gerenciadorFase->adicionar_entidade(100, 150, "Chao");
	gerenciadorFase->adicionar_entidade(100, 150, "Chao");
	magnetico = true;
	xMouse = 0;
	yMouse = 0;
	window->setFramerateLimit(60);
	auxVertical = 0;
	auxHorizontal = 0;
	aspectRatio = 0;
	vel = 10;
	mouseLeft = false;
	entidade = new RectangleShape(Vector2f(32.f, 32.f));
	entidade->setFillColor(Color::Blue);
	entidade->setPosition(Vector2f());
	view = new View(Vector2f(0.0f, 0.0f), Vector2f(VIEW_WITDH, VIEW_HEIGHT));
	
	//window->setMouseCursorVisible(false);
	executar();
}


LarrysChallenge::~LarrysChallenge()
{
	delete window;
	delete gerenciadorEntidades;
	delete gerenciadorFase;
}

void LarrysChallenge::executar()
{
	while (window->isOpen()) {

		Event evnt;
		while (window->pollEvent(evnt)) {
			switch (evnt.type)
			{
			case Event::Closed:
				window->close();
				break;
			case Event::Resized:
				view->setSize((float) evnt.size.width ,(float)evnt.size.height);
				break;
			}
			
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
			auxHorizontal += vel;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
			auxHorizontal -= vel;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
			auxVertical -= vel;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
			auxVertical += vel;
		}
		
		Time time = clock.getElapsedTime();
		//cout << 1.0f / time.asSeconds() << endl;
		clock.restart().asSeconds();

		acao_mouse();
		window->clear(Color(50, 90, 80, 255));
		window->setView(*view);
		view->setCenter(Vector2f(auxHorizontal, auxVertical));
		desenhar_preview();
		gerenciadorFase->executar_fase(10, 10);
		entidade->setPosition(Vector2f(auxHorizontal + 200, auxVertical + 200));
		window->draw(*entidade);
		window->display();
	}
}
void LarrysChallenge::desenhar_preview()
{
	mousePos = Mouse::getPosition(*window);
	xMouse = mousePos.x / 32 * 32;
	yMouse = mousePos.y / 32 * 32;
	mouse->setPosition((float)xMouse, (float)yMouse);

	window->draw(*mouse); 
}

void LarrysChallenge::mudar_imagem_mouse()
{
	Vector2i mousePos = Mouse::getPosition(*window);

	imagemMouse = gerenciadorEntidades->criar_entidade((float)mousePos.x, (float)mousePos.y, tipoMouse);
}

void LarrysChallenge::acao_mouse()
{
	if (Mouse::isButtonPressed(Mouse::Left) && mouseLeft == false) {
			Vector2i mousePos = Mouse::getPosition(*window);
			gerenciadorFase->adicionar_entidade((float)xMouse, (float)yMouse, tipoEntidade);
			//mouseLeft = true;
			cout << "aqui" << endl;
	}
	if (Mouse::isButtonPressed(Mouse::Right)) {
		Vector2i mousePos = Mouse::getPosition(*window);
		gerenciadorFase->excluir_entidade((float)xMouse, (float)yMouse);
	}
	/*if (Mouse::isButtonPressed(Mouse::Left) == false && mouseLeft == true){
		mouseLeft = false;
	}*/
}