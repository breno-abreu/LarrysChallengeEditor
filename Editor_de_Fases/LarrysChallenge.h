#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
#include "GerenciadorFase.h"
#include "GerenciadorEntidades.h"
#include "Menu.h"
//Classse principal, onde será executado o loop principal do programa.

class LarrysChallenge
{
private:
	RenderWindow* window;
	GerenciadorFase *gerenciadorFase;
	GerenciadorEntidades* gerenciadorEntidades;
	Entidade* imagemMouse;
	RectangleShape* mouse;
	Texture* texturaMouse;
	View* view;
	Menu* menu;

	int tipoEntidade;
	int tipoMouse;
	int xMouse;
	int yMouse;
	int acao;
	const float comprimentoView;
	const float	alturaView;
	float auxVertical;
	float auxHorizontal;
	float vel;
	float comprimentoMouse;
	float alturaMouse;
	bool mouseLeft;
	bool mouseRight;
	bool excluir;
	bool done;
	int cont;
	string opcao;
	string arquivo;

public:
	LarrysChallenge();
	~LarrysChallenge();
	void executar();
	void desenhar_mouse();
	void acao_mouse();
	void mudar_imagem_mouse();
};

