#include "GameElement.h"
#include <SFML/Graphics.hpp>

GameElement::GameElement() {

};

bool GameElement::if_initialised() {
    return is_initialised;
}
void GameElement::draw(RenderWindow* okno) {
    okno->draw(sprite);
};

FloatRect GameElement::get_bounding_box() const noexcept {
    return sprite.getGlobalBounds();
}

void GameElement::Create(std::string image_path) {
    is_initialised = texture.loadFromFile(image_path);
    if (is_initialised == true) {
        sprite.setTexture(texture);
    }
    this->image = texture.copyToImage();
}

GameElementPosition* GameElement::getPosition() {
    return &position;
}

moving_GameElement::moving_GameElement() {

};
GameElementPosition::GameElementPosition(float PosX, float PosY) {
    
        x = PosX;
        y = PosY;
    
}
GameElementPosition::GameElementPosition() {
    x = 0;
    y = 0;
}