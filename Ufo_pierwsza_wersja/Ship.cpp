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
    GameElement::draw(okno);
}
bool Ship::isShipDetonated() {
    return isDetonated;
}

bool Ship::isOnTheRoad(Image* image,int background_position, int background_height) {
    if (this->isDetonated == true) {
        return true;
    }
    Vector2u imgSize = image->getSize();
    int relative_y = background_height - constants::window_height - background_position + position.y;
    if (imgSize.y < relative_y)
        return false;
    if (imgSize.x < position.x)
        return false;
    
    if (relative_y < 0)
    {
        return false; //Cheking if values are correct, so ship is not out of background
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

bool Ship::HasShipFinished(Image* image, int background_position, int background_height) {
    if (isFinished == true) {
        return true;
    }
    Vector2u imgSize = image->getSize();
    int relative_y = background_height - constants::window_height - background_position + position.y;
    if (imgSize.y < relative_y)
        return false;
    if (imgSize.x < position.x)
        return false;

    if (relative_y < 0)
    {
        return false; //Cheking if values are correct, so ship is not out of background
    }
    
        Color color = image->getPixel(position.x, relative_y); //Left site of the ship
        Color color2 = image->getPixel(position.x + sprite.getGlobalBounds().width, relative_y); // Right side of the ship
        Color allowedColor = Color(0, 0, 0);
        if (color == allowedColor && color2 == allowedColor)
        {

            this->isFinished = true;
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

