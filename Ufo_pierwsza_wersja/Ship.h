#pragma once
#include <SFML/Graphics.hpp>
#include "GameElement.h"
#include "constants.h"
#include <string>
#include <iostream>
using namespace sf;
class Ship:public GameElement
{
private:
    std::string path{ ".\\Textures\\ufo.png" };
    bool isDetonated{ false };
    std::string broken_ufo{ ".\\Textures\\broken_ufo3.jpg" };
    bool isFinished{ false };
public:
    Ship();
    void move(float offsetX, float offsetY);
    void detonate();
    void draw(RenderWindow* okno);
    bool isShipDetonated();
    bool isOnTheRoad(Image* image, int background_position, int background_height);
    bool HasShipFinished(Image* image, int background_position, int background_height);
    bool isShipFinished();
};