#include "Ship.h"

Ship::Ship(Color allowedColor):GameElement() {
    roadColor = allowedColor;
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
    sprite.move(offsetX, offsetY);

}
void Ship::detonate() {
    if (this->isFinished == false) {
        this->isDetonated = true;
    }
      
}

void Ship::draw(RenderWindow* okno) {
    if (this->isDetonated) {
        this->Create(this->broken_ufo); 
    }
    if (this->isFinished) {
        return;
    }
    GameElement::draw(okno);
}
bool Ship::isShipDetonated() {
    return isDetonated;
}

bool Ship::isOnTheRoad(Image* image,float background_position, float background_height) {
    if (this->isDetonated == true) {
        return true;
    }
    Vector2u imgSize = image->getSize();
    float relative_y = background_height - constants::window_height - background_position + position.y;
    if (imgSize.y < relative_y)
        return false;
    if (imgSize.x < position.x)
        return false;
    
    if (relative_y < 0)
    {
        return false; //Cheking if values are correct, so ship is not out of background
    }
    Color color = image->getPixel((int)position.x, (int)relative_y); //Left site of the ship
    Color color2 = image->getPixel((int)(position.x + sprite.getGlobalBounds().width), (int)relative_y); // Right side of the ship
    Color allowedColor = roadColor;
    if (color == allowedColor && color2 == allowedColor )
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool Ship::HasShipFinished(Image* image, float background_position, float background_height) {
    if (isFinished == true) {
        return true;
    }
    Vector2u imgSize = image->getSize();
    float relative_y = background_height - constants::window_height - background_position + position.y;
    if (imgSize.y < relative_y)
        return false;
    if (imgSize.x < position.x)
        return false;

    if (relative_y < 0)
    {
        return false; //Cheking if values are correct, so ship is not out of background
    }
    if (relative_y < 1000)
    {
        this->isFinished = true;
        this->isDetonated = false;

        return true; //ship has reached destination
    }
    Color color = image->getPixel((int)position.x, (int)relative_y); //Left site of the ship
    Color color2 = image->getPixel((int)(position.x + sprite.getGlobalBounds().width), (int)(relative_y)); // Right side of the ship
    Color allowedColor = Color(0, 0, 0);
    if (color == allowedColor && color2 == allowedColor)
    {
        this->isFinished = true;
        this->isDetonated = false;

        return true;
    }
    else
    {
        return false;
    }
    
}

bool Ship::isShipFinished() {
    return isFinished;
}


