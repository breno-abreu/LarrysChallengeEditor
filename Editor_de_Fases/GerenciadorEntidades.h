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
	Entidade* criar_entidade(int mousex, int mousey, String tipo, int codigo);
	Entidade* criar_caixa(int xEntidade, int yEntidade, int codigo);
	Entidade* criar_personagem();
	Entidade* criar_rato_cima();
	Entidade* criar_rato_baixo();
	Entidade* criar_rato_direita();
	Entidade* criar_rato_esquerda();
	Entidade* criar_zumbi();
	Entidade* criar_esqueleto();
	Entidade* criar_interruptor();
	Entidade* criar_botao();
	Entidade* criar_bau();
	Entidade* criar_caixa_leve();
	Entidade* criar_caixa_pesada();
	Entidade* criar_chave_prateada();
	Entidade* criar_chave_dourada();
	Entidade* criar_escada();
	Entidade* criar_tocha();
	Entidade* criar_moeda();
	Entidade* criar_pocao_vermelha();
	Entidade* criar_pocao_azul();
	Entidade* criar_atirador_cima();
	Entidade* criar_atirador_baixo();
	Entidade* criar_atirador_direita();
	Entidade* criar_atirador_esquerda();
	Entidade* criar_bloco_invisível();
	Entidade* criar_bloco_armadilha();
	Entidade* criar_porta_horizontal();
	Entidade* criar_porta_vertical();
	Entidade* criar_coluna_horizontal();
	Entidade* criar_coluna_vertical();
	Entidade* criar_espinhos();
	Entidade* criar_chao();
	Entidade* criar_parede_cima();
	Entidade* criar_parede_baixo();
	Entidade* criar_abismo();
	Entidade* criar_abismo_cima();
	Entidade* criar_abismo_baixo();
	Entidade* criar_abismo_direita();
	Entidade* criar_abismo_esquerda();
	Entidade* criar_abismo_cotovelo_cima_esquerda();
	Entidade* criar_abismo_cotovelo_cima_direita();
	Entidade* criar_abismo_cotovelo_baixo_esquerda();
	Entidade* criar_abismo_cotovelo_baixo_direita();
	Entidade* criar_movimentador_cima();
	Entidade* criar_movimentador_baixo();
	Entidade* criar_movimentador_direita();
	Entidade* criar_movimentador_esquerda();
};

