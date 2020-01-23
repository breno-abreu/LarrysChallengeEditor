#include "Menu.h"

Menu::Menu()
{
}


Menu::~Menu()
{
	delete background;
	delete listaEntidades;
	listaBotoes.clear();
}

Menu::Menu(RenderWindow* _window)
{
	origemxBackground = 1200;
	origemyBackground = 0;
	window = _window;
	xBackground = 1200;
	tipoEntidade = 0;
	acao = 1;
	yBackground = 0;
	listaEntidades = new ListaEntidades(_window);
	background = new RectangleShape();
	background->setSize(Vector2f(400, 900));
	background->setPosition(origemxBackground, origemyBackground);
	background->setFillColor(Color::Color(160, 160, 160, 255));
	criar_botoes();
	criar_botoes_entidades();
}
void Menu::executar_botoes(const float xView, const float yView)
{
	list<Botao*>::iterator itr;
	for (itr = listaBotoes.begin(); itr != listaBotoes.end(); itr++) {
		(*itr)->desenhar_botao(xView, yView);
	}
}
void Menu::executar_entidades(const float xView, const float yView)
{
	listaEntidades->percorrer_menu(xView, yView);
}
void Menu::executar(const float xView, const float yView)
{
	executar_background(xView, yView);
	executar_botoes(xView, yView);
	executar_entidades(xView, yView);
}
void Menu::executar_background(const float xView, const float yView)
{
	window->draw(*background);
	//background->setPosition(xView, yView);
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
	Botao* novo = new Botao(window, 1225, 25, "Novo", 25, NOVO);
	listaBotoes.push_back(novo);

	Botao* carregar = new Botao(window, 1350, 25, "Carregar", 10, CARREGAR);
	listaBotoes.push_back(carregar);

	Botao* salvar = new Botao(window, 1475, 25, "Salvar", 22, SALVAR);
	listaBotoes.push_back(salvar);
}

void Menu::verificar_botoes(const int mousex, const int mousey)
{
	list<Botao*>::iterator itr;
	for (itr = listaBotoes.begin(); itr != listaBotoes.end(); itr++) {
		if (mousex > (*itr)->getxBotao() && mousex < (*itr)->getxBotao() + (*itr)->getComprimento() &&
			mousey >(*itr)->getyBotao() && mousey < (*itr)->getyBotao() + (*itr)->getAltura()) {

		}
			//cout << (*itr)->getTipo() << endl;
	}
}
void Menu::verificar_botoes_entidade(const int mousex, const int mousey)
{
	int aux = listaEntidades->verificar_entidades_menu(mousex, mousey);
	if (aux != -1)
		tipoEntidade = aux;
}

void Menu::criar_botoes_entidades()
{
	int cx = 1250;
	int cy = 100;
	int cont = 0;
	int distanciaPadrao = 60;

	for (int i = 0; i < 55; i++) {
		listaEntidades->adicionar_entidade(cx, cy, i, 2);
		cx += distanciaPadrao;
		cont++;

		if (cont == 6) {
			cont = 0;
			cy += distanciaPadrao;
			cx = 1250;
		}
	}
}

