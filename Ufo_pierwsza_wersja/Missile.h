#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "GameElement.h"
#include <iostream>
#include "Ship.h"

class Missile : public moving_GameElement
{
private:
	std::string path{ ".\\Textures\\bullet3.png" };
	bool toDelete{ false };
public:
	Missile(float x, float y);
	void update();
	bool toBeDeleted();
	void detectColision(Ship* ship);


};

