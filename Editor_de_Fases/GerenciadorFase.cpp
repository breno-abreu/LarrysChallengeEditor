#include "GerenciadorFase.h"

GerenciadorFase::GerenciadorFase()
{
	listaEntidades = NULL;
}

GerenciadorFase::GerenciadorFase(RenderWindow* _window)
{
	listaEntidades = new ListaEntidades(_window);
}

GerenciadorFase::~GerenciadorFase()
{
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
void GerenciadorFase::salvar_fase()
{

}
void GerenciadorFase::carregar_fase()
{

}