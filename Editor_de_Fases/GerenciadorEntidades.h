#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class GerenciadorEntidades
{
private:
	RenderWindow* window;

public:
	GerenciadorEntidades();
	GerenciadorEntidades(RenderWindow* _window);
	~GerenciadorEntidades();
	Entidade* criar_entidade(int mousex, int mousey, string tipo, int codigo = -1);
	/*Entidade* criar_jogador(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_rato_cima(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_rato_baixo(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_rato_direita(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_rato_esquerda(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_zumbi(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_esqueleto(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_interruptor(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_botao(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_bau(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_caixa_leve(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_caixa_pesada(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_chave_prateada(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_chave_dourada(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_escada(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_tocha(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_moeda(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_pocao_vermelha(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_pocao_azul(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_atirador_cima(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_atirador_baixo(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_atirador_direita(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_atirador_esquerda(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_bloco_invisível(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_bloco_armadilha(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_porta_horizontal(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_porta_vertical(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_coluna_horizontal(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_coluna_vertical(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_espinhos(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_chao(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_parede_cima(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_parede_baixo(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_abismo(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_abismo_cima(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_abismo_baixo(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_abismo_direita(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_abismo_esquerda(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_abismo_cotovelo_cima_esquerda(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_abismo_cotovelo_cima_direita(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_abismo_cotovelo_baixo_esquerda(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_abismo_cotovelo_baixo_direita(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_movimentador_cima(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_movimentador_baixo(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_movimentador_direita(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_movimentador_esquerda(int xEntidade, int yEntidade, int codigo);*/
};

