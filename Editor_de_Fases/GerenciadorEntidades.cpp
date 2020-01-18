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

Entidade* GerenciadorEntidades::criar_entidade(int mousex, int mousey, string tipo, int codigo)
{
	if (tipo == "Jogador") {
		return criar_jogador(mousex, mousey, codigo);
	}
	else if (tipo == "Rato Cima"){
		return criar_rato_cima(mousex, mousey, codigo);
	}
	return NULL;
}

Entidade* GerenciadorEntidades::criar_jogador(int xEntidade, int yEntidade, int codigo)
{
	Entidade* jogador = new Entidade(window, "Jogador", "Tiny Dungeon Pack/Character/Char_one/Char_4_sides.png", (float)xEntidade, (float)yEntidade, codigo, MIDDLEGROUND, NULO);
	return jogador;
}
Entidade* GerenciadorEntidades::criar_rato_cima(int xEntidade, int yEntidade, int codigo)
{
	Entidade* rato = new Entidade(window, "Rato Cima", "Tiny Dungeon Pack/Enemies/Rat/Rat_up.png", (float)xEntidade, (float)yEntidade, codigo, MIDDLEGROUND, CIMA);
	return rato;
}
/*Entidade* GerenciadorEntidades::criar_rato_baixo(int xEntidade, int yEntidade, int codigo)
{
	Entidade* rato = new Entidade(window, "Rato Baixo", "Tiny Dungeon Pack/Enemies/Rat/Rat_down.png", (float)xEntidade, (float)yEntidade, codigo, MIDDLEGROUND, BAIXO);
	return rato;
}
Entidade* GerenciadorEntidades::criar_rato_direita(int xEntidade, int yEntidade, int codigo)
{
	Entidade* rato = new Entidade(window, "Rato Direita", "Tiny Dungeon Pack/Enemies/Rat/Rat_right.png", (float)xEntidade, (float)yEntidade, codigo, MIDDLEGROUND, DIREITA);
	return rato;
}
Entidade* GerenciadorEntidades::criar_rato_esquerda(int xEntidade, int yEntidade, int codigo)
{
	Entidade* rato = new Entidade(window, "Rato Cima", "Tiny Dungeon Pack/Enemies/Rat/Rat_left.png", (float)xEntidade, (float)yEntidade, codigo, MIDDLEGROUND, ESQUERDA);
	return rato;
}
Entidade* GerenciadorEntidades::criar_zumbi(int xEntidade, int yEntidade, int codigo)
{
	Entidade* zumbi = new Entidade(window, "Zumbi", "Tiny Dungeon Pack/Enemies/Zombie/Idle/Zombie_idle_down.png", (float)xEntidade, (float)yEntidade, codigo, MIDDLEGROUND, NULO);
	return zumbi;
}
Entidade* GerenciadorEntidades::criar_esqueleto(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_interruptor(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_botao(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_bau(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_caixa_leve(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_caixa_pesada(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_chave_prateada(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_chave_dourada(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_escada(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_tocha(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_moeda(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_pocao_vermelha(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_pocao_azul(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_atirador_cima(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_atirador_baixo(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_atirador_direita(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_atirador_esquerda(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_bloco_invisível(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_bloco_armadilha(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_porta_horizontal(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_porta_vertical(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_coluna_horizontal(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_coluna_vertical(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_espinhos(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_chao(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_parede_cima(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_parede_baixo(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_abismo(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_abismo_cima(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_abismo_baixo(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_abismo_direita(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_abismo_esquerda(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_abismo_cotovelo_cima_esquerda(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_abismo_cotovelo_cima_direita(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_abismo_cotovelo_baixo_esquerda(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_abismo_cotovelo_baixo_direita(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_movimentador_cima(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_movimentador_baixo(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_movimentador_direita(int xEntidade, int yEntidade, int codigo)
{

}
Entidade* GerenciadorEntidades::criar_movimentador_esquerda(int xEntidade, int yEntidade, int codigo)
{

}*/
