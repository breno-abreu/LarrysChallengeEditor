#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "Botao.h"
class Menu
{
private:
	const int larguraMenu;
	float origemxBackground;
	float origemyBackground;
	float xBackground;
	float yBackground;
	int acao;
	int tipoEntidade;
	string arquivoIn;
	list<Botao*> listaBotoes;
	ListaEntidades* listaEntidades;
	RectangleShape background;
	RenderWindow* window;
	View* view;
	Text arquivoOut;

public:
	Menu();
	Menu(RenderWindow* _window, View* _view);
	~Menu();
	void executar_botoes(const float xView, const float yView);
	void executar_entidades(const float xView, const float yView);
	void executar(const float xView, const float yView);
	void executar_background(const float xView, const float yView);
	void setTipoEntidade(const int _acao);
	int getTipoEntidade() const;
	void criar_botoes();
	int getAcao() const;
	void setAcao(const int _acao);
	void verificar_botoes(const int mousex, const int mousey);
	void criar_botoes_entidades();
	void verificar_botoes_entidade(const int mousex, const int mousey);
	float getLarguraMenu()const;
	void setNomeArquivo(const string _texto);

};

