#include "Ship.h"

Ship::Ship():GameElement() {
    Create(path);
    sprite.setScale(0.15f, 0.15f);
    position.x = (constants::window_width - sprite.getGlobalBounds().width) / 2;
    position.y = constants::window_height - sprite.getGlobalBounds().height;
    sprite.setPosition(position.x, position.y);

}
void Ship::move(float offsetX, float offsetY) {
    if (this->isDetonated) {
        return;
    }
    position.x += offsetX;
    position.y += offsetY;
    if (position.x < 0) {
        position.x = 0;
        offsetX = 0;
    }
    if (position.x + sprite.getGlobalBounds().width > constants::window_width) {
        position.x = constants::window_width - sprite.getGlobalBounds().width;
        offsetY = 0;
    }
    sprite.move(offsetX, offsetY);

}
void Ship::detonate() {
    this->isDetonated = true;
}

void Ship::draw(RenderWindow* okno) {
    if (this->isDetonated) {
        this->Create(this->broken_ufo); 
    }
    GameElement::draw(okno);
}
bool Ship::isShipDetonated() {
    return isDetonated;
}

