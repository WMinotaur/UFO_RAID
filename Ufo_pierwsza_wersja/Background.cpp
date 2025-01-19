#include "Background.h"

Background::Background(std::string path):moving_GameElement(){
    Create(path);
    
    background_height = sprite.getGlobalBounds().height;
    sprite.setPosition(0.0f, (constants::window_height -  background_height));
    velocity = { constants::background_velocity_x , constants::background_velocity_y };
    
}
std::string Background::Level1() {
    return level1_path;
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

int Background::getDistanceTraveled() {
    return distance_traveled;
}

int Background::getBackgroundHeight() {
    return background_height;
}

void Background::ShowWinGameScreen() {
    Create(gameWon);
    sprite.setPosition(0.0f, 0.0f);
    velocity = { 0,0 };
}