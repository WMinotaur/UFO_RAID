#include "Missile.h"


Missile::Missile(float x, float y) : AbstractMissile() {
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
void Missile::Delete() {
	this->toDelete = true;
}
void Missile::detectColision(GameElement* ship) {
	auto shipBox = ship->get_bounding_box();
	auto missile = this->get_bounding_box();
	if (missile.intersects(shipBox))
	{
		ship->detonate();
	}
}
void Missile::detectBeingShotDown(std::vector<AbstractMissile*>* friendlyMissile) {
	for (AbstractMissile* m : *friendlyMissile) {
		auto FriendlyBox = m->get_bounding_box();
		auto missile = this->get_bounding_box();
		if (missile.intersects(FriendlyBox))
		{
			toDelete = true;
			m->Delete();
		}
	}
}
void Missile::detectOutOfScreen(float window_height) {
	if (this->getPosition()->y >= window_height)
		this->toDelete = true;
}


Missile::~Missile() {
	
}
