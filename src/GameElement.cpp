#include "GameElement.h"
#include <SFML/Graphics.hpp>

/**
 * @brief Default constructor for GameElement.
 */
GameElement::GameElement() {

};

/**
 * @brief Checks if the GameElement is initialized.
 * @return true if initialized, false otherwise.
 */
bool GameElement::if_initialised() {
    return is_initialised;
}

/**
 * @brief Draws the GameElement on the given window.
 * @param okno Pointer to the RenderWindow where the sprite will be drawn.
 */
void GameElement::draw(RenderWindow* okno) {
    okno->draw(sprite);
};

/**
 * @brief Gets the bounding box of the GameElement.
 * @return FloatRect representing the bounding box of the sprite.
 */
FloatRect GameElement::get_bounding_box() const noexcept {
    return sprite.getGlobalBounds();
}

/**
 * @brief Creates the GameElement by loading an image from the given path.
 * @param image_path Path to the image file.
 */
void GameElement::Create(std::string image_path) {
    is_initialised = texture.loadFromFile(image_path);
    if (is_initialised == true) {
        sprite.setTexture(texture);
    }
    this->image = texture.copyToImage();
}

/**
 * @brief Gets the position of the GameElement.
 * @return Pointer to the GameElementPosition.
 */
GameElementPosition* GameElement::getPosition() {
    return &position;
}

/**
 * @brief Default constructor for moving_GameElement.
 */
MovingGameElement::MovingGameElement() {

};

/**
 * @brief Constructor for GameElementPosition with specified coordinates.
 * @param PosX X coordinate.
 * @param PosY Y coordinate.
 */
GameElementPosition::GameElementPosition(float PosX, float PosY) {
    x = PosX;
    y = PosY;
}

/**
 * @brief Default constructor for GameElementPosition.
 */
GameElementPosition::GameElementPosition() {
    x = 0;
    y = 0;
}

/**
 * @brief Detonates the GameElement. Currently does nothing.
 */
void GameElement::detonate() {
    //do nothing
}
