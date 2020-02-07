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
	c.loadFromFile("Textures/Red_orb.png");
	d.loadFromFile("Textures/Green_orb.png");
	e.loadFromFile("Textures/Coin.png");
	f.loadFromFile("Textures/Blue_Wall_up.png");
	g.loadFromFile("Textures/Caixa.png");
	h.loadFromFile("Textures/Caixa_Pesada.png");
	i.loadFromFile("Textures/Chao.png");
	j.loadFromFile("Textures/Chave.png");
	k.loadFromFile("Textures/Coluna_Horizontal.png");
	l.loadFromFile("Textures/Coluna_Vertical_Direita.png");
	m.loadFromFile("Textures/Coluna_Vertical_Esquerda.png");
	n.loadFromFile("Textures/Coluna_Vertical2_Direita.png");
	o.loadFromFile("Textures/Coluna_Vertical2_Esquerda.png");
	p.loadFromFile("Textures/Jogador.png");
	q.loadFromFile("Textures/Skel.png");
	r.loadFromFile("Textures/Zombie.png");
	s.loadFromFile("Textures/Floor_push_down.png");
	t.loadFromFile("Textures/Floor_push_left.png");
	u.loadFromFile("Textures/Floor_push_right.png");
	v.loadFromFile("Textures/Floor_push_up.png");
	w.loadFromFile("Textures/Rat_down.png");
	x.loadFromFile("Textures/Rat_left.png");
	y.loadFromFile("Textures/Rat_right.png");
	z.loadFromFile("Textures/Rat_up.png");
	aa.loadFromFile("Textures/Parede.png");
	ab.loadFromFile("Textures/Passagem.png");
	ac.loadFromFile("Textures/Pit00.png");
	ad.loadFromFile("Textures/Pit01.png");
	ae.loadFromFile("Textures/Pit02.png");
	af.loadFromFile("Textures/Pit03.png");
	ag.loadFromFile("Textures/Pit04.png");
	ah.loadFromFile("Textures/Pit05.png");
	ai.loadFromFile("Textures/Pit06.png");
	aj.loadFromFile("Textures/Pit07.png");
	ak.loadFromFile("Textures/Pit08.png");
	al.loadFromFile("Textures/Pit09.png");
	am.loadFromFile("Textures/Pit10.png");
	an.loadFromFile("Textures/Pit11.png");
	ao.loadFromFile("Textures/Pit12.png");
	ap.loadFromFile("Textures/Pit13.png");
	aq.loadFromFile("Textures/Porta.png");
	ar.loadFromFile("Textures/Porta_Aberta.png");
	as.loadFromFile("Textures/Porta_Cima.png");
	at.loadFromFile("Textures/Porta_Vertical_Direita.png");
	au.loadFromFile("Textures/Porta_Vertical_Esquerda.png");
	av.loadFromFile("Textures/Rock2.png");
	aw.loadFromFile("Textures/Shooting_trap_down.png");
	ax.loadFromFile("Textures/Shooting_trap_left.png");
	ay.loadFromFile("Textures/Shooting_trap_right.png");
	az.loadFromFile("Textures/Shooting_trap_up.png");
	ba.loadFromFile("Textures/Spike_trap.png");
	bb.loadFromFile("Textures/Stairs_down.png");
	bc.loadFromFile("Textures/Stairs_up.png");
	bd.loadFromFile("Textures/Topo_Coluna_Direita.png");
	be.loadFromFile("Textures/Topo_Coluna_Esquerda.png");
	bf.loadFromFile("Textures/Switch_blue_orange.png");
	bg.loadFromFile("Textures/Torch.png");
	bh.loadFromFile("Textures/Switch_press.png");
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