#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "GameElement.h"
#include <iostream>
#include "Ship.h"
#include "AbstractMissile.h"

/**
 * @class FriendlyMissile
 * @brief Represents a missile fired by the player's ship.
 * 
 * This class inherits from AbstractMissile and provides specific implementation
 * for a friendly missile, including its update logic, collision detection, and
 * deletion status.
 */
class FriendlyMissile : public AbstractMissile
{
private:
    std::string path{ ".\\Textures\\friendlymissile.png" }; ///< Path to the texture of the friendly missile.
    bool toDelete{ false }; ///< Flag indicating whether the missile should be deleted.
    
    /**
     * @brief Constructs a FriendlyMissile at the given coordinates.
     * 
     * @param x The x-coordinate of the missile's initial position.
     * @param y The y-coordinate of the missile's initial position.
     */
    FriendlyMissile(float x, float y);

public:
    /**
     * @brief Updates the missile's state.
     * 
     * This function is called every frame to update the missile's position and check for collisions.
     */
    void update() override;

    /**
     * @brief Checks if the missile should be deleted.
     * 
     * @return true if the missile should be deleted, false otherwise.
     */
    bool toBeDeleted() override;

    /**
     * @brief Marks the missile for deletion.
     */
    void Delete() override;

    /**
     * @brief Detects collision with another game element.
     * 
     * @param element Pointer to the game element to check collision with.
     */
    void detectColision(GameElement* element) override;

    /**
     * @brief Detects if the missile has been shot down.
     * 
     * @param friendlyMissile Pointer to a vector of friendly missiles to check against.
     */
    void detectBeingShotDown(std::vector<AbstractMissile*>* friendlyMissile) override;

    /**
     * @brief Factory function to create a missile of the specified type.
     * 
     * @param type The type of missile to create.
     * @param x The x-coordinate of the missile's initial position.
     * @param y The y-coordinate of the missile's initial position.
     * @return Pointer to the created missile.
     */
    friend AbstractMissile* MissileFactory(MissileType type, float x, float y);
};
