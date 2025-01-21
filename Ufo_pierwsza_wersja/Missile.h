#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "GameElement.h"
#include <iostream>
#include "Ship.h"
#include "FriendlyMissile.h"
#include "AbstractMissile.h"

class Missile : public AbstractMissile
{
private:
	std::string path{ ".\\Textures\\bullet3.png" };
	bool toDelete{ false };
	Missile(float x, float y);
public:
	void update();
	bool toBeDeleted();
	void Delete();
	void detectColision(GameElement* ship);
	void detectBeingShotDown(std::vector<AbstractMissile*>* friendlyMissile);
	void detectOutOfScreen(float window_height);
	~Missile();
	friend AbstractMissile* MissileFactory(MissileType type, float x, float y);
};

