#include "GerenciadorEntidades.h"

GerenciadorEntidades::GerenciadorEntidades()
{
	window = NULL;
}

GerenciadorEntidades::GerenciadorEntidades(RenderWindow* _window)
{
	window = _window;
}


GerenciadorEntidades::~GerenciadorEntidades()
{
}

Entidade* GerenciadorEntidades::criar_entidade(int mousex, int mousey, String tipo, int _codigo)
{
	int xEntidade = mousex;
	int yEntidade = mousey;
	int codigo = _codigo;

	if (tipo == "Caixa") {
		return criar_caixa(mousex, mousey, codigo);
	}
	return NULL;
}
Entidade* GerenciadorEntidades::criar_caixa(int xEntidade, int yEntidade, int codigo)
{
	Entidade* caixa = new Entidade(window, "Caixa", "Box.png", (float)xEntidade, (float)yEntidade, codigo, BACKGROUND, NULO);
	return caixa;
}

Entidade* GerenciadorEntidades::criar_personagem()
{

}
Entidade* GerenciadorEntidades::criar_rato_cima()
{

}
Entidade* GerenciadorEntidades::criar_rato_baixo()
{

}
Entidade* GerenciadorEntidades::criar_rato_direita()
{

}
Entidade* GerenciadorEntidades::criar_rato_esquerda()
{

}
Entidade* GerenciadorEntidades::criar_zumbi()
{

}
Entidade* GerenciadorEntidades::criar_esqueleto()
{

}
Entidade* GerenciadorEntidades::criar_interruptor()
{

}
Entidade* GerenciadorEntidades::criar_botao()
{

}
Entidade* GerenciadorEntidades::criar_bau()
{

}
Entidade* GerenciadorEntidades::criar_caixa_leve()
{

}
Entidade* GerenciadorEntidades::criar_caixa_pesada()
{

}
Entidade* GerenciadorEntidades::criar_chave_prateada()
{

}
Entidade* GerenciadorEntidades::criar_chave_dourada()
{

}
Entidade* GerenciadorEntidades::criar_escada()
{

}
Entidade* GerenciadorEntidades::criar_tocha()
{

}
Entidade* GerenciadorEntidades::criar_moeda()
{

}
Entidade* GerenciadorEntidades::criar_pocao_vermelha()
{

}
Entidade* GerenciadorEntidades::criar_pocao_azul()
{

}
Entidade* GerenciadorEntidades::criar_atirador_cima()
{

}
Entidade* GerenciadorEntidades::criar_atirador_baixo()
{

}
Entidade* GerenciadorEntidades::criar_atirador_direita()
{

}
Entidade* GerenciadorEntidades::criar_atirador_esquerda()
{

}
Entidade* GerenciadorEntidades::criar_bloco_invisível()
{

}
Entidade* GerenciadorEntidades::criar_bloco_armadilha()
{

}
Entidade* GerenciadorEntidades::criar_porta_horizontal()
{

}
Entidade* GerenciadorEntidades::criar_porta_vertical()
{

}
Entidade* GerenciadorEntidades::criar_coluna_horizontal()
{

}
Entidade* GerenciadorEntidades::criar_coluna_vertical()
{

}
Entidade* GerenciadorEntidades::criar_espinhos()
{

}
Entidade* GerenciadorEntidades::criar_chao()
{

}
Entidade* GerenciadorEntidades::criar_parede_cima()
{

}
Entidade* GerenciadorEntidades::criar_parede_baixo()
{

}
Entidade* GerenciadorEntidades::criar_abismo()
{

}
Entidade* GerenciadorEntidades::criar_abismo_cima()
{

}
Entidade* GerenciadorEntidades::criar_abismo_baixo()
{

}
Entidade* GerenciadorEntidades::criar_abismo_direita()
{

}
Entidade* GerenciadorEntidades::criar_abismo_esquerda()
{

}
Entidade* GerenciadorEntidades::criar_abismo_cotovelo_cima_esquerda()
{

}
Entidade* GerenciadorEntidades::criar_abismo_cotovelo_cima_direita()
{

}
Entidade* GerenciadorEntidades::criar_abismo_cotovelo_baixo_esquerda()
{

}
Entidade* GerenciadorEntidades::criar_abismo_cotovelo_baixo_direita()
{

}
Entidade* GerenciadorEntidades::criar_movimentador_cima()
{

}
Entidade* GerenciadorEntidades::criar_movimentador_baixo()
{

}
Entidade* GerenciadorEntidades::criar_movimentador_direita()
{

}
Entidade* GerenciadorEntidades::criar_movimentador_esquerda()
{

}
