#pragma once
#include "bibliotecas.h"

class Entidade
{
protected:
	int codigo;
	int xTile;
	int yTile;
	int profundidade;
	int direcao;
	float xEntidade;
	float yEntidade;
	float comprimento;
	float altura;
	bool existe;
	String tipo;
	String diretorio;
	RenderWindow *window;
	RectangleShape entidade;
	Texture textura;

public:
	Entidade();
	Entidade(RenderWindow* _window, String _tipo, String _diretorio, float _xEntidade, float _yEntidade, int _codigo, int _profundidade, int _direcao, float _comprimento = 16, float _altura = 16);
	~Entidade();
	void existir();
	void desenhar_entidade();
	void setCodigo(const int codigo);
	void setTipo(const String tipo);
	void setxEntidade(const float xEntidade);
	void setyEntidade(const float yEntidade);
	void setComprimento(const float comprimento);
	void setAltura(const float altura);
	void setxTile(const int xTile);
	void setyTile(const int yTile);
	void setExiste(const bool existe);
	void setProfundidade(const int profundidade);
	void setDirecao(const int direcao);
	int getCodigo() const;
	float getxEntidade() const;
	float getyEntidade() const;
	float getComprimento() const;
	float getAltura() const;
	int getxTile() const;
	int getyTile() const;
	int getProfundidade() const;
	int getDirecao() const;
	bool getExiste() const;
	String getTipo() const;
	bool operator == (const Entidade& _entidade) const;
	bool operator != (const Entidade& _entidade) const;
	bool operator < (const Entidade& _entidade) const;

};

