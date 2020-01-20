#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
class Menu
{
private:
	ListaEntidades* listaBackground;
	ListaEntidades* listaBotoes;
	ListaEntidades* listaTextFieldIn;
	ListaEntidades* listaTextFieldOut;

public:
	Menu();
	~Menu();
};

