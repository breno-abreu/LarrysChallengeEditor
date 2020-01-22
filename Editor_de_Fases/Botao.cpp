#include "Botao.h"

Botao::Botao()
{

}
Botao::Botao(RenderWindow* _window, const float _distanciax, const float _distanciay, const string _texto, const float _distanciaxTexto, const int _tipo)
{
	xBotao = 0;
	yBotao = 0;
	//texto = _texto;
	window = _window;
	ativo = false;
	comprimento = 100;
	altura = 30;
	distanciax = _distanciax;
	distanciay = _distanciay;
	distanciaxTexto = _distanciaxTexto;
	botao = new RectangleShape();
	botao->setSize(Vector2f(comprimento, altura));
	botao->setPosition(0, 0);
	botao->setFillColor(Color::Color(200, 200, 200, 255));
	botao->setOutlineColor(Color::Black);
	botao->setOutlineThickness(1);
	fonte = new Font();
	if (!fonte->loadFromFile("Arial.ttf")) {
		cout << "Erro ao carregar a fonte!" << endl;
	}
	texto = new Text();
	texto->setFont(*fonte);
	texto->setString(_texto);
	texto->setCharacterSize(20);
	texto->setFillColor(Color::Black);
	texto->setPosition(xBotao, yBotao);
	tipo = _tipo;
}
Botao::~Botao()
{
	delete texto;
	delete botao;
	delete fonte;
}

void Botao::desenhar_botao(const float _xBotao, const float _yBotao)
{
	window->draw(*botao);
	botao->setPosition(_xBotao + distanciax, _yBotao + distanciay);
	window->draw(*texto);
	texto->setPosition(_xBotao + distanciax + distanciaxTexto, _yBotao + distanciay + 3);

	xBotao = botao->getPosition().x;
	yBotao = botao->getPosition().y;
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