#include "ListaEntidades.h"


ListaEntidades::ListaEntidades()
{
	codigo = 0;
	conexao = 0;
	gerenciadorEntidades = NULL;
}

ListaEntidades::ListaEntidades(RenderWindow* _window)
{
	codigo = 0;
	conexao = 0;
	gerenciadorEntidades = new GerenciadorEntidades(_window);
}

ListaEntidades::~ListaEntidades()
{
	limpar();
	delete gerenciadorEntidades;
}
//Inclusão de entidades na fase. Se o tipo for igual a um dos tipos citados abaixo, significa que o objeto possui uma conexão com outro.
void ListaEntidades::adicionar_entidade(const int mousex, const int mousey, const int tipo, const float proporcao, const int viewx, const int viewy)
{
	codigo++;
	Entidade* entidade = gerenciadorEntidades->criar_entidade(mousex - viewx, mousey - viewy, tipo, codigo, proporcao);

	if (tipo == 27 || tipo == 42 || tipo == 44 || 
		tipo == 45 || tipo == 46 || tipo == 48 || 
		tipo == 49 || tipo == 50 || tipo == 51 || 
		tipo == 52 || tipo == 57 || tipo == 59 ||
		tipo == 54 || tipo == 53) {
		string aux = to_string(conexao);
		entidade->setConexao(aux);
	}

	listaEntidades.push_back(entidade);
	ordenar();
}
//Inclusão de entidades do menu.
void ListaEntidades::adicionar_entidade_menu(const int mousex, const int mousey, const int tipo, const float proporcao, const int viewx, const int viewy)
{
	codigo++;
	Entidade* entidade = gerenciadorEntidades->criar_entidade(mousex - viewx, mousey - viewy, tipo, codigo, proporcao);
	listaEntidades.push_back(entidade);
	ordenar();
}
//Inclusão de entidades ao carregar uma fase por um arquivo.
void ListaEntidades::adicionar_entidade_carregar(const int mousex, const int mousey, const int tipo, const float proporcao, const string _conexao)
{
	codigo++;
	Entidade* entidade = gerenciadorEntidades->criar_entidade(mousex, mousey, tipo, codigo, proporcao);
	entidade->setConexao(_conexao);
	listaEntidades.push_back(entidade);
	ordenar();
}

void ListaEntidades::excluir_entidade(const int mousex, const int mousey, const int viewx, const int viewy)
{
	list<Entidade*>::reverse_iterator itr;
	for (itr = listaEntidades.rbegin(); itr != listaEntidades.rend(); itr++) {
		if (mousex > (*itr)->getxEntidade() && mousex < (*itr)->getxEntidade() + (*itr)->getComprimento()
			&& mousey >(*itr)->getyEntidade() && mousey < (*itr)->getyEntidade() + (*itr)->getAltura()) {
			listaEntidades.erase(next(itr).base());
			break;
		}
	}
}
//Percorrimento da lista da fase.
void ListaEntidades::percorrer(const int viewx, const int viewy)
{
	list<Entidade*>::iterator itr;
	for (itr = listaEntidades.begin(); itr != listaEntidades.end(); itr++) {
		(*itr)->existir(viewx, viewy);
	}
}
//Percorrimento da lista do menu.
void ListaEntidades::percorrer_menu(const float xView, const float yView)
{
	list<Entidade*>::iterator itr;
	for (itr = listaEntidades.begin(); itr != listaEntidades.end(); itr++) {
		(*itr)->existir_menu(xView, yView);
	}
}
//Verifica se há algum objeto nas coordenadas recebidas.
int ListaEntidades::verificar_entidades_menu(const int mousex, const int mousey)
{
	list<Entidade*>::iterator itr;
	for (itr = listaEntidades.begin(); itr != listaEntidades.end(); itr++) {
		if (mousex > (*itr)->getxEntidade() && mousex < (*itr)->getxEntidade() + (*itr)->getComprimento()
			&& mousey >(*itr)->getyEntidade() && mousey < (*itr)->getyEntidade() + (*itr)->getAltura()) {
			return (*itr)->getTipo();
		}
	}
	return -1;
}

void ListaEntidades::limpar()
{
	listaEntidades.clear();
	codigo = 0;
}
//Ordena a lista em relação ao atributo 'profundidade' de uma Entidade, dessa forma é possível...
//... posicionar objetos sobrepostos, causando o efeito de distância entre eles.
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

void ListaEntidades::setConexao(const int _conexao)
{
	conexao = _conexao;
}
