#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
#include "GerenciadorFase.h"
#include "GerenciadorEntidades.h"
#include "BotaoUI.h"

class LarrysChallenge
{
private:
	GerenciadorFase *gerenciadorFase;
	string tipoMouse;
	RenderWindow *window;
	Entidade* imagemMouse;
	string tipoEntidade;
	GerenciadorEntidades* gerenciadorEntidades;
	RectangleShape* mouse;
	Texture* texturaMouse;
	Vector2i mousePos;
	View *view;
	const float VIEW_HEIGHT;
	const float	VIEW_WITDH;
	float aspectRatio;

	Clock clock;

	RectangleShape* entidade;
	bool magnetico;
	int xMouse;
	int yMouse;

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

