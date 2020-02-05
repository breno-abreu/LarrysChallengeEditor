#include "GerenciadorEntidades.h"

GerenciadorEntidades::GerenciadorEntidades()
{
	window = NULL;
}

GerenciadorEntidades::GerenciadorEntidades(RenderWindow* _window)
{
	window = _window;
	//As texturas são carregadas com o conteúdo dos arquivos de imagem .PNG contidos na pasta 'Textures'.
	a.loadFromFile("Textures/Bau.png");
	b.loadFromFile("Textures/Blue_orb.png");
	c.loadFromFile("Textures/Blue_Wall_up.png");
	d.loadFromFile("Textures/Caixa.png");
	e.loadFromFile("Textures/Caixa_Pesada.png");
	f.loadFromFile("Textures/Chao.png");
	g.loadFromFile("Textures/Chave.png");
	h.loadFromFile("Textures/Coin.png");
	i.loadFromFile("Textures/Coluna_Horizontal.png");
	j.loadFromFile("Textures/Coluna_Vertical_Direita.png");
	k.loadFromFile("Textures/Coluna_Vertical_Esquerda.png");
	l.loadFromFile("Textures/Coluna_Vertical2_Direita.png");
	m.loadFromFile("Textures/Coluna_Vertical2_Esquerda.png");
	n.loadFromFile("Textures/Floor_push_down.png");
	o.loadFromFile("Textures/Floor_push_left.png");
	p.loadFromFile("Textures/Floor_push_right.png");
	q.loadFromFile("Textures/Floor_push_up.png");
	r.loadFromFile("Textures/Green_orb.png");
	s.loadFromFile("Textures/Jogador.png");
	t.loadFromFile("Textures/Parede.png");
	u.loadFromFile("Textures/Passagem.png");
	v.loadFromFile("Textures/Pit00.png");
	w.loadFromFile("Textures/Pit01.png");
	x.loadFromFile("Textures/Pit02.png");
	y.loadFromFile("Textures/Pit03.png");
	z.loadFromFile("Textures/Pit04.png");
	aa.loadFromFile("Textures/Pit05.png");
	ab.loadFromFile("Textures/Pit06.png");
	ac.loadFromFile("Textures/Pit07.png");
	ad.loadFromFile("Textures/Pit08.png");
	ae.loadFromFile("Textures/Pit09.png");
	af.loadFromFile("Textures/Porta.png");
	ag.loadFromFile("Textures/Porta_Aberta.png");
	ah.loadFromFile("Textures/Porta_Cima.png");
	ai.loadFromFile("Textures/Porta_Vertical_Direita.png");
	aj.loadFromFile("Textures/Porta_Vertical_Esquerda.png");
	ak.loadFromFile("Textures/Rat_down.png");
	al.loadFromFile("Textures/Rat_left.png");
	am.loadFromFile("Textures/Rat_right.png");
	an.loadFromFile("Textures/Rat_up.png");
	ao.loadFromFile("Textures/Red_orb.png");
	ap.loadFromFile("Textures/Rock2.png");
	aq.loadFromFile("Textures/Shooting_trap_down.png");
	ar.loadFromFile("Textures/Shooting_trap_left.png");
	as.loadFromFile("Textures/Shooting_trap_right.png");
	at.loadFromFile("Textures/Shooting_trap_up.png");
	au.loadFromFile("Textures/Skel.png");
	av.loadFromFile("Textures/Spike_trap.png");
	aw.loadFromFile("Textures/Stairs_down.png");
	ax.loadFromFile("Textures/Switch_press.png");
	ay.loadFromFile("Textures/Topo_Coluna_Direita.png");
	az.loadFromFile("Textures/Topo_Coluna_Esquerda.png");
	ba.loadFromFile("Textures/Switch_blue_orange.png");
	bb.loadFromFile("Textures/Torch.png");
	bc.loadFromFile("Textures/Zombie.png");
}


GerenciadorEntidades::~GerenciadorEntidades()
{

}

Texture* GerenciadorEntidades::getTextura(const int n)
{
	return texturas[n];
}
//A fábrica retorna um objeto da classe Entidade com as especificações necessárias.
Entidade* GerenciadorEntidades::criar_entidade(const int mousex, const int mousey, const int tipo, const int codigo, const float proporcao)
{
	Entidade* entidade = new Entidade(window, texturas[tipo], mousex, mousey, codigo, profundidade[tipo], tipo, proporcao);
	return entidade;
}