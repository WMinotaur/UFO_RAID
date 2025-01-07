#include "Missile.h"


Missile::Missile(float x, float y) : moving_GameElement() {
	Create(path);
	sprite.setScale(0.1f, 0.1f);
	sprite.setPosition(x, y);
	velocity = { constants::missile_velocity_x , constants::missile_velocity_y };

}

void Missile::update() {
	sprite.move(velocity);
	std::cerr << "Pozycja pocisku: x = " << sprite.getPosition().x
		<< ", y = " << sprite.getPosition().y << std::endl;
}
