#pragma once
#include <SFML/Graphics.hpp>
#include "GameElement.h"
#include "constants.h"
#include <string>
using namespace sf;
class Ship:public GameElement
{
private:
    std::string path{ ".\\Textures\\ufo.png" };
    float pozycja_x{};
    float pozycja_y{};
public:
    Ship();
    void move(float offsetX, float offsetY);
};

