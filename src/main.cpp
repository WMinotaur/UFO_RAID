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
#include "Game.h"
#include <__msvc_filebuf.hpp>
//#include "interactions.h"

using namespace sf;
//DOTO list
// pociski z samolotu
// fuel
// przyspieszenie

/**
 * @brief The main function initializes the game and runs the main game loop.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    srand(static_cast<unsigned>(time(NULL)));

    RenderWindow okno(VideoMode::getDesktopMode(), "gra_ufo", sf::Style::Fullscreen);
    okno.setFramerateLimit(60);

    Game game;
    bool isGameRunning{ true };
    GameOptions options = Title;
    while (isGameRunning) {
        
        switch (options) {
            case Title:
                options = game.TitleScreen(&okno);
                break;
            case Level1:
                options = game.PlayLevel1(&okno);
                break;
            case Level2:
                options = game.PlayLevel2(&okno);
                break;
            case CreditsGame:
                options = game.Credits(&okno);
                break;
            case ExitGame:
                isGameRunning = false; 
                break;
            case InitialisationError:
                game.displayMessageBox("Game cannot be initialized, exiting");
                isGameRunning = false;
                break; 
        }
    } 
    
    return 0;
}
