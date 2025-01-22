#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "GameElement.h"
#include <iostream>
#include "Ship.h"
#include "AbstractMissile.h"

class FriendlyMissile : public AbstractMissile
{
private:
	std::string path{ ".\\Textures\\friendlymissile.png" };
	bool toDelete{ false };
	FriendlyMissile(float x, float y);
public:
	void update();
	bool toBeDeleted();
	void Delete();
	void detectColision(GameElement* element);
	void detectBeingShotDown(std::vector<AbstractMissile*>* friendlyMissile);
	friend AbstractMissile* MissileFactory(MissileType type, float x, float y);
};