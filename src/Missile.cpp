#include "Missile.h"

/**
 * @brief Construct a new Missile object
 * 
 * @param x Initial x position of the missile
 * @param y Initial y position of the missile
 */
Missile::Missile(float x, float y) : AbstractMissile() {
    Create(path);
    sprite.setScale(0.1f, 0.1f);
    sprite.setPosition(x, y);
    velocity = { constants::missile_velocity_x , constants::missile_velocity_y };
    position.x = x;
    position.y = y;
}

/**
 * @brief Update the missile's position
 */
void Missile::update() {
    sprite.move(velocity);
    if (sprite.getPosition().y > constants::window_height) {
        toDelete = true;
    }
}

/**
 * @brief Check if the missile should be deleted
 * 
 * @return true if the missile should be deleted
 * @return false otherwise
 */
bool Missile::toBeDeleted() {
    return toDelete;
}

/**
 * @brief Mark the missile for deletion
 */
void Missile::Delete() {
    this->toDelete = true;
}

/**
 * @brief Detect collision with a ship
 * 
 * @param ship Pointer to the ship object
 */
void Missile::detectColision(GameElement* ship) {
    auto shipBox = ship->get_bounding_box();
    auto missile = this->get_bounding_box();
    if (missile.intersects(shipBox)) {
        ship->detonate();
    }
}

/**
 * @brief Detect if the missile is shot down by friendly missiles
 * 
 * @param friendlyMissile Vector of pointers to friendly missiles
 */
void Missile::detectBeingShotDown(std::vector<AbstractMissile*>* friendlyMissile) {
    for (AbstractMissile* m : *friendlyMissile) {
        auto FriendlyBox = m->get_bounding_box();
        auto missile = this->get_bounding_box();
        if (missile.intersects(FriendlyBox)) {
            toDelete = true;
            m->Delete();
        }
    }
}

/**
 * @brief Detect if the missile is out of the screen
 * 
 * @param window_height Height of the window
 */
void Missile::detectOutOfScreen(float window_height) {
    if (this->getPosition()->y >= window_height)
        this->toDelete = true;
}

/**
 * @brief Destroy the Missile object
 */
Missile::~Missile() {
    
}
