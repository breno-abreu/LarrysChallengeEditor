#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class GerenciadorEntidades
{
private:
	RenderWindow* window;
	Texture a;
	Texture b;
	Texture c;
	Texture d;
	Texture e;
	Texture f;
	Texture g;
	Texture h;
	Texture i;
	Texture j;
	Texture k;
	Texture l;
	Texture m;
	Texture n;
	Texture o;
	Texture p;
	Texture q;
	Texture r;
	Texture s;
	Texture t;
	Texture u;
	Texture v;
	Texture w;
	Texture x;
	Texture y;
	Texture z;
	Texture aa;
	Texture ab;
	Texture ac;
	Texture ad;
	Texture ae;
	Texture af;
	Texture ag;
	Texture ah;
	Texture ai;
	Texture aj;
	Texture ak;
	Texture al;
	Texture am;
	Texture an;
	Texture ao;
	Texture ap;
	Texture aq;
	Texture ar;
	Texture as;
	Texture at;
	Texture au;
	Texture av;
	Texture aw;
	Texture ax;
	Texture ay;

	int profundidade[51] = {1, 1, 1, 1, 1, 0, 1, 1, 2, 2, 
							2, 0, 0, 0, 0, 1, 1, 0, 0, 0, 
							0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
							2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 0, 0, 1, 2, 2, 1, 1,
							1};

	Texture* texturas[51] = { &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, 
							  &k, &l, &m, &n, &o, &p, &q, &r, &s, &t, 
							  &u, &v, &w, &x, &y, &z, &aa, &ab, &ac, &ad,
							  &ae, &af, &ag, &ah, &ai, &aj, &ak, &al, &am, &an,
							  &ao, &ap, &aq, &ar, &as, &at, &au, &av, &aw, &ax,
							  &ay };

public:
	GerenciadorEntidades();
	GerenciadorEntidades(RenderWindow* _window);
	~GerenciadorEntidades();
	Entidade* criar_entidade(const int mousex, const int mousey, const int tipo, const int codigo = -1);
	Texture* getTextura(const int n);
};

