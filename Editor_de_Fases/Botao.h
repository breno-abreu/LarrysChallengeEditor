#pragma once
#include "bibliotecas.h"

class Botao
{
private:
	RectangleShape* botao;
	RenderWindow* window;
	//string texto;
	float xBotao;
	float yBotao;
	bool ativo;
	float comprimento;
	float altura;
	Font *fonte;
	Text *texto;
	float distanciax;
	float distanciay;
	int tipo;
	float distanciaxTexto;

public:
	Botao();
	Botao(RenderWindow* _window, const float _distanciax, const float _distanciay, const string _texto, const float _distanciaxTexto, const int _tipo);
	~Botao();
	void setxBotao(const float _xBotao);
	void setyBotao(const float _yBotao);
	void setCoordenadas(const float _xBotao, const float _yBotao);
	float getxBotao() const;
	float getyBotao() const;
	void desenhar_botao(const float _xBotao, const float _yBotao);
	void desativar();
	void ativar();
	float getAltura()const;
	float getComprimento()const;
	int getTipo()const;
};

