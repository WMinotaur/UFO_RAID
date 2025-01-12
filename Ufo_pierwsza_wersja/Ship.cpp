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

bool Ship::isOnTheRoad(Image* image,int background_position, int background_height) {
    Vector2u imgSize = image->getSize();
    if (imgSize.y < background_height - constants::window_height - background_position + position.y)
        return false;
    if (imgSize.x < position.x)
        return false;
    int relative_y = background_height - constants::window_height - background_position + position.y;
    if (relative_y < 0)
    {
        return false;
    }
    Color color = image->getPixel(position.x, relative_y); //Left site of the ship
    Color color2 = image->getPixel(position.x + sprite.getGlobalBounds().width, relative_y); // Right side of the ship
    Color allowedColor = Color(212, 106, 48);
    if (color == allowedColor && color2 == allowedColor )
    {
        return true;
    }
    else
    {
        return false;
    }

}

