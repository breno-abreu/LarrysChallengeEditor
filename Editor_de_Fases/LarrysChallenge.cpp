#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge():
	VIEW_HEIGHT(900.f),
	VIEW_WITDH(1600.f)
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
	auxHorizontal = 0;

	menu = new Menu(window);
	aspectRatio = 0;
	vel = 48;
	mouseLeft = false;
	mouseRight = false;
	comprimentoMouse = 0;
	alturaMouse = 0;
	view = new View(Vector2f(0.0f, 0.0f), Vector2f(VIEW_WITDH, VIEW_HEIGHT));

	auxMouse = false;
	view->setCenter(VIEW_WITDH / 2, VIEW_HEIGHT / 2);


	window->setMouseCursorVisible(false);
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
		view->setCenter(Vector2f(auxHorizontal, auxVertical));
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
	Vector2i mousePos = Mouse::getPosition(*window);
	//Mouse::setPosition(Vector2i(100, 100));

	if (xMouse < 1200) {
		xMouse = (mousePos.x / 24 * 24);
		yMouse = (mousePos.y / 24 * 24);

		if (tipoEntidade != -1) {
			window->setMouseCursorVisible(false);
			mouse->setSize(Vector2f(comprimentoMouse, alturaMouse));
		}
		else
			window->setMouseCursorVisible(true);
	}
	else {
		xMouse = mousePos.x;
		yMouse = mousePos.y;
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
	if (xMouse < 1200 && tipoEntidade != -1) {
		if (Mouse::isButtonPressed(Mouse::Left) && !mouseLeft) {
			gerenciadorFase->adicionar_entidade(xMouse, yMouse, tipoEntidade, auxHorizontal, auxVertical, 3);
			mouseLeft = true;
		}
		if (Mouse::isButtonPressed(Mouse::Right) && !mouseRight) {
			gerenciadorFase->excluir_entidade(xMouse, yMouse, auxHorizontal, auxVertical);
			mouseRight = true;
		}
	}
	else if (xMouse >= 1200) {
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
		}
	}
	
	if (!Mouse::isButtonPressed(Mouse::Left) && mouseLeft){
		mouseLeft = false;
	}
	if (!Mouse::isButtonPressed(Mouse::Right) && mouseRight) {
		mouseRight = false;
	}
}