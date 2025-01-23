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
#include <windows.h>

/**
 * @brief Enum representing the different game options.
 */
enum GameOptions {
	Level1 = 1,
	Level2,
	NextLevel,
	CreditsGame,
	ExitGame,
	Title,
	InitialisationError
};

/**
 * @brief The Game class manages the game state and game loop.
 */
class Game
{
private:
	/**
  * @brief Vector of enemy missiles.
  */
	std::vector<AbstractMissile*> missiles;

	/**
  * @brief Vector of friendly missiles.
  */
	std::vector<AbstractMissile*> friendlyMissile;

	/**
  * @brief Checks if the game is initialized properly.
  * @param bkg Pointer to the background object.
  * @param shp Pointer to the ship object.
  * @return True if initialized, false otherwise.
  */
	bool GameInitialized(Background* bkg, Ship* shp);

	/**
  * @brief Indicates if the game is paused.
  */
	bool paused;

	/**
  * @brief Main game loop.
  * @param window Pointer to the render window.
  * @param bgr Pointer to the background object.
  * @param ship Pointer to the ship object.
  * @return The current game option.
  */
	GameOptions GameLoop(RenderWindow* window, Background* bgr, Ship *ship);

	/**
  * @brief Deletes missiles from the window.
  * @param window Pointer to the render window.
  */
	void DeleteMissiless(RenderWindow* window);

	/**
  * @brief Updates the state of the missiles.
  * @param ship Pointer to the ship object.
  */
	void UpdateMissiles(Ship* ship);

	/**
  * @brief Path to the executable.
  */
	std::string executable_path{};

	/**
  * @brief Deletes all missiles from the window.
  * @param window Pointer to the render window.
  */
	void DeleteAllMissiles(RenderWindow* window);

public:
	/**
  * @brief Constructor for the Game class.
  */
	Game();

	/**
  * @brief Plays the first level of the game.
  * @param okno Pointer to the render window.
  * @return The current game option.
  */
	GameOptions PlayLevel1(RenderWindow* okno);

	/**
  * @brief Plays the second level of the game.
  * @param okno Pointer to the render window.
  * @return The current game option.
  */
	GameOptions PlayLevel2(RenderWindow* okno);

	/**
  * @brief Displays the title screen.
  * @param okno Pointer to the render window.
  * @return The current game option.
  */
	GameOptions TitleScreen(RenderWindow* okno);

	/**
  * @brief Displays the credits screen.
  * @param okno Pointer to the render window.
  * @return The current game option.
  */
	GameOptions Credits(RenderWindow* okno);

	/**
  * @brief Displays a message box with the given message.
  * @param message The message to display.
  */
	void displayMessageBox(const std::string& message);
};
