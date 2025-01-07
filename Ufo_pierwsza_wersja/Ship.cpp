#include "Ship.h"

Ship::Ship():GameElement() {
    Create(path);
    sprite.setScale(0.15f, 0.15f);
    pozycja_x = (constants::window_width - sprite.getGlobalBounds().width) / 2;
    pozycja_y = constants::window_height - sprite.getGlobalBounds().height;
    sprite.setPosition(pozycja_x, pozycja_y);
}
void Ship::move(float offsetX, float offsetY) {
    pozycja_x += offsetX;
    pozycja_y += offsetY;
    if (pozycja_x < 0) {
        pozycja_x = 0;
        offsetX = 0;
    }
    if (pozycja_x + sprite.getGlobalBounds().width > constants::window_width) {
        pozycja_x = constants::window_width - sprite.getGlobalBounds().width;
        offsetY = 0;
    }
    sprite.move(offsetX, offsetY);

}


