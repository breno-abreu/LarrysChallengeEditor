#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
#include "GerenciadorFase.h"
#include "GerenciadorEntidades.h"

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

public:
	LarrysChallenge();
	~LarrysChallenge();
	void executar();
	void desenhar_preview();
	void acao_mouse();
	void mudar_imagem_mouse();
};

