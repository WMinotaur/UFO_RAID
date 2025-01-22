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
    Color roadColor{};
public:
    Ship(Color roadColor);
    void move(float offsetX, float offsetY);
    void detonate();
    void draw(RenderWindow* okno);
    bool isShipDetonated();
    bool isOnTheRoad(Image* image, float background_position, float background_height);
    bool HasShipFinished(Image* image, float background_position, float background_height);
    bool isShipFinished();
};