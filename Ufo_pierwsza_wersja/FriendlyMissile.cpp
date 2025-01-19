#include "FriendlyMissile.h"

FriendlyMissile::FriendlyMissile(float x,float y) : moving_GameElement() {
	Create(path);
	sprite.setScale(0.1f, 0.1f);
	sprite.setPosition(x, y);
	velocity = { constants::missile_velocity_x , -(constants::missile_velocity_y+constants::background_velocity_y) };
	position.x = x;
	position.y = y;
}


void FriendlyMissile::update() {
	sprite.move(velocity);
	if (sprite.getPosition().y < 0){
		toDelete = true;
	}
}

bool FriendlyMissile::toBeDeleted() {
	return toDelete;
}
