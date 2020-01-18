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
	void executar_fase(int mousex, int mousey);
	void adicionar_entidade(int mousex, int mousey, string tipo);
	void excluir_entidade(int mousex, int mousey);
	void limpar_fase();
	void salvar_fase(string nomeArquivo);
	void carregar_fase(string nomeArquivo);
	void setListaEntidades(ListaEntidades* _listaEntidades);
};

