#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"

class GerenciadorPersistencia
{
private:
	list<string> arquivos;

public:
	GerenciadorPersistencia();
	~GerenciadorPersistencia();
	void salvar(ListaEntidades listaEntidades);
	void carregar(string arquivo);
	void salvar_lista_arquivos();
	void carregar_lista_arquivos();
	void ordenarListaArquivos();
	void adicionar_arquivo(string arquivo);
	void excluir_arquivo(string arquivo);
	bool pesquisar_lista_arquivos(string arquivo);
};

