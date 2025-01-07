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

void GameElement::Create(std::string image_path) {
    is_initialised = texture.loadFromFile(image_path);
    if (is_initialised == true) {
        sprite.setTexture(texture);
    }
}
