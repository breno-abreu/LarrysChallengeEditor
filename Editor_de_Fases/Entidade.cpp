#include "Entidade.h"

Entidade::Entidade(RenderWindow* _window, Texture* _textura, const float _xEntidade, const float _yEntidade, const int _codigo, const int _profundidade, const int _tipo, const float _proporcao)
{
	textura = _textura;
	comprimento = textura->getSize().x * _proporcao;
	altura = textura->getSize().y * _proporcao;
	xEntidade = _xEntidade;
	yEntidade = _yEntidade;
	xEntidadeOrigem = xEntidade;
	yEntidadeOrigem = yEntidade;
	codigo = _codigo;
	profundidade = _profundidade;
	tipo = _tipo;
	conexao = "-1";
	window = _window;

	entidade.setPosition(xEntidade, yEntidade);
	entidade.setSize(Vector2f(comprimento, altura));
	entidade.setOrigin(Vector2f(comprimento / 2, altura / 2));
	entidade.setTexture(textura);

	if (!fonte.loadFromFile("Arial.ttf")) {
		cout << "Erro ao carregar a fonte!" << endl;
	}
	
	texto.setFont(fonte);
	texto.setString(conexao);
	texto.setCharacterSize(17);
	texto.setFillColor(Color::Blue);
	texto.setPosition(xEntidade - comprimento / 1.2, yEntidade - 15);
}

Entidade::Entidade()
{
	altura = 0;
	comprimento = 0;
	xEntidade = 0;
	xEntidadeOrigem = 0;
	yEntidade = 0;
	yEntidadeOrigem = 0;
	codigo = 0;
	profundidade = 0;
	tipo = 0;
	conexao = "";
	window = NULL;
	textura = NULL;
}

Entidade::~Entidade()
{

}
//Método de existência dos objetos da fase.
void Entidade::existir(const int viewx, const int viewy)
{
	entidade.setPosition(viewx + xEntidade, viewy + yEntidade);
	texto.setPosition(xEntidade - comprimento / 1.2 + viewx, yEntidade - 15 + viewy);
	desenhar_entidade();
}
//Método de existência dos objetos do menu especificamente.
void Entidade::existir_menu(const float xView, const float yView)
{
	entidade.setPosition(Vector2f(xView - xEntidadeOrigem, yView + yEntidadeOrigem));
	desenhar_entidade();
}

void Entidade::desenhar_entidade()
{
	window->draw(entidade);
	if(conexao != "-1")
		window->draw(texto);
}

void Entidade::setCodigo(const int _codigo)
{
	codigo = _codigo;
}

void Entidade::setTipo(const int _tipo)
{
	tipo = _tipo;
}

void Entidade::setxEntidade(const float _xEntidade)
{
	xEntidade = _xEntidade;
}

void Entidade::setyEntidade(const float _yEntidade)
{
	yEntidade = _yEntidade;
}

void Entidade::setComprimento(const float _comprimento)
{
	comprimento = _comprimento;
}

void Entidade::setAltura(const float _altura)
{
	altura = _altura;
}

void Entidade::setCoordenadas(const float _xEntidade, const float _yEntidade)
{
	xEntidade = _xEntidade;
	yEntidade = _yEntidade;
}

void Entidade::setProfundidade(const int _profundidade)
{
	profundidade = _profundidade;
}

int Entidade::getCodigo() const
{
	return codigo;
}

int Entidade::getTipo() const
{
	return tipo;
}

float Entidade::getxEntidade() const
{
	return entidade.getPosition().x - (comprimento / 2);
}

float Entidade::getyEntidade() const
{
	return entidade.getPosition().y - (altura / 2);
}

float Entidade::getComprimento() const
{
	return comprimento;
}

float Entidade::getAltura() const
{
	return altura;
}

int Entidade::getProfundidade() const
{
	return profundidade;
}

bool Entidade::operator == (const Entidade& _entidade) const
{
	return codigo == _entidade.getCodigo();
}

bool Entidade::operator != (const Entidade& _entidade) const
{
	return !operator==(_entidade);
}

void Entidade::setConexao(const string _conexao)
{
	conexao = _conexao;
	texto.setString(conexao);
}

string Entidade::getConexao()const
{
	return conexao;
}
