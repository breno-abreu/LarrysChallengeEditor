#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "GerenciadorPersistencia.h"

class GerenciadorFase
{
private:
	ListaEntidades *listaEntidades;
	RenderWindow* window;
	GerenciadorPersistencia* gerenciadorPersistencia;

public:
	GerenciadorFase();
	GerenciadorFase(RenderWindow* _window);
	~GerenciadorFase();
	void executar_fase(int mousex, int mousey, int viewx, int viewy);
	void adicionar_entidade(const int mousex, const int mousey, const int tipo, int viewx = 0, int viewy = 0);
	void excluir_entidade(int mousex, int mousey);
	void limpar_fase();
	void salvar_fase(string nomeArquivo);
	void carregar_fase(string nomeArquivo);
	void setListaEntidades(ListaEntidades* _listaEntidades);
};

