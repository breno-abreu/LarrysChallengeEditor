#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "GerenciadorPersistencia.h"
//Classe que cont�m os m�todos relativos ao salvamento e carregamento de fases que est�o contidas na pasta 'Fases'.
//Os arquivos possuem a extens�o .LCS.

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

