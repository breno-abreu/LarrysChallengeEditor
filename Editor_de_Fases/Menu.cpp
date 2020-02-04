#include "Menu.h"

Menu::Menu():
	larguraMenu(400)
{
}


Menu::~Menu()
{
	delete background;
	delete listaEntidades;
	listaBotoes.clear();
}

Menu::Menu(RenderWindow* _window, View* _view):
	larguraMenu(400)
{
	view = _view;
	origemyBackground = 0;
	window = _window;
	origemxBackground = view->getSize().x - larguraMenu;
	xBackground = 1200;
	tipoEntidade = 0;
	yBackground = 0;
	listaEntidades = new ListaEntidades(_window);
	background = new RectangleShape();

	background->setSize(Vector2f(larguraMenu, view->getSize().y));
	background->setPosition(Vector2f(view->getSize().x - larguraMenu, 0));
	background->setFillColor(Color::Color(160, 160, 160, 255));
	acao = -1;
	frase = "";
	texto = new Text();
	fonte = new Font();
	if (!fonte->loadFromFile("Arial.ttf")) {
		cout << "Erro ao carregar a fonte!" << endl;
	}
	texto->setFont(*fonte);
	texto->setString(frase);
	texto->setCharacterSize(20);
	texto->setFillColor(Color::Color(200, 50, 50, 255));
	texto->setPosition(1225, 80);


	arquivoOut = new Text();
	arquivoOut->setFont(*fonte);
	arquivoOut->setCharacterSize(20);
	arquivoOut->setFillColor(Color::Blue);
	arquivoOut->setPosition(10, 10);
	arquivoOut->setString("");

	confirmar = false;
	recusar = false;
	criar_botoes();
	criar_botoes_entidades();

}
void Menu::executar_botoes(const float xView, const float yView)
{
	list<Botao*>::iterator itr;
	for (itr = listaBotoes.begin(); itr != listaBotoes.end(); itr++) {

		(*itr)->setCoordenadas(view->getCenter().x + (view->getSize().x / 2) - (*itr)->getDistanciax(), view->getCenter().y - (view->getSize().y / 2) + (*itr)->getDistanciay());


		if (acao < 3){
			(*itr)->desenhar_botao(xView, yView);
		}
		else {
			if ((*itr)->getTipo() < 3)
				(*itr)->desenhar_botao(xView, yView);
		}
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

	window->draw(*arquivoOut);
}
void Menu::executar_background(const float xView, const float yView)
{
	
	background->setSize(Vector2f(larguraMenu, view->getSize().y));
	background->setPosition(Vector2f(view->getCenter().x + (view->getSize().x / 2) - larguraMenu, view->getCenter().y - (view->getSize().y / 2)));

	window->draw(*background);
	window->draw(*texto);
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
	Botao* botao = new Botao(window, 375, 25, "Opções", 15, Botoes::OPCOES);
	listaBotoes.push_back(botao);

	/*botao = new Botao(window, 250, 25, "Carregar", 10, Botoes::CARREGAR);
	listaBotoes.push_back(botao);

	botao = new Botao(window, 125, 25, "Salvar", 22, Botoes::SALVAR);
	listaBotoes.push_back(botao);

	botao = new Botao(window, 375, 120, "Cancelar", 10, Botoes::CANCELAR);
	listaBotoes.push_back(botao);

	botao = new Botao(window, 250, 120, "ok", 37, Botoes::OK);
	listaBotoes.push_back(botao);*/

}

void Menu::verificar_botoes(const int mousex, const int mousey)
{
	list<Botao*>::iterator itr;
	for (itr = listaBotoes.begin(); itr != listaBotoes.end(); itr++) {
		if (mousex > (*itr)->getxBotao() && mousex < (*itr)->getxBotao() + (*itr)->getComprimento() &&
			mousey >(*itr)->getyBotao() && mousey < (*itr)->getyBotao() + (*itr)->getAltura()) {
			acao = 0;

			/*int aux = (*itr)->getTipo();
			switch (aux) {
			case 0:
				acao = aux;
				frase = "Criar nova fase?";
				break;
			case 1:
				acao = aux;
				frase = "Carregar fase?";
				break;
			case 2:
				acao = aux;
				frase = "Arquivo existente. Sobreescrever?";
				break;
			case 3:
				confirmar = true;
				frase = "";
				break;
			case 4:
				recusar = true;
				frase = "";
				break;
			}
			texto->setString(frase);*/
		}
		else
			acao = -1;
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

bool Menu::getConfirmar()const
{
	return confirmar;
}

void Menu::setConfirmar(const bool _confirmar)
{
	confirmar = _confirmar;
}

void Menu::setRecusar(const bool _recusar)
{
	recusar = _recusar;
}

bool Menu::getRecusar()const
{
	return recusar;
}

float Menu::getLarguraMenu()const
{
	return larguraMenu;
}

void Menu::setListaArquivos(const list<string> _listaArquivos)
{
	listaArquivos = _listaArquivos;
}

void Menu::setNomeArquivo(const string _texto)
{
	arquivoOut->setString(_texto);
	window->draw(*arquivoOut);
}