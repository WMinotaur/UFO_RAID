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
enum GameOptions {
	Play = 1,
	CreditsGame,
	ExitGame,
	InitialisationError

};
class Game
{
public:
	Game();
	void PlayGame(RenderWindow* okno);
	GameOptions TitleScreen(RenderWindow* okno);
	void Credits();
};

