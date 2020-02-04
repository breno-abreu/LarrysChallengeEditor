#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
//Fábrica de objetos da classe Entidade.

class GerenciadorEntidades
{
private:
	//Aqui são criadas as texturas que serão referenciadas pelos objetos de Entidade.
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
	Texture az;
	Texture ba;
	Texture bb;
	Texture bc;

	//A lista de objetos do tipo Entidade será ordenada de acordo com os valores do vetor 'profundidade'...
	//...para que certos objetos fiquem graficamente a frente de outros.
	int profundidade[55] = {3, 3, 3, 3, 3, 0, 3, 3, 3, 3, 
							3, 2, 2, 2, 2, 2, 2, 3, 3, 1, 
							2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
							2, 2, 2, 4, 4, 4, 3, 3, 3, 3,
							3, 3, 3, 3, 3, 3, 3, 2, 2, 3,
							4, 4, 2, 2, 3};

	Texture* texturas[55] = { &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, 
							  &k, &l, &m, &n, &o, &p, &q, &r, &s, &t, 
							  &u, &v, &w, &x, &y, &z, &aa, &ab, &ac, &ad,
							  &ae, &af, &ag, &ah, &ai, &aj, &ak, &al, &am, &an,
							  &ao, &ap, &aq, &ar, &as, &at, &au, &av, &aw, &ax,
							  &ay, &az, &ba, &bb, &bc };

public:
	GerenciadorEntidades();
	GerenciadorEntidades(RenderWindow* _window);
	~GerenciadorEntidades();
	Entidade* criar_entidade(const int mousex, const int mousey, const int tipo, const int codigo = -1, const float proporcao = 3);
	Texture* getTextura(const int n);
};

