#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
#include "GerenciadorEntidades.h"
//Classe que irá implementar uma lista de Entidades e suas principais funcionalidades...
//... como incluir e excluir elementos e percorrer a lista.

class ListaEntidades
{
private:
	GerenciadorEntidades *gerenciadorEntidades;
	list<Entidade*> listaEntidades;
	int codigo;
	int conexao;

public:
	ListaEntidades();
	ListaEntidades(RenderWindow* _window);
	~ListaEntidades();
	bool vazio();
	int verificar_entidades_menu(const int mousex, const int mousey);
	list<Entidade*> getLista();
	void adicionar_entidade_carregar(const int mousex, const int mousey, const int tipo, const float proporcao, const string _conexao = "-1");
	void adicionar_entidade_menu(const int mousex, const int mousey, const int tipo, const float proporcao, const int viewx = 0, const int viewy = 0);
	void adicionar_entidade(const int mousex, const int mousey, const int tipo, const float proporcao, const int viewx = 0, const int viewy = 0);
	void excluir_entidade(const int mousex, const int mousey, const int viewx, int const viewy);
	void limpar();
	void ordenar();
	void percorrer_menu(const float xView, const float yView);
	void percorrer(const int view, const int viey);
	void setConexao(const int conexao);
	void setLista(list<Entidade*> lista);



};

