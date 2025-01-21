#pragma once
#include <SFML/Graphics.hpp>
#include "GameElement.h"

enum MissileType {
	enemy,
	friendly
};
class  AbstractMissile : public moving_GameElement
{
protected:
	AbstractMissile();
public:
	virtual void update()=0;
	virtual bool toBeDeleted()=0;
	virtual void Delete()=0;
	virtual void detectColision(GameElement* element) = 0;
	virtual void detectBeingShotDown(std::vector<AbstractMissile*>* friendlyMissile) = 0;

public:
	friend AbstractMissile* MissileFactory(MissileType type, float x, float y);
};