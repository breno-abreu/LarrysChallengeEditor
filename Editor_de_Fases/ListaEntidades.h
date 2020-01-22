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
	void adicionar_entidade(const int mousex, const int mousey, const string tipo);
	void excluir_entidade(const int mousex, const int mousey);
	void percorrer();
	void percorrer_menu(const float xView, const float yView);
	void limpar();
	void ordenar();
	bool vazio();
	list<Entidade*> getLista();
	void setLista(list<Entidade*> lista);
};

