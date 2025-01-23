#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "GameElement.h"
#include <iostream>
#include "Ship.h"
#include "FriendlyMissile.h"
#include "AbstractMissile.h"

/**
 * @class Missile
 * @brief Represents a missile in the game.
 * 
 * This class is responsible for handling the behavior of a missile, including
 * updating its state, detecting collisions, and determining if it should be deleted.
 */
class Missile : public AbstractMissile
{
private:
    std::string path{ ".\\Textures\\bullet3.png" }; ///< Path to the missile texture.
    bool toDelete{ false }; ///< Flag indicating if the missile should be deleted.
    Missile(float x, float y); ///< Private constructor to create a missile at a given position.

public:
    /**
     * @brief Updates the state of the missile.
     */
    void update();

    /**
     * @brief Checks if the missile should be deleted.
     * @return True if the missile should be deleted, false otherwise.
     */
    bool toBeDeleted();

    /**
     * @brief Marks the missile for deletion.
     */
    void Delete();

    /**
     * @brief Detects collision with a game element.
     * @param ship Pointer to the game element to check collision with.
     */
    void detectColision(GameElement* ship);

    /**
     * @brief Detects if the missile has been shot down by friendly missiles.
     * @param friendlyMissile Pointer to a vector of friendly missiles.
     */
    void detectBeingShotDown(std::vector<AbstractMissile*>* friendlyMissile);

    /**
     * @brief Detects if the missile is out of the screen bounds.
     * @param window_height Height of the game window.
     */
    void detectOutOfScreen(float window_height);

    /**
     * @brief Destructor for the Missile class.
     */
    ~Missile();

    /**
     * @brief Factory function to create a missile of a given type at a specified position.
     * @param type Type of the missile.
     * @param x X-coordinate of the missile's position.
     * @param y Y-coordinate of the missile's position.
     * @return Pointer to the created missile.
     */
    friend AbstractMissile* MissileFactory(MissileType type, float x, float y);
};
