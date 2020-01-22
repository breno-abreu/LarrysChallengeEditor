#include "GerenciadorEntidades.h"

GerenciadorEntidades::GerenciadorEntidades()
{
	window = NULL;
}

GerenciadorEntidades::GerenciadorEntidades(RenderWindow* _window)
{
	window = _window;
	t.loadFromFile("Tiny Dungeon Pack/Tilesets/Room/Room_gray.png");
}


GerenciadorEntidades::~GerenciadorEntidades()
{
}

Entidade* GerenciadorEntidades::criar_entidade(const int mousex, const int mousey, const int tipo, const int codigo)
{
	string diretorio = "";
	int profundidade = BACKGROUND;
	int xTile = 0;
	int yTile = 0;
	int quantidadeLinhas = 1;
	int quantidadeColunas = 1;
	Texture* textura = &t;
	string nome = "";


	if (tipo == 1) {
		nome = "Jogador";
		diretorio = "Tiny Dungeon Pack/Character/Char_one/Char_4_sides.png";
		profundidade = MIDDLEGROUND;
		quantidadeLinhas = 1;
		quantidadeColunas = 4;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 2){
		nome = "Rato Cima";
		diretorio = "Tiny Dungeon Pack/Enemies/Rat/Rat_up.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 3) {
		nome = "Rato Baixo";
		diretorio = "Tiny Dungeon Pack/Enemies/Rat/Rat_down.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 4) {
		nome = "Rato Direita";
		diretorio = "Tiny Dungeon Pack/Enemies/Rat/Rat_right.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 5) {
		nome = "Rato Esquerda";
		diretorio = "Tiny Dungeon Pack/Enemies/Rat/Rat_left.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 6) {
		nome = "Zumbi";
		diretorio = "Tiny Dungeon Pack/Enemies/Zombie/Idle/Zombie_idle_down.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 7) {
		nome = "Esqueleto";
		diretorio = "Tiny Dungeon Pack/Enemies/Skeleton/Skel_4Sides.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 4;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 8) {
		nome = "Interruptor";
		diretorio = "Tiny Dungeon Pack/Misc/Switches/Switch_blue_orange.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 9) {
		nome = "Botao";
		diretorio = "Tiny Dungeon Pack/Misc/Switches/Switch_press.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 10) {
		nome = "Bau";
		diretorio = "Tiny Dungeon Pack/Misc/Big_treasure_chest.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 11) {
		nome = "Caixa Leve";
		diretorio = "Tiny Dungeon Pack/Misc/Box.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 12) {
		nome = "Caixa Pesada";
		diretorio = "Tiny Dungeon Pack/Misc/Box_heavy.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 13) {
		nome = "Chave Prateada";
		diretorio = "Tiny Dungeon Pack/Misc/Golden_key.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 14) {
		nome = "Chave Dourada";
		diretorio = "Tiny Dungeon Pack/Misc/Golden_key.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 15) {
		nome = "Escada";
		diretorio = "Tiny Dungeon Pack/Misc/Stairs_down.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 16) {
		nome = "Tocha";
		diretorio = "Tiny Dungeon Pack/Misc/Torch.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 17) {
		nome = "Moeda";
		diretorio = "Tiny Dungeon Pack/Misc/Coin.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 18) {
		nome = "Pocao Vermelha";
		diretorio = "Tiny Dungeon Pack/Misc/Red_orb.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 19) {
		nome = "Pocao Azul";
		diretorio = "Tiny Dungeon Pack/Misc/Blue_orb.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 20) {
		nome = "Atirador Cima";
		diretorio = "Tiny Dungeon Pack/Traps/Shooting_trap/Shooting_trap_up.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 21) {
		nome = "Atirador Baixo";
		diretorio = "Tiny Dungeon Pack/Traps/Shooting_trap/Shooting_trap_down.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 22) {
		nome = "Atirador Direita";
		diretorio = "Tiny Dungeon Pack/Traps/Shooting_trap/Shooting_trap_right.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 23) {
		nome = "Atirador Esquerda";
		diretorio = "Tiny Dungeon Pack/Traps/Shooting_trap/Shooting_trap_left.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 24) {
		nome = "Bloco Invisivel";
		diretorio = "Tiny Dungeon Pack/Misc/Rock.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 25) {
		nome = "Bloco Armadilha";
		diretorio = "Tiny Dungeon Pack/Traps/Color_Wall/Blue_wall_up.png";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 26) {
		nome = "Porta Horizontal";
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = FOREGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 27) {
		nome = "Porta Vertical";
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = FOREGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 28) {
		nome = "Coluna Horizontal";
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = FOREGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 29) {
		nome = "Coluna Vertical";
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = FOREGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 30) {
		nome = "Espinhos";
		diretorio = "Tiny Dungeon Pack/Traps/Spike_trap";
		profundidade = BACKGROUND;
		quantidadeColunas = 7;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
	}
	else if (tipo == 31) {
		nome = "Chao";
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		textura = &t;
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 32) {
		nome = "Parede Cima";
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 33) {
		nome = "Parede Baixo";
		diretorio = "Tiny Dungeon Pack/Tilesets/Room/Room_gray.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 34) {
		nome = "Abismo";
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 35) {
		nome = "Abismo Cima";
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 2;
		yTile = 0;
	}
	else if (tipo == 36) {
		nome = "Abismo Baixo";
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 2;
		yTile = 2;
	}
	else if (tipo == 37) {
		nome = "Abismo Direita";
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 3;
		yTile = 1;
	}
	else if (tipo == 38) {
		nome = "Abismo Esquerda";
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 1;
		yTile = 1;
	}
	else if (tipo == 39) {
		nome = "Abismo Cotovelo Cima Esquerda";
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 40) {
		nome = "Abismo Cotovelo Cima Direita";
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 3;
		yTile = 0;
	}
	else if (tipo == 41) {
		nome = "Abismo Cotovelo Baixo Esquerda";
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 1;
		yTile = 2;
	}
	else if (tipo == 42) {
		nome = "Abismo Cotovelo Baixo Direita";
		diretorio = "Tiny Dungeon Pack/Tilesets/pit.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 3;
		yTile = 2;
	}
	else if (tipo == 43) {
		nome = "Movimentador Cima";
		diretorio = "Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_up.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 44) {
		nome = "Movimentador Baixo";
		diretorio = "Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_down.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 45) {
		nome = "Movimentador Esquerda";
		diretorio = "Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_left.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else if (tipo == 46) {
		nome = "Movimentador Direita";
		diretorio = "Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_right.png";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
	}
	else {
		cout << "Tipo não encontrado" << endl;
		return NULL;
	}
	Entidade* entidade = new Entidade(window, nome, textura, mousex, mousey, codigo, profundidade, xTile, yTile, quantidadeLinhas, quantidadeColunas, tipo);
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
