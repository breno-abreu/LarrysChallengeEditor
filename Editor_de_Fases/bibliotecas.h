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
	FOREGROUND
};

using namespace std;
using namespace sf;
namespace fs = std::experimental::filesystem;
using namespace fs;