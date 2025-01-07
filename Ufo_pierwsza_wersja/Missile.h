#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "GameElement.h"
#include <iostream>

class Missile : public moving_GameElement
{
private:
	std::string path{ ".\\Textures\\bullet3.png" };
public:
	Missile(float x, float y);
	void update();

};

