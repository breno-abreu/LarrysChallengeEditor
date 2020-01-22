#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "GerenciadorPersistencia.h"

class GerenciadorPersistencia
{
private:
	list<string> arquivos;
	ListaEntidades* listaEntidades;

public:
	GerenciadorPersistencia();
	~GerenciadorPersistencia();
	bool salvar(ListaEntidades* listaEntidades, string nomeArquivo);
	ListaEntidades* carregar(string nomeArquivo, RenderWindow* _window);
	bool excluir_arquivo(string nomeArquivo);
	bool pesquisar_lista_arquivos(string nomeArquivo);
	list<string> getArquivos();
};

