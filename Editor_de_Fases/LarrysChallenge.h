#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
#include "GerenciadorFase.h"
#include "GerenciadorEntidades.h"
#include "Menu.h"

class LarrysChallenge
{
private:
	GerenciadorFase *gerenciadorFase;
	int tipoMouse;
	RenderWindow *window;
	Entidade* imagemMouse;
	int tipoEntidade;
	GerenciadorEntidades* gerenciadorEntidades;
	RectangleShape* mouse;
	Texture* texturaMouse;
	Vector2i mousePos;
	View *view;
	const float VIEW_HEIGHT;
	const float	VIEW_WITDH;
	float aspectRatio;

	Menu* menu;

	Clock clock;


	RectangleShape* entidade;
	bool magnetico;
	float xMouse;
	float yMouse;

	bool mouseLeft;

	float auxVertical;
	float auxHorizontal;
	float vel;

public:
	LarrysChallenge();
	~LarrysChallenge();
	void executar();
	void desenhar_preview();
	void acao_mouse();
	void mudar_imagem_mouse();
};

