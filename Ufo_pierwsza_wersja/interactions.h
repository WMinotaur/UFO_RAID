#pragma once
#include "Missile.h"
#include "Ship.h"
#include <iostream>


class interactions
{
	bool is_interacting(GameElement& element1, GameElement& element2);
	void clash(Ship& ship, Missile& missile);
};



