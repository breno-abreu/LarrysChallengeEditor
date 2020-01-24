#include "Entidade.h"

Entidade::Entidade(RenderWindow* _window, Texture* _textura, float _xEntidade, float _yEntidade, int _codigo, int _profundidade, int _tipo, float proporcao)
{
	codigo = _codigo;
	profundidade = _profundidade;
	direcao = 0;
	xEntidade = _xEntidade;
	yEntidade = _yEntidade;
	existe = true;
	tipo = _tipo;
	cx = 0;
	cy = 0;
	diretorio = "";
	textura = _textura;
	comprimento = textura->getSize().x * proporcao;
	altura = textura->getSize().y * proporcao;
	window = _window;
	entidade.setPosition(xEntidade, yEntidade);
	entidade.setSize(Vector2f(comprimento, altura));
	entidade.setOrigin(Vector2f(comprimento / 2, altura / 2));
	entidade.setTexture(textura);
}

Entidade::Entidade()
{
	codigo = -1;
	xTile = 0;
	yTile = 0;
	profundidade = 0;
	direcao = 0;
	xEntidade = 0;
	yEntidade = 0;
	comprimento = 0;
	altura = 0;
	existe = true;
	tipo = 0;
	diretorio = "NULL";
	window = NULL;
	quantidadeLinhas = 0;
	quantidadeColunas = 0;
}

Entidade::~Entidade()
{

}

void Entidade::existir(int viewx, int viewy)
{
	entidade.setPosition(viewx + xEntidade, viewy + yEntidade);
	desenhar_entidade();
	//cout << xEntidade << endl;
	//cx = entidade.getPosition().x;
	//cy = entidade.getPosition().y;

}

void  Entidade::existir_menu(const float xView, const float yView)
{
	//xEntidade = xView;
	//yEntidade = yView;
	desenhar_entidade();
	
}

void Entidade::desenhar_entidade()
{
	window->draw(entidade);
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
void Entidade::setxTile(const int _xTile)
{
	xTile = _xTile;
}
void Entidade::setyTile(const int _yTile)
{
	yTile = _yTile;
}
void Entidade::setExiste(const bool _existe)
{
	existe = _existe;
}
void Entidade::setProfundidade(const int _profundidade)
{
	profundidade = _profundidade;
}
void Entidade::setDirecao(const int _direcao)
{
	direcao = _direcao;
}
void Entidade::setRenderWindow(RenderWindow* _window)
{
	window = _window;
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
	return xEntidade - (comprimento / 2);
}
float Entidade::getyEntidade() const
{
	return yEntidade - (altura / 2);
}
float Entidade::getComprimento() const
{
	return comprimento;
}
float Entidade::getAltura() const
{
	return altura;
}
int Entidade::getxTile() const
{
	return xTile;
}
int Entidade::getyTile() const
{
	return yTile;
}
bool Entidade::getExiste() const
{
	return existe;
}
int Entidade::getProfundidade() const
{
	return profundidade;
}
int Entidade::getDirecao() const
{
	return direcao;
}

bool Entidade::operator == (const Entidade& _entidade) const
{
	return codigo == _entidade.getCodigo();
}

bool Entidade::operator != (const Entidade& _entidade) const
{
	return !operator==(_entidade);
}

/*bool Entidade::operator < (const Entidade& _entidade) const
{
	return profundidade < _entidade.getProfundidade();
}*/
