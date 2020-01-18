#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge()
{
	window = new RenderWindow(VideoMode(500, 500), "Larry's Challenge Editor", Style::Close);
	gerenciadorFase = new GerenciadorFase(window);
	tipoMouse = "Jogador";
	imagemMouse = NULL;
	tipoEntidade = "Jogador";
	mouse = new RectangleShape(Vector2f(16.0f, 16.0f));
	texturaMouse = new Texture();
	texturaMouse->loadFromFile("Tiny Dungeon Pack/Character/Char_one/Char_4_sides.png");
	mouse->setTexture(texturaMouse);
	gerenciadorEntidades = new GerenciadorEntidades(window);
	gerenciadorFase->adicionar_entidade(10, 10, "Jogador");
	gerenciadorFase->adicionar_entidade(40, 10, "Jogador");
	window->setMouseCursorVisible(false);
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
			}
		}
		
		acao_mouse();
		window->clear();
		desenhar_preview();
		gerenciadorFase->executar_fase(10, 10);
		window->display();
	}
}
void LarrysChallenge::desenhar_preview()
{
	Vector2i mousePos = Mouse::getPosition(*window);
	mouse->setPosition((float)mousePos.x, (float)mousePos.y);
	window->draw(*mouse);
}

void LarrysChallenge::mudar_imagem_mouse()
{
	Vector2i mousePos = Mouse::getPosition(*window);

	if (tipoMouse == "NULL") {

	}
	else {
		imagemMouse = gerenciadorEntidades->criar_entidade((float)mousePos.x, (float)mousePos.y, tipoMouse);
	}
}

void LarrysChallenge::acao_mouse()
{
	if (Mouse::isButtonPressed(Mouse::Left)) {
			Vector2i mousePos = Mouse::getPosition(*window);
			gerenciadorFase->adicionar_entidade((float)mousePos.x, (float)mousePos.y, tipoEntidade);
	}
	if (Mouse::isButtonPressed(Mouse::Right)) {
		Vector2i mousePos = Mouse::getPosition(*window);
		gerenciadorFase->excluir_entidade((float)mousePos.x, (float)mousePos.y);
	}
}
