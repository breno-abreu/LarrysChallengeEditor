#include "GerenciadorPersistencia.h"



GerenciadorPersistencia::GerenciadorPersistencia()
{
}


GerenciadorPersistencia::~GerenciadorPersistencia()
{
}

void GerenciadorPersistencia::salvar(ListaEntidades listaEntidades)
{

}
void GerenciadorPersistencia::carregar(string arquivo)
{

}
void GerenciadorPersistencia::salvar_lista_arquivos()
{

}
void GerenciadorPersistencia::carregar_lista_arquivos()
{

}
void GerenciadorPersistencia::ordenarListaArquivos()
{
	arquivos.sort();
}
void GerenciadorPersistencia::adicionar_arquivo(string arquivo)
{

}
void GerenciadorPersistencia::excluir_arquivo(string arquivo)
{

}
bool GerenciadorPersistencia::pesquisar_lista_arquivos(string arquivo)
{
	list<string>::iterator itr;

	for (itr = arquivos.begin(); itr != arquivos.end(); itr++) {
		if (arquivo == *itr)
			return true;
	}

	return false;
}