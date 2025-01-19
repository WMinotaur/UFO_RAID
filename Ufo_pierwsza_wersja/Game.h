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
	CreditsGame,
	ExitGame,
	Title,
	InitialisationError

};
class Game
{
public:
	Game();
	GameOptions PlayLevel1(RenderWindow* okno);
	GameOptions PlayLevel2(RenderWindow* okno);
	GameOptions TitleScreen(RenderWindow* okno);
	void Credits();
};

