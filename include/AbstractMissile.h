#pragma once
#include "GameElement.h"

/**
 * @enum MissileType
 * @brief Enum representing the type of missile.
 */
enum MissileType {
    enemy,    ///< Represents an enemy missile.
    friendly  ///< Represents a friendly missile.
};

/**
 * @class AbstractMissile
 * @brief Abstract base class for all missile types in the game.
 */
class AbstractMissile : public MovingGameElement
{
protected:
    /**
     * @brief Protected constructor to prevent direct instantiation.
     */
    AbstractMissile();

public:
    /**
     * @brief Pure virtual function to update the missile's state.
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual function to check if the missile should be deleted.
     * @return True if the missile should be deleted, false otherwise.
     */
    virtual bool toBeDeleted() = 0;

    /**
     * @brief Pure virtual function to delete the missile.
     */
    virtual void Delete() = 0;

    /**
     * @brief Pure virtual function to detect collision with another game element.
     * @param element Pointer to the game element to check collision with.
     */
    virtual void detectColision(GameElement* element) = 0;

    /**
     * @brief Pure virtual function to detect if the missile has been shot down.
     * @param friendlyMissile Pointer to a vector of friendly missiles.
     */
    virtual void detectBeingShotDown(std::vector<AbstractMissile*>* friendlyMissile) = 0;

public:
    /**
     * @brief Friend function to create a missile using the MissileFactory.
     * @param type The type of missile to create.
     * @param x The x-coordinate of the missile's initial position.
     * @param y The y-coordinate of the missile's initial position.
     * @return Pointer to the created missile.
     */
    friend AbstractMissile* MissileFactory(MissileType type, float x, float y);
};
