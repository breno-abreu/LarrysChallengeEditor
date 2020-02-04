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

void GerenciadorFase::executar_fase(int mousex, int mousey, int viewx, int viewy)
{
	listaEntidades->percorrer(viewx, viewy);
}
void GerenciadorFase::adicionar_entidade(const int mousex, const int mousey, const int tipo, int viewx, int viewy, float proporcao)
{
	listaEntidades->adicionar_entidade(mousex, mousey, tipo, proporcao, viewx, viewy);
}
void GerenciadorFase::excluir_entidade(int mousex, int mousey, int viewx, int viewy)
{
	listaEntidades->excluir_entidade(mousex, mousey, viewx, viewy);
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

bool GerenciadorFase::pesquisar_lista_arquivos(const string arquivo)
{
	return gerenciadorPersistencia->pesquisar_lista_arquivos(arquivo);
}

void  GerenciadorFase::listar_arquivos()
{
	gerenciadorPersistencia->listar_arquivos();
}