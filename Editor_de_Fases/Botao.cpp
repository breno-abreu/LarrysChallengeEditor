#include "Botao.h"

Botao::Botao()
{
	ativo = false;
	altura = 0;
	comprimento = 0;
	distanciax = 0;
	distanciay = 0;
	distanciaxTexto = 0;
	xBotao = 0;
	yBotao = 0;
	tipo = 0;
	window = NULL;
}

Botao::Botao(RenderWindow* _window, const float _distanciax, const float _distanciay, const string _texto, const float _distanciaxTexto, const int _tipo)
{
	ativo = false;
	altura = 30;
	comprimento = 100;
	distanciax = _distanciax;
	distanciay = _distanciay;
	distanciaxTexto = _distanciaxTexto;
	xBotao = _distanciax;
	yBotao = _distanciay;
	tipo = _tipo;
	window = _window;

	botao.setSize(Vector2f(comprimento, altura));
	botao.setPosition(Vector2f(window->getSize().x - distanciax, distanciay));
	botao.setFillColor(Color::Color(210, 210, 210, 255));
	botao.setOutlineColor(Color::Black);
	botao.setOutlineThickness(1);
	
	if (!fonte.loadFromFile("Arial.ttf")) {
		cout << "Erro ao carregar a fonte!" << endl;
	}

	texto.setFont(fonte);
	texto.setString(_texto);
	texto.setCharacterSize(20);
	texto.setFillColor(Color::Black);
	texto.setPosition(Vector2f(window->getSize().x - distanciax + distanciaxTexto, distanciay +  3));
}

Botao::~Botao()
{

}

void Botao::desenhar_botao()
{
	window->draw(botao);
	botao.setPosition(Vector2f(xBotao, yBotao));
	window->draw(texto);
	texto.setPosition(Vector2f(xBotao + distanciaxTexto, yBotao + 3));
}

void Botao::desativar()
{
	ativo = false;
}

void Botao::ativar()
{
	ativo = true;
}

void Botao::setCoordenadas(const float _xBotao, const float _yBotao)
{
	xBotao = _xBotao;
	yBotao = _yBotao;
}

void Botao::setxBotao(const float _xBotao)
{
	xBotao = _xBotao;
}

void Botao::setyBotao(const float _yBotao)
{
	yBotao = _yBotao;
}

float Botao::getxBotao() const
{
	return xBotao;
}

float Botao::getyBotao() const
{
	return yBotao;
}

float Botao::getAltura()const
{
	return altura;
}

float Botao::getComprimento()const
{
	return comprimento;
}

int Botao::getTipo()const
{
	return tipo;
}

float Botao::getDistanciax()const
{
	return distanciax;
}
float Botao::getDistanciay()const
{
	return distanciay;
}