#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"

class GerenciadorFase
{
private:
	ListaEntidades *listaEntidades;

public:
	GerenciadorFase();
	GerenciadorFase(RenderWindow* _window);
	~GerenciadorFase();
	void executar_fase(int mousex, int mousey);
	void adicionar_entidade(int mousex, int mousey, String tipo);
	void excluir_entidade(int mousex, int mousey);
	void limpar_fase();
	void salvar_fase();
	void carregar_fase();
};

