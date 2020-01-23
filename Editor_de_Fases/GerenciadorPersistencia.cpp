#include "GerenciadorPersistencia.h"

GerenciadorPersistencia::GerenciadorPersistencia()
{
	listaEntidades = NULL;
}

GerenciadorPersistencia::~GerenciadorPersistencia()
{
	delete listaEntidades;
}

bool GerenciadorPersistencia::salvar(ListaEntidades* listaEntidades, string nomeArquivo)
{
	if (pesquisar_lista_arquivos(nomeArquivo)) {
		ofstream arquivo("Fases/" + nomeArquivo + ".lcs");
		list<Entidade*> lista = listaEntidades->getLista();
		list<Entidade*>::iterator itr;

		if (arquivo.is_open()) {
			if (!listaEntidades->vazio()) {
				for (itr = lista.begin(); itr != lista.end(); itr++) {
					arquivo << (*itr)->getTipo() << " " << (*itr)->getxEntidade() << " " << (*itr)->getyEntidade() << endl;
				}
				arquivo.close();
				return true;
			}
		}
	}
	return false;
}
ListaEntidades* GerenciadorPersistencia::carregar(string nomeArquivo, RenderWindow* _window)
{
	ifstream arquivo("Fases/" + nomeArquivo + ".lcs");
	listaEntidades = new ListaEntidades(_window);
	int tipo = 1;
	float xEntidade = 0;
	float yEntidade = 0;

	if (pesquisar_lista_arquivos(nomeArquivo)) {
		if (arquivo.is_open()) {
			while (!arquivo.eof()) {
				arquivo >> tipo >> xEntidade >> yEntidade;

				if (arquivo.get() == '\n') {
					listaEntidades->adicionar_entidade(xEntidade, yEntidade, tipo, 3);
				}
			}
			arquivo.close();
		}
		return listaEntidades;
	}
	return NULL;
}

bool GerenciadorPersistencia::excluir_arquivo(string nomeArquivo)
{
	string aux = "";
	for (const auto& entry : filesystem::directory_iterator("Fases")) {
		aux = nomeArquivo + "lcs";
		if (entry.path() == aux) {
			if (remove(aux.c_str()))
				return true;
			else
				return false;
		}
	}
	return false;
}
bool GerenciadorPersistencia::pesquisar_lista_arquivos(string nomeArquivo)
{
	/*list<string>::iterator itr;

	for (itr = arquivos.begin(); itr != arquivos.end(); itr++) {
		if (nomeArquivo == *itr)
			return true;
	}
	return false;*/

	for (const auto& entry : filesystem::directory_iterator("Fases")) {
		if (entry.path().string() == nomeArquivo + ".lcs") {
			return true;
		}
	}
	return false;
}

list<string> GerenciadorPersistencia::getArquivos()
{
	for (const auto& entry : filesystem::directory_iterator("Fases")) {
		arquivos.push_front(entry.path().string());
	}
	return arquivos;
}