#pragma once
#include "bibliotecas.h"
//Classe dos objetos com representação gráfica.

class Entidade
{
protected:
	float altura;
	float comprimento;
	float xEntidade;
	float xEntidadeOrigem;
	float yEntidade;
	float yEntidadeOrigem;
	int codigo;
	short int profundidade;
	short int tipo;
	string conexao;
	RectangleShape entidade;
	RenderWindow* window;
	Texture* textura;
	Font fonte;
	Text texto;

public:
	Entidade();
	Entidade(RenderWindow* _window, Texture* _textura, const float _xEntidade, const float _yEntidade, const int _codigo, const int _profundidade, const int _tipo, const float _proporcao = 3);
	~Entidade();
	void desenhar_entidade();
	void existir_menu(const float xView, const float yView);
	void existir(const int viewx, const int viewy);
	void setAltura(const float altura);
	void setCodigo(const int codigo);
	void setComprimento(const float comprimento);
	void setConexao(const string conexao);
	void setCoordenadas(const float _xEntidade, const float _yEntidade);
	void setProfundidade(const int profundidade);
	void setTipo(const int _nome);
	void setxEntidade(const float xEntidade);
	void setyEntidade(const float yEntidade);
	float getAltura() const;
	float getComprimento() const;
	float getxEntidade() const;
	float getyEntidade() const;
	float getxEntidadeOrigem() const;
	float getyEntidadeOrigem() const;
	int getCodigo() const;
	int getProfundidade() const;
	int getTipo() const;
	string getConexao()const;
	bool operator != (const Entidade& _entidade) const;
	bool operator == (const Entidade& _entidade) const;
};

