#include "Background.h"

Background::Background(std::string path,std::string success_path):moving_GameElement(){
    Create(path);
    gameLevelSuccess = success_path;
    background_height = sprite.getGlobalBounds().height;
    sprite.setPosition(0.0f, (constants::window_height -  background_height));
    velocity = { constants::background_velocity_x , constants::background_velocity_y };

    
}




void Background::ShowEndGameScreen() {
    Create(gameover);
    sprite.setPosition(0.0f, 0.0f); 
}

Image* Background::getImage() {
    return &image;
}
void Background::update() {
	sprite.move(velocity);
    distance_traveled += velocity.y;
}

float Background::getDistanceTraveled() {
    return distance_traveled;
}

float Background::getBackgroundHeight() {
    return background_height;
}

void Background::ShowWinGameScreen() {
    Create(gameLevelSuccess);
    sprite.setPosition(0.0f, 0.0f);
    velocity = { 0,0 };
}