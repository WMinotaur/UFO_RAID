#include "FriendlyMissile.h"

/**
 * @brief Construct a new Friendly Missile object
 * 
 * @param x Initial x position of the missile
 * @param y Initial y position of the missile
 */
FriendlyMissile::FriendlyMissile(float x,float y) : AbstractMissile() {
    Create(path);
    sprite.setScale(0.1f, 0.1f);
    sprite.setPosition(x, y);
    velocity = { constants::missile_velocity_x , -(constants::missile_velocity_y+constants::background_velocity_y- constants::friendlymissile_velocity_y) };
    position.x = x;
    position.y = y;
}

/**
 * @brief Update the position of the missile
 * 
 */
void FriendlyMissile::update() {
    sprite.move(velocity);
    if (sprite.getPosition().y < 0){
        toDelete = true;
    }
}

/**
 * @brief Mark the missile for deletion
 * 
 */
void FriendlyMissile::Delete() {
    toDelete = true;
}

/**
 * @brief Check if the missile is marked for deletion
 * 
 * @return true if the missile is marked for deletion
 * @return false if the missile is not marked for deletion
 */
bool FriendlyMissile::toBeDeleted() {
    return toDelete;
}

/**
 * @brief Detect collision with another game element
 * 
 * @param element The game element to check collision with
 */
void FriendlyMissile::detectColision(GameElement* element)
{
    // do nothing
}

/**
 * @brief Detect if the missile is being shot down
 * 
 * @param friendlyMissile A vector of friendly missiles
 */
void FriendlyMissile::detectBeingShotDown(std::vector<AbstractMissile*>* friendlyMissile)
{
    // do nothing
}
