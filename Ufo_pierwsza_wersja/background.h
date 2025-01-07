#pragma once
#include <SFML/Graphics.hpp>
#include "GameElement.h"
using namespace sf;
class Background :public GameElement
{
private:
	std::string path{ ".\\Textures\\background.jpg" };

public:
	Background();

};

