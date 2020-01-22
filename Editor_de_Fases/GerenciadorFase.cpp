#include "GerenciadorFase.h"

GerenciadorFase::GerenciadorFase()
{
	window = NULL;
	listaEntidades = NULL;
	gerenciadorPersistencia = NULL;
}

GerenciadorFase::GerenciadorFase(RenderWindow* _window)
{
	listaEntidades = new ListaEntidades(_window);
	window = _window;
	gerenciadorPersistencia = new GerenciadorPersistencia();
}

GerenciadorFase::~GerenciadorFase()
{
	delete listaEntidades;
	delete gerenciadorPersistencia;
}

void GerenciadorFase::executar_fase(int mousex, int mousey)
{
	listaEntidades->percorrer();
}
void GerenciadorFase::adicionar_entidade(int mousex, int mousey, string tipo)
{
	listaEntidades->adicionar_entidade(mousex, mousey, tipo);
}
void GerenciadorFase::excluir_entidade(int mousex, int mousey)
{
	listaEntidades->excluir_entidade(mousex, mousey);
}
void GerenciadorFase::limpar_fase()
{
	listaEntidades->limpar();
}
void GerenciadorFase::salvar_fase(string nomeArquivo)
{
	gerenciadorPersistencia->salvar(listaEntidades, nomeArquivo);
}
void GerenciadorFase::carregar_fase(string nomeArquivo)
{
	limpar_fase();
	listaEntidades = gerenciadorPersistencia->carregar(nomeArquivo, window);
}

void GerenciadorFase::setListaEntidades(ListaEntidades* _listaEntidades)
{
	listaEntidades = _listaEntidades;
}