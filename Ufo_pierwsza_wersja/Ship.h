#pragma once
#include <SFML/Graphics.hpp>
#include "GameElement.h"
#include "constants.h"
#include <string>
#include <iostream>
using namespace sf;

/**
 * @class Ship
 * @brief Represents a ship in the game, derived from GameElement.
 */
class Ship:public GameElement
{
private:
    std::string path{ ".\\Textures\\ufo.png" }; ///< Path to the ship texture.
    bool isDetonated{ false }; ///< Flag indicating if the ship is detonated.
    std::string broken_ufo{ ".\\Textures\\broken_ufo3.png" }; ///< Path to the broken ship texture.
    bool isFinished{ false }; ///< Flag indicating if the ship has finished its task.
    Color roadColor{}; ///< Color of the road.

public:
    /**
     * @brief Constructor for Ship.
     * @param roadColor Color of the road.
     */
    Ship(Color roadColor);

    /**
     * @brief Moves the ship by the given offsets.
     * @param offsetX Offset in the X direction.
     * @param offsetY Offset in the Y direction.
     */
    void move(float offsetX, float offsetY);

    /**
     * @brief Detonates the ship.
     */
    void detonate();

    /**
     * @brief Draws the ship on the given window.
     * @param okno Pointer to the render window.
     */
    void draw(RenderWindow* okno);

    /**
     * @brief Checks if the ship is detonated.
     * @return True if the ship is detonated, false otherwise.
     */
    bool isShipDetonated();

    /**
     * @brief Checks if the ship is on the road.
     * @param image Pointer to the image.
     * @param background_position Position of the background.
     * @param background_height Height of the background.
     * @return True if the ship is on the road, false otherwise.
     */
    bool isOnTheRoad(Image* image, float background_position, float background_height);

    /**
     * @brief Checks if the ship has finished its task.
     * @param image Pointer to the image.
     * @param background_position Position of the background.
     * @param background_height Height of the background.
     * @return True if the ship has finished its task, false otherwise.
     */
    bool HasShipFinished(Image* image, float background_position, float background_height);

    /**
     * @brief Checks if the ship has finished.
     * @return True if the ship has finished, false otherwise.
     */
    bool isShipFinished();
};
