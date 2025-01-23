#include "Background.h"

/**
 * @brief Construct a new Background object
 * 
 * @param path Path to the background image
 * @param success_path Path to the success screen image
 */
Background::Background(std::string path,std::string success_path):MovingGameElement(){
    Create(path);
    gameLevelSuccess = success_path;
    background_height = sprite.getGlobalBounds().height;
    sprite.setPosition(0.0f, (constants::window_height -  background_height));
    velocity = { constants::background_velocity_x , constants::background_velocity_y };
}

/**
 * @brief Show the end game screen
 */
void Background::ShowEndGameScreen() {
    Create(gameover);
    sprite.setPosition(0.0f, 0.0f); 
}

/**
 * @brief Get the Image object
 * 
 * @return Image* Pointer to the image object
 */
Image* Background::getImage() {
    return &image;
}

/**
 * @brief Update the background position
 */
void Background::update() {
    sprite.move(velocity);
    distance_traveled += velocity.y;
}

/**
 * @brief Get the distance traveled by the background
 * 
 * @return float Distance traveled
 */
float Background::getDistanceTraveled() {
    return distance_traveled;
}

/**
 * @brief Get the height of the background
 * 
 * @return float Background height
 */
float Background::getBackgroundHeight() {
    return background_height;
}

/**
 * @brief Show the win game screen
 */
void Background::ShowWinGameScreen() {
    Create(gameLevelSuccess);
    sprite.setPosition(0.0f, 0.0f);
    velocity = { 0,0 };
}
