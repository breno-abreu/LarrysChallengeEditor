#include "Menu.h"

Menu::Menu():
	larguraMenu(400)
{
	origemxBackground = 0;
	origemyBackground = 0;
	xBackground = 0;
	yBackground = 0;
	acao = 0;
	tipoEntidade = 0;
	arquivoIn = "";
	listaEntidades = NULL;
	window = NULL;
	view = NULL;
}

Menu::~Menu()
{
	delete listaEntidades;
	listaBotoes.clear();
}

Menu::Menu(RenderWindow* _window, View* _view):
	larguraMenu(400)
{
	view = _view;
	window = _window;
	origemyBackground = 0;
	origemxBackground = view->getSize().x - larguraMenu;
	xBackground = 1200;
	yBackground = 0;
	tipoEntidade = 0;
	listaEntidades = new ListaEntidades(_window);
	acao = -1;

	background.setSize(Vector2f(larguraMenu, view->getSize().y));
	background.setPosition(Vector2f(view->getSize().x - larguraMenu, 0));
	background.setFillColor(Color::Color(160, 160, 160, 255));

	criar_botoes();
	criar_botoes_entidades();

}

void Menu::executar_botoes(const float xView, const float yView)
{
	list<Botao*>::iterator itr;
	for (itr = listaBotoes.begin(); itr != listaBotoes.end(); itr++) {
		(*itr)->setCoordenadas(view->getCenter().x + (view->getSize().x / 2) - (*itr)->getDistanciax(), view->getCenter().y - (view->getSize().y / 2) + (*itr)->getDistanciay());
		(*itr)->desenhar_botao();
	}
}

void Menu::executar_entidades(const float xView, const float yView)
{
	listaEntidades->percorrer_menu(view->getCenter().x + (view->getSize().x / 2), view->getCenter().y - (view->getSize().y / 2));
}

void Menu::executar(const float xView, const float yView)
{
	executar_background(xView, yView);
	executar_botoes(xView, yView);
	executar_entidades(xView, yView);
	window->draw(arquivoOut);
}

void Menu::executar_background(const float xView, const float yView)
{
	
	background.setSize(Vector2f(larguraMenu, view->getSize().y));
	background.setPosition(Vector2f(view->getCenter().x + (view->getSize().x / 2) - larguraMenu, view->getCenter().y - (view->getSize().y / 2)));
	window->draw(background);
}

void Menu::setTipoEntidade(const int _tipoEntidade)
{
	tipoEntidade = _tipoEntidade;
}

int Menu::getTipoEntidade() const
{
	return tipoEntidade;
}

void Menu::criar_botoes()
{
	Botao* botao = new Botao(window, 375, 25, "Opções", 15, 0);
	listaBotoes.push_back(botao);
}
//Verifica se há um botão nas coordenadas recebidas.
void Menu::verificar_botoes(const int mousex, const int mousey)
{
	list<Botao*>::iterator itr;
	for (itr = listaBotoes.begin(); itr != listaBotoes.end(); itr++) {
		if (mousex > (*itr)->getxBotao() && mousex < (*itr)->getxBotao() + (*itr)->getComprimento() &&
			mousey >(*itr)->getyBotao() && mousey < (*itr)->getyBotao() + (*itr)->getAltura()) {
			acao = 0;
		}
		else
			acao = -1;
	}
}
//Verifica se há alguma entidade nas coordenadas recebidas.
void Menu::verificar_botoes_entidade(const int mousex, const int mousey)
{
	int aux = listaEntidades->verificar_entidades_menu(mousex, mousey);
	if (aux != -1)
		tipoEntidade = aux;
}
//Posiciona os botões do menu em um grade.
void Menu::criar_botoes_entidades()
{
	int cx = 50;
	int cy = 100;
	int cont = 0;
	int distanciaPadrao = 60;

	for (int i = 0; i < 55; i++) {
		listaEntidades->adicionar_entidade_menu(cx, cy, i, 2);
		cx += distanciaPadrao;
		cont++;

		if (cont == 6) {
			cont = 0;
			cy += distanciaPadrao;
			cx = 50;
		}
	}
}

int Menu::getAcao() const
{
	return acao;
}

void Menu::setAcao(const int _acao)
{
	acao = _acao;
}

float Menu::getLarguraMenu()const
{
	return larguraMenu;
}

void Menu::setNomeArquivo(const string _texto)
{
	arquivoOut.setString(_texto);
	window->draw(arquivoOut);
}