#pragma once
#include <SFML/Graphics.hpp>
#include "GameElement.h"
#include "constants.h"

using namespace sf;
class Background :public moving_GameElement
{
private:
	std::string path{ ".\\Textures\\background.jpg" };
	std::string gameover{ ".\\Textures\\background_kopia.jpg" };
	int distance_traveled{ 0 };
	int background_height{ 0 };

public:
	Background();
	void ShowEndGameScreen();
	Image* getImage();
	void update();
	int getDistanceTraveled();
	int getBackgroundHeight();
};
