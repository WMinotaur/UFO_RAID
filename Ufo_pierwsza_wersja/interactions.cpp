#include "interactions.h"

bool interactions::is_interacting(GameElement& element1, GameElement& element2) {
    auto box1 = element1.get_bounding_box();
    auto box2 = element2.get_bounding_box();
    return box1.intersects(box2);
}


void interactions::clash(Ship& ship, Missile& missile) {
    if (is_interacting(ship, missile)) {
        std::cout << "Kolizja wykryta pomiêdzy statkiem a pociskiem!" << std::endl;

    }
}







