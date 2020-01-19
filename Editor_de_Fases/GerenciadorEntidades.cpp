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
	string diretorio = "";
	int profundidade = 0;
	int xTile = 0;
	int yTile = 0;
	int quantidadeLinhas = 1;
	int quantidadeColunas = 1;

	if (tipo == "Jogador") {
		diretorio = "Tiny Dungeon Pack/Character/Char_one/Char_4_sides.png";
		profundidade = MIDDLEGROUND;
		quantidadeLinhas = 1;
		quantidadeColunas = 4;
	}
	else if (tipo == "Rato Cima"){
		diretorio = "Tiny Dungeon Pack/Enemies/Rat/Rat_up.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Rato Baixo") {
		diretorio = "Tiny Dungeon Pack/Enemies/Rat/Rat_down.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Rato Direita") {
		diretorio = "Tiny Dungeon Pack/Enemies/Rat/Rat_right.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Rato Esquerda") {
		diretorio = "Tiny Dungeon Pack/Enemies/Rat/Rat_left.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Zumbi") {
		diretorio = "Tiny Dungeon Pack/Enemies/Zombie/Idle/Zombie_idle_down.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Esqueleto") {
		diretorio = "Tiny Dungeon Pack/Enemies/Skeleton/Skel_4Sides.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Interruptor") {
		diretorio = "Tiny Dungeon Pack/Misc/Switches/Switch_blue_orange.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Botao") {
		diretorio = "Tiny Dungeon Pack/Misc/Switches/Switch_press.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Bau") {
		diretorio = "Tiny Dungeon Pack/Misc/Big_treasure_chest.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Caixa Leve") {
		diretorio = "Tiny Dungeon Pack/Misc/Box.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Caixa Pesada") {
		diretorio = "Tiny Dungeon Pack/Misc/Box_heavy.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Chave Prateada") {
		diretorio = "Tiny Dungeon Pack/Misc/Golden_key.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Chave Dourada") {
		diretorio = "Tiny Dungeon Pack/Misc/Golden_key.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Escada") {
		diretorio = "Tiny Dungeon Pack/Misc/Stairs_down.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Tocha") {
		diretorio = "Tiny Dungeon Pack/Misc/Torch.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Moeda") {
		diretorio = "Tiny Dungeon Pack/Misc/Coin.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Pocao Vermelha") {
		diretorio = "Tiny Dungeon Pack/Misc/Red_orb.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Pocao Azul") {
		diretorio = "Tiny Dungeon Pack/Misc/Blue_orb.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Atirador Cima") {
		diretorio = "Tiny Dungeon Pack/Traps/Shooting_trap/Shooting_trap_up.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Atirador Baixo") {
		diretorio = "Tiny Dungeon Pack/Traps/Shooting_trap/Shooting_trap_down.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Atirador Direita") {
		diretorio = "Tiny Dungeon Pack/Traps/Shooting_trap/Shooting_trap_right.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Atirador Esquerda") {
		diretorio = "Tiny Dungeon Pack/Traps/Shooting_trap/Shooting_trap_left.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Bloco Invisivel") {
		diretorio = "Tiny Dungeon Pack/Misc/Rock.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Bloco Armadilha") {
		diretorio = "Tiny Dungeon Pack/Traps/Color_Wall/Blue_wall_up.png";
		profundidade = MIDDLEGROUND;
	}
	else if (tipo == "Porta Horizontal") {
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = FOREGROUND;
	}
	else if (tipo == "Porta Vertical") {
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = FOREGROUND;
	}
	else if (tipo == "Coluna Horizontal") {
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = FOREGROUND;
	}
	else if (tipo == "Coluna Vertical") {
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = FOREGROUND;
	}
	else if (tipo == "Espinhos") {
		diretorio = "Tiny Dungeon Pack/Traps/Spike_trap";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Chao") {
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == "Parede Cima") {
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Parede Baixo") {
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Abismo") {
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Abismo Cima") {
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Abismo Baixo") {
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Abismo Direita") {
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Abismo Esquerda") {
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Abismo Cotovelo Cima Esquerda") {
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Abismo Cotovelo Cima Direita") {
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Abismo Cotovelo Baixo Esquerda") {
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Abismo Cotovelo Baixo Direita") {
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Movimentador Cima") {
		diretorio = "Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_up.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Movimentador Baixo") {
		diretorio = "Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_down.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Movimentador Esquerda") {
		diretorio = "Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_left.png";
		profundidade = BACKGROUND;
	}
	else if (tipo == "Movimentador Direita") {
		diretorio = "Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_right.png";
		profundidade = BACKGROUND;
	}
	else {
		cout << "Tipo não encontrado" << endl;
	}
	Entidade* entidade = new Entidade(window, tipo, diretorio, mousex, mousey, codigo, profundidade, xTile, yTile, quantidadeLinhas, quantidadeColunas);
	return entidade;
}

/*Entidade* GerenciadorEntidades::criar_jogador(int xEntidade, int yEntidade, int codigo)
{
	Entidade* jogador = new Entidade(window, "Jogador", "Tiny Dungeon Pack/Character/Char_one/Char_4_sides.png", (float)xEntidade, (float)yEntidade, codigo, MIDDLEGROUND, NULO);
	return jogador;
}
Entidade* GerenciadorEntidades::criar_rato_cima(int xEntidade, int yEntidade, int codigo)
{
	Entidade* rato = new Entidade(window, "Rato Cima", "Tiny Dungeon Pack/Enemies/Rat/Rat_up.png", (float)xEntidade, (float)yEntidade, codigo, MIDDLEGROUND, CIMA);
	return rato;
}
Entidade* GerenciadorEntidades::criar_rato_baixo(int xEntidade, int yEntidade, int codigo)
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
