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
	int tipoEntidade;
	Text* texto;
	Font* fonte;
	string frase;
	bool confirmar;
	bool recusar;

public:
	Menu();
	Menu(RenderWindow* _window);
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
	bool getConfirmar()const;
	void setConfirmar(const bool _confirmar);
	void setRecusar(const bool _recusar);
	bool getRecusar()const;

};

