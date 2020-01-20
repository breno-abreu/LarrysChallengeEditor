#pragma once
#include "bibliotecas.h"
#include "Menu.h"
#include "GerenciadorEntidades.h"
class GerenciadorMenus
{
private:
	Menu *menuEntidades;
	Menu *menuSalvar;
	Menu *menuCarregar;
	string estado;

public:
	GerenciadorMenus();
	~GerenciadorMenus();
	void criar_menu_entidades();
	void criar_menu_salvar();
	void criar_menu_carregar();
	void executar_menu_entidades();
	void executar_menu_carregar();
	void executar_menu_salvar();
};

