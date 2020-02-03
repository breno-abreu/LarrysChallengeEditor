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
	int comprimentoUnidade;
	int alturaUnidade;
	int quantidadeLinhas;
	int quantidadeColunas;
	int tipo;
	float xEntidade;
	float yEntidade;
	float xEntidadeOrigem;
	float yEntidadeOrigem;
	float comprimento;
	float altura;
	float cx;
	float cy;
	bool existe;
	string nome;
	string diretorio;
	RenderWindow *window;
	RectangleShape entidade;
	Texture *textura;

public:
	Entidade();
	Entidade(RenderWindow* _window, Texture* _textura, float _xEntidade, float _yEntidade, int _codigo, int _profundidade, int _tipo, float proporcao = 3);
	~Entidade();
	void existir(int viewx, int viewy);
	void existir_menu(const float xView, const float yView);
	void desenhar_entidade();
	void setCodigo(const int codigo);
	void setTipo(const int _nome);
	void setxEntidade(const float xEntidade);
	void setyEntidade(const float yEntidade);
	void setComprimento(const float comprimento);
	void setAltura(const float altura);
	void setxTile(const int xTile);
	void setyTile(const int yTile);
	void setExiste(const bool existe);
	void setProfundidade(const int profundidade);
	void setDirecao(const int direcao);
	void setRenderWindow(RenderWindow* _window);
	void setCoordenadas(const float _xEntidade, const float _yEntidade);
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
	int getTipo() const;
	bool operator == (const Entidade& _entidade) const;
	bool operator != (const Entidade& _entidade) const;
	//bool operator < (const Entidade& _entidade) const;

};

