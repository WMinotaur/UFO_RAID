#pragma once
#include <SFML/Graphics.hpp>
#include "GameElement.h"
#include "constants.h"
#include <string>

using namespace sf;
class Background :public moving_GameElement
{
private:
	std::string gameover{ ".\\Textures\\background_lost.png" };
	std::string gameLevelSuccess{};
	float distance_traveled{ 0 };
	float background_height{ 0 };

public:
	Background(std::string path,std::string success_path);
	void ShowEndGameScreen();
	Image* getImage();
	void update();
	float getDistanceTraveled();
	float getBackgroundHeight();
	void ShowWinGameScreen();
};
