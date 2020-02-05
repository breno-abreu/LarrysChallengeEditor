#include "GerenciadorPersistencia.h"

GerenciadorPersistencia::GerenciadorPersistencia()
{

}

GerenciadorPersistencia::~GerenciadorPersistencia()
{

}

bool GerenciadorPersistencia::salvar(ListaEntidades* listaEntidades, const string nomeArquivo)
{
	ofstream arquivo("Fases/" + nomeArquivo + ".lcs");
	list<Entidade*> lista = listaEntidades->getLista();
	list<Entidade*>::iterator itr;

	if (arquivo.is_open()) {
		if (!listaEntidades->vazio()) {
			for (itr = lista.begin(); itr != lista.end(); itr++) {
				arquivo << (*itr)->getTipo() << " " << (*itr)->getxEntidadeOrigem() << " " << (*itr)->getyEntidadeOrigem() << " " << (*itr)->getConexao() << endl;
			}
			arquivo.close();
			return true;
		}
	}
	return false;
}

ListaEntidades* GerenciadorPersistencia::carregar(const string nomeArquivo, RenderWindow* _window)
{
	ListaEntidades* lista = new ListaEntidades(_window);
	ifstream arquivo("Fases/" + nomeArquivo + ".lcs");
	int tipo = 1;
	float xEntidade = 0;
	float yEntidade = 0;
	string conexao = "";


	if (arquivo.is_open()) {
		while (!arquivo.eof()) {
			arquivo >> tipo >> xEntidade >> yEntidade >> conexao;
			if (arquivo.get() == '\n') {
				lista->adicionar_entidade_carregar(xEntidade, yEntidade, tipo, 3, conexao);
			}
		}
		arquivo.close();
	}
	return lista;
}

bool GerenciadorPersistencia::excluir_arquivo(const string nomeArquivo)
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

bool GerenciadorPersistencia::pesquisar_lista_arquivos(const string nomeArquivo)
{
	for (const auto& entry : filesystem::directory_iterator("Fases")) {
		if (entry.path().string() == "Fases\\" + nomeArquivo + ".lcs") {
			return true;
		}
	}
	return false;
}

void GerenciadorPersistencia::listar_arquivos()
{
	for (const auto& entry : filesystem::directory_iterator("Fases")) {
		cout << entry.path().string() << endl;
	}
}