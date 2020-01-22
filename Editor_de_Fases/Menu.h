#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "Botao.h"
class Menu
{
private:
	ListaEntidades* listaEntidades;
	list<Botao*> listaBotoes;
	int acao;
	RectangleShape* background;
	RenderWindow* window;
	float origemxBackground;
	float origemyBackground;
	float xBackground;
	float yBackground;

public:
	Menu();
	Menu(RenderWindow* _window);
	~Menu();
	void executar_botoes(const float xView, const float yView);
	void executar_entidades(const float xView, const float yView);
	void executar(const float xView, const float yView);
	void executar_background(const float xView, const float yView);
	void setAcao(const int _acao);
	int getAcao() const;
	void criar_botoes();
	void verificar_botoes(const int mousex, const int mousey);
	void criar_botoes_entidades();
	void verificar_botoes_entidade(const int mousex, const int mousey);

};

