#pragma once
#include <SFML/Graphics.hpp>
#include "GameElement.h"
#include "constants.h"
#include <string>

using namespace sf;
class Background :public moving_GameElement
{
private:
	std::string level1_path{ ".\\Textures\\background_test.jpg" };
	std::string level2_path{ ".\\Textures\\background.jpg" };
	std::string gameover{ ".\\Textures\\background_lost.jpg" };
	std::string gameWon{ ".\\Textures\\background_kopia.jpg" };
	float distance_traveled{ 0 };
	float background_height{ 0 };

public:
	Background(std::string path);
	std::string Level1();
	void ShowEndGameScreen();
	Image* getImage();
	void update();
	float getDistanceTraveled();
	float getBackgroundHeight();
	void ShowWinGameScreen();
};
