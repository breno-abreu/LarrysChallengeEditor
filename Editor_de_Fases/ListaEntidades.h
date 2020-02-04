#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
#include "GerenciadorEntidades.h"

class ListaEntidades
{
private:
	GerenciadorEntidades *gerenciadorEntidades;
	list<Entidade*> listaEntidades;
	int codigo;

public:
	ListaEntidades();
	ListaEntidades(RenderWindow* _window);
	~ListaEntidades();
	void adicionar_entidade(const int mousex, const int mousey, const int tipo, float proporcao, int viewx = 0, int viewy = 0);
	void adicionar_entidade_menu(int mousex, int mousey, int tipo, float proporcao, int viewx = 0, int viewy = 0);
	void excluir_entidade(const int mousex, const int mousey, int viewx, int viewy);
	void percorrer(int view, int viey);
	void percorrer_menu(const float xView, const float yView);
	void limpar();
	void ordenar();
	bool vazio();
	list<Entidade*> getLista();
	void setLista(list<Entidade*> lista);
	int verificar_entidades_menu(const int mousex, const int mousey);
};

