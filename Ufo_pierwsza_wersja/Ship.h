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
    bool isDetonated{ false };
    std::string broken_ufo{ ".\\Textures\\broken_ufo3.jpg" };
public:
    Ship();
    void move(float offsetX, float offsetY);
    void detonate();
    void draw(RenderWindow* okno);
    bool isShipDetonated();
};

