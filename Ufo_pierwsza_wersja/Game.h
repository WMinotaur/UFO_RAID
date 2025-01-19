#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "constants.h"
#include <iostream>
#include <filesystem>
#include "GameElement.h"
#include "Background.h"
#include "Ship.h"
#include "Missile.h"
#include <windows.h>
#include "Pointer.h"
#include "StaticBackground.h"
#include "FriendlyMissile.h"

enum GameOptions {
	Level1 = 1,
	Level2,
	NextLevel,
	CreditsGame,
	ExitGame,
	Title,
	InitialisationError

};
class Game
{
private:
	std::vector<Missile*> missiles;
	std::vector<FriendlyMissile*> friendlyMissile;
	bool GameInitialized(Background* bkg, Ship* shp);
	bool paused;
	GameOptions GameLoop(RenderWindow* window, Background* bgr, Ship *ship );
	void DeleteMissless(RenderWindow* window);
	void UpdateMissles(Ship* ship);
public:
	Game();
	GameOptions PlayLevel1(RenderWindow* okno);
	GameOptions PlayLevel2(RenderWindow* okno);
	GameOptions TitleScreen(RenderWindow* okno);
	GameOptions Credits(RenderWindow* okno);
};

