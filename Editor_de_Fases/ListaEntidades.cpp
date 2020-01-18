#include "ListaEntidades.h"


ListaEntidades::ListaEntidades()
{
	codigo = 0;
	gerenciadorEntidades = NULL;
}

ListaEntidades::ListaEntidades(RenderWindow* _window)
{
	codigo = 0;
	gerenciadorEntidades = new GerenciadorEntidades(_window);
}

ListaEntidades::~ListaEntidades()
{
	limpar();
}

void ListaEntidades::adicionar_entidade(int mousex, int mousey, string tipo)
{
	codigo++;
	Entidade* entidade = gerenciadorEntidades->criar_entidade(mousex, mousey, tipo, codigo);
	listaEntidades.push_back(*entidade);
	ordenar();
}
void ListaEntidades::excluir_entidade(int mousex, int mousey)
{
	list<Entidade>::iterator itr;
	for (itr = listaEntidades.begin(); itr != listaEntidades.end(); itr++) {
		if (mousex > itr->getxEntidade() && mousex < itr->getxEntidade() + itr->getComprimento()
			&& mousey > itr->getyEntidade() && mousey < itr->getyEntidade() + itr->getAltura()) {
			listaEntidades.erase(itr);
			break;
		}
	}
}
void ListaEntidades::percorrer()
{
	list<Entidade>::iterator itr;
	for (itr = listaEntidades.begin(); itr != listaEntidades.end(); itr++) {
		itr->existir();
	}
}
void ListaEntidades::limpar()
{
	listaEntidades.clear();
	codigo = 0;
}
void ListaEntidades::ordenar()
{
	listaEntidades.sort();
}
