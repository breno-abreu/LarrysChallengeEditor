#include "GerenciadorEntidades.h"

GerenciadorEntidades::GerenciadorEntidades()
{
	window = NULL;
}

GerenciadorEntidades::GerenciadorEntidades(RenderWindow* _window)
{
	window = _window;
	a.loadFromFile("Textures/Bau.png");
	b.loadFromFile("Textures/Blue_orb.png");
	c.loadFromFile("Textures/Blue_Wall_up.png");
	d.loadFromFile("Textures/Caixa.png");
	e.loadFromFile("Textures/Caixa_Pesada.png");
	f.loadFromFile("Textures/Chao.png");
	g.loadFromFile("Textures/Chave.png");
	h.loadFromFile("Textures/Coin.png");
	i.loadFromFile("Textures/Coluna_Horizontal.png");
	j.loadFromFile("Textures/Coluna_Vertical.png");
	k.loadFromFile("Textures/Coluna_Vertical2.png");
	l.loadFromFile("Textures/Floor_push_down.png");
	m.loadFromFile("Textures/Floor_push_left.png");
	n.loadFromFile("Textures/Floor_push_right.png");
	o.loadFromFile("Textures/Floor_push_up.png");
	p.loadFromFile("Textures/Green_orb.png");
	q.loadFromFile("Textures/Jogador.png");
	r.loadFromFile("Textures/Parede.png");
	s.loadFromFile("Textures/Passagem.png");
	t.loadFromFile("Textures/Pit00.png");
	u.loadFromFile("Textures/Pit01.png");
	v.loadFromFile("Textures/Pit02.png");
	w.loadFromFile("Textures/Pit03.png");
	x.loadFromFile("Textures/Pit04.png");
	y.loadFromFile("Textures/Pit05.png");
	z.loadFromFile("Textures/Pit06.png");
	aa.loadFromFile("Textures/Pit07.png");
	ab.loadFromFile("Textures/Pit08.png");
	ac.loadFromFile("Textures/Pit09.png");
	ad.loadFromFile("Textures/Porta.png");
	ae.loadFromFile("Textures/Porta_Aberta.png");
	af.loadFromFile("Textures/Porta_Vertical.png");
	ag.loadFromFile("Textures/Rat_down.png");
	ah.loadFromFile("Textures/Rat_left.png");
	ai.loadFromFile("Textures/Rat_right.png");
	aj.loadFromFile("Textures/Rat_up.png");
	ak.loadFromFile("Textures/Red_orb.png");
	al.loadFromFile("Textures/Rock2.png");
	am.loadFromFile("Textures/Shooting_trap_down.png");
	an.loadFromFile("Textures/Shooting_trap_left.png");
	ao.loadFromFile("Textures/Shooting_trap_right.png");
	ap.loadFromFile("Textures/Shooting_trap_up.png");
	aq.loadFromFile("Textures/Skel.png");
	ar.loadFromFile("Textures/Spike_trap.png");
	as.loadFromFile("Textures/Stairs_down.png");
	at.loadFromFile("Textures/Switch_press.png");
	au.loadFromFile("Textures/Topo_Coluna_Direita.png");
	av.loadFromFile("Textures/Topo_Coluna_Esquerda.png");
	aw.loadFromFile("Textures/Switch_blue_orange.png");
	ax.loadFromFile("Textures/Torch.png");
	ay.loadFromFile("Textures/Zombie.png");
}


GerenciadorEntidades::~GerenciadorEntidades()
{
}

Entidade* GerenciadorEntidades::criar_entidade(const int mousex, const int mousey, const int tipo, const int codigo)
{
	int profundidade = BACKGROUND;
	int xTile = 0;
	int yTile = 0;
	int quantidadeLinhas = 1;
	int quantidadeColunas = 1;
	Texture* textura = NULL;
	string nome = "";

	if (tipo == 1) {
		nome = "Jogador";
		profundidade = MIDDLEGROUND;
		quantidadeLinhas = 1;
		quantidadeColunas = 4;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 2){
		nome = "Rato Cima";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 3) {
		nome = "Rato Baixo";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 4) {
		nome = "Rato Direita";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 5) {
		nome = "Rato Esquerda";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 6) {
		nome = "Zumbi";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 7) {
		nome = "Esqueleto";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 4;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 8) {
		nome = "Interruptor";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 9) {
		nome = "Botao";
		profundidade = BACKGROUND;
		quantidadeColunas = 2;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 10) {
		nome = "Bau";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 11) {
		nome = "Caixa Leve";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 12) {
		nome = "Caixa Pesada";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 13) {
		nome = "Chave Prateada";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0; 
		textura = &a;
	}
	else if (tipo == 14) {
		nome = "Chave Dourada";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 15) {
		nome = "Escada";
		profundidade = BACKGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 16) {
		nome = "Tocha";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 17) {
		nome = "Moeda";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 18) {
		nome = "Pocao Vermelha";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 19) {
		nome = "Pocao Azul";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 20) {
		nome = "Atirador Cima";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 21) {
		nome = "Atirador Baixo";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 22) {
		nome = "Atirador Direita";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 23) {
		nome = "Atirador Esquerda";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 24) {
		nome = "Bloco Invisivel";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 1;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 25) {
		nome = "Bloco Armadilha";
		profundidade = MIDDLEGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 26) {
		nome = "Porta Horizontal";
		profundidade = FOREGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 27) {
		nome = "Porta Vertical";
		profundidade = FOREGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 28) {
		nome = "Coluna Horizontal";
		profundidade = FOREGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 29) {
		nome = "Coluna Vertical";
		profundidade = FOREGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 30) {
		nome = "Espinhos";
		profundidade = BACKGROUND;
		quantidadeColunas = 7;
		quantidadeLinhas = 1;
		xTile = 0;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 31) {
		nome = "Chao";
		textura = &t;
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 32) {
		nome = "Parede Cima";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 33) {
		nome = "Parede Baixo";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 34) {
		nome = "Abismo";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 35) {
		nome = "Abismo Cima";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 2;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 36) {
		nome = "Abismo Baixo";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 2;
		yTile = 2;
		textura = &a;
	}
	else if (tipo == 37) {
		nome = "Abismo Direita";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 3;
		yTile = 1;
		textura = &a;
	}
	else if (tipo == 38) {
		nome = "Abismo Esquerda";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 1;
		yTile = 1;
		textura = &a;
	}
	else if (tipo == 39) {
		nome = "Abismo Cotovelo Cima Esquerda";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 40) {
		nome = "Abismo Cotovelo Cima Direita";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 3;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 41) {
		nome = "Abismo Cotovelo Baixo Esquerda";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 1;
		yTile = 2;
		textura = &a;
	}
	else if (tipo == 42) {
		nome = "Abismo Cotovelo Baixo Direita";
		profundidade = BACKGROUND;
		quantidadeColunas = 6;
		quantidadeLinhas = 3;
		xTile = 3;
		yTile = 2;
		textura = &a;
	}
	else if (tipo == 43) {
		nome = "Movimentador Cima";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 44) {
		nome = "Movimentador Baixo";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 45) {
		nome = "Movimentador Esquerda";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
	}
	else if (tipo == 46) {
		nome = "Movimentador Direita";
		profundidade = BACKGROUND;
		quantidadeColunas = 13;
		quantidadeLinhas = 10;
		xTile = 1;
		yTile = 0;
		textura = &a;
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
