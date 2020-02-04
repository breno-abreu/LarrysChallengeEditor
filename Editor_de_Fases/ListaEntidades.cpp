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
	delete gerenciadorEntidades;
}

void ListaEntidades::adicionar_entidade(int mousex, int mousey, int tipo, float proporcao, int viewx, int viewy)
{
	codigo++;
	Entidade* entidade = gerenciadorEntidades->criar_entidade(mousex - viewx, mousey - viewy, tipo, codigo, proporcao);

	if (tipo == 31 || tipo == 34 || tipo == 35 ||
		tipo == 42 || tipo == 43 || tipo == 44 ||
		tipo == 45 || tipo == 47 || tipo == 49 ||
		tipo == 52) {


		int conexao;
		system("cls");
		cout << "Estabelecer conexao: " << endl;
		cin >> conexao;
		string aux = to_string(conexao);
		entidade->setConexao(aux);
	}

	listaEntidades.push_back(entidade);
	ordenar();
}

void ListaEntidades::adicionar_entidade_menu(int mousex, int mousey, int tipo, float proporcao, int viewx, int viewy)
{
	codigo++;
	Entidade* entidade = gerenciadorEntidades->criar_entidade(mousex - viewx, mousey - viewy, tipo, codigo, proporcao);
	listaEntidades.push_back(entidade);
	ordenar();
}
void ListaEntidades::excluir_entidade(int mousex, int mousey, int viewx, int viewy)
{
	list<Entidade*>::reverse_iterator itr;
	/*for (itr = listaEntidades.rbegin(); itr != listaEntidades.rend(); itr++) {
		if (mousex - viewx > (*itr)->getxEntidade() && mousex - viewx < (*itr)->getxEntidade() + (*itr)->getComprimento()
			&& mousey - viewy > (*itr)->getyEntidade() && mousey - viewy < (*itr)->getyEntidade() + (*itr)->getAltura()) {
			listaEntidades.erase(next(itr).base());
			break;
		}
	}*/

	for (itr = listaEntidades.rbegin(); itr != listaEntidades.rend(); itr++) {
		if (mousex > (*itr)->getxEntidade() && mousex < (*itr)->getxEntidade() + (*itr)->getComprimento()
			&& mousey >(*itr)->getyEntidade() && mousey < (*itr)->getyEntidade() + (*itr)->getAltura()) {
			listaEntidades.erase(next(itr).base());
			break;
		}
	}
}
void ListaEntidades::percorrer(int viewx, int viewy)
{
	list<Entidade*>::iterator itr;
	for (itr = listaEntidades.begin(); itr != listaEntidades.end(); itr++) {
		(*itr)->existir(viewx, viewy);
	}
}
void ListaEntidades::percorrer_menu(const float xView, const float yView)
{
	list<Entidade*>::iterator itr;
	for (itr = listaEntidades.begin(); itr != listaEntidades.end(); itr++) {
		(*itr)->existir_menu(xView, yView);
	}
}
void ListaEntidades::limpar()
{
	listaEntidades.clear();
	codigo = 0;
}
void ListaEntidades::ordenar()
{
	listaEntidades.sort([](Entidade * a, Entidade * b) {return a->getProfundidade() < b->getProfundidade(); });
}

bool ListaEntidades::vazio()
{
	return listaEntidades.empty();
}

list<Entidade*> ListaEntidades::getLista()
{
	return listaEntidades;
}

void ListaEntidades::setLista(list<Entidade*> lista) 
{
	listaEntidades = lista;
}

int ListaEntidades::verificar_entidades_menu(const int mousex, const int mousey)
{
	list<Entidade*>::iterator itr;
	for (itr = listaEntidades.begin(); itr != listaEntidades.end(); itr++){
		if (mousex > (*itr)->getxEntidade() && mousex < (*itr)->getxEntidade() + (*itr)->getComprimento()
			&& mousey >(*itr)->getyEntidade() && mousey < (*itr)->getyEntidade() + (*itr)->getAltura()) {
			return (*itr)->getTipo();
		}
	}
	return -1;
}
