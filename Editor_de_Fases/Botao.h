#pragma once
#include "bibliotecas.h"
//Classe dos bot�es utilizados no menu para efetuar as a��es de criar, carregar e salvar fase. 
//Na vers�o 1.0 h� apenas um bot�o para que as a��es listadas acima possam ser realizadas a partir do terminal.

class Botao
{
private:
	bool ativo;
	float altura;
	float comprimento;
	float distanciax;
	float distanciay;
	float distanciaxTexto;
	float xBotao;
	float yBotao;
	short int tipo;
	RectangleShape botao;
	RenderWindow* window;
	Text texto;
	Font fonte;

public:
	Botao();
	Botao(RenderWindow* _window, const float _distanciax, const float _distanciay, const string _texto, const float _distanciaxTexto, const int _tipo);
	~Botao();
	void ativar();
	void desativar();
	void desenhar_botao();
	void setCoordenadas(const float _xBotao, const float _yBotao);
	void setxBotao(const float _xBotao);
	void setyBotao(const float _yBotao);
	float getAltura()const;
	float getComprimento() const;
	float getDistanciax() const;
	float getDistanciay() const;
	float getxBotao() const;
	float getyBotao() const;
	int getTipo() const;
};

