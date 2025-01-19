#include "Missile.h"


Missile::Missile(float x, float y) : moving_GameElement() {
	Create(path);
	sprite.setScale(0.1f, 0.1f);
	sprite.setPosition(x, y);
	velocity = { constants::missile_velocity_x , constants::missile_velocity_y };
	position.x = x;
	position.y = y;


}

void Missile::update() {
	sprite.move(velocity);
	if (sprite.getPosition().y > constants::window_height) {
		toDelete = true;
	}
}
bool Missile::toBeDeleted() {
	return toDelete;
}
void Missile::detectColision(Ship* ship) {
	auto shipBox = ship->get_bounding_box();
	auto missile = this->get_bounding_box();
	if (missile.intersects(shipBox))
	{
		ship->detonate();
	}
}
void Missile::detectBeingShotDown(std::vector<FriendlyMissile*>* friendlyMissile) {
	for (FriendlyMissile* m : *friendlyMissile) {
		auto shipBox = m->get_bounding_box();
		auto missile = this->get_bounding_box();
		if (missile.intersects(shipBox))
		{
			toDelete = true;
		}
	}
}
