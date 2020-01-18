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
	void adicionar_entidade(int mousex, int mousey, string tipo);
	void excluir_entidade(int mousex, int mousey);
	void percorrer();
	void limpar();
	void ordenar();
	bool vazio();
	list<Entidade*> getLista();
	void setLista(list<Entidade*> lista);
};

