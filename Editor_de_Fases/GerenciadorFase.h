#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "GerenciadorPersistencia.h"
//Classe que irá gerenciar as ações que uma fase terá que efetuar, como sua execução percorrendo a lista de objetos de Entidade, ...
//... inclusão e exclusão de Entidades, salvar e carregar uma fase.
//Serve apenas como uma classe intermediária entre a classe principal (LarrysChallenge) e as classes GerenciadorPersistencia e ListaEntidade.

class GerenciadorFase
{
private:
	GerenciadorPersistencia gerenciadorPersistencia;
	ListaEntidades* listaEntidades;
	RenderWindow* window;
	
public:
	GerenciadorFase();
	GerenciadorFase(RenderWindow* _window);
	~GerenciadorFase();
	void executar_fase(const int mousex, const int mousey, const int viewx, const int viewy);
	void adicionar_entidade(const int mousex, const int mousey, const int tipo, const int viewx = 0, const int viewy = 0, const float proporcao = 3);
	void excluir_entidade(const int mousex, const int mousey, const int viewx, const int viewy);
	void limpar_fase();
	void salvar_fase(const string nomeArquivo);
	void carregar_fase(const string nomeArquivo);
	void setListaEntidades(ListaEntidades* _listaEntidades);
	void listar_arquivos();
	void setConexao(const int _conexao);
	bool pesquisar_lista_arquivos(const string arquivo);
};

