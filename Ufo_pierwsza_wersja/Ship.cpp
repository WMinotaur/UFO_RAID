#include "Ship.h"

/**
 * @brief Construct a new Ship object
 * 
 * @param allowedColor The color of the road ship is allowed to be on
 */
Ship::Ship(Color allowedColor):GameElement() {
    roadColor = allowedColor;
    Create(path);
    sprite.setScale(0.15f, 0.15f);
    position.x = (constants::window_width - sprite.getGlobalBounds().width) / 2;
    position.y = constants::window_height - sprite.getGlobalBounds().height;
    sprite.setPosition(position.x, position.y);
}

/**
 * @brief Move the ship by the given offsets
 * 
 * @param offsetX The offset in the x direction
 * @param offsetY The offset in the y direction
 */
void Ship::move(float offsetX, float offsetY) {
    if (this->isDetonated) {
        return;
    }
    position.x += offsetX;
    position.y += offsetY;
    sprite.move(offsetX, offsetY);
}

/**
 * @brief Detonate the ship
 */
void Ship::detonate() {
    if (this->isFinished == false) {
        this->isDetonated = true;
    }
}

/**
 * @brief Draw the ship on the given window
 * 
 * @param okno The window to draw the ship on
 */
void Ship::draw(RenderWindow* okno) {
    if (this->isDetonated) {
        this->Create(this->broken_ufo); 
    }
    if (this->isFinished) {
        return;
    }
    GameElement::draw(okno);
}

/**
 * @brief Check if the ship is detonated
 * 
 * @return true If the ship is detonated
 * @return false If the ship is not detonated
 */
bool Ship::isShipDetonated() {
    return isDetonated;
}

/**
 * @brief Check if the ship is on the road
 * 
 * @param image The image of the background
 * @param background_position The position of the background
 * @param background_height The height of the background
 * @return true If the ship is on the road
 * @return false If the ship is not on the road
 */
bool Ship::isOnTheRoad(Image* image, float background_position, float background_height) {
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

/**
 * @brief Check if the ship has finished its journey
 * 
 * @param image The image of the background
 * @param background_position The position of the background
 * @param background_height The height of the background
 * @return true If the ship has finished its journey
 * @return false If the ship has not finished its journey
 */
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

/**
 * @brief Check if the ship has finished its journey
 * 
 * @return true If the ship has finished its journey
 * @return false If the ship has not finished its journey
 */
bool Ship::isShipFinished() {
    return isFinished;
}
