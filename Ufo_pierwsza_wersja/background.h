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
	int distance_traveled{ 0 };
	int background_height{ 0 };

public:
	Background(std::string path);
	std::string Level1();
	void ShowEndGameScreen();
	Image* getImage();
	void update();
	int getDistanceTraveled();
	int getBackgroundHeight();
	void ShowWinGameScreen();
};
