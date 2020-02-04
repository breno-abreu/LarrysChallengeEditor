#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "GerenciadorPersistencia.h"
//Classe que contém os métodos relativos ao salvamento e carregamento de fases que estão contidas na pasta 'Fases'.
//Os arquivos possuem a extensão .LCS.

class GerenciadorPersistencia
{
public:
	GerenciadorPersistencia();
	~GerenciadorPersistencia();
	bool excluir_arquivo(const string nomeArquivo);
	bool pesquisar_lista_arquivos(const string nomeArquivo);
	bool salvar(ListaEntidades* listaEntidades, const string nomeArquivo);
	ListaEntidades* carregar(const string nomeArquivo, RenderWindow* _window);
	void listar_arquivos();
};

