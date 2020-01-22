#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <cstdio>
#include <filesystem>
#include <SFML/Graphics.hpp>

enum {
	NULO,
	CIMA,
	BAIXO,
	DIREITA,
	ESQUERDA, 
	BACKGROUND,
	MIDDLEGROUND,
	FOREGROUND,
	SALVAR,
	CARREGAR,
	NOVO
};

using namespace std;
using namespace sf;