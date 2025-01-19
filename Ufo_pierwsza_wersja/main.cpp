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
//#include "interactions.h"

using namespace sf;
//DOTO list
// pociski z samolotu
// fuel
// przyspieszenie



int main() {
    srand(static_cast<unsigned>(time(NULL)));
    std::string path{ "C:\\git\\jpo_ufo_gra" };//zmienic na koniec
    std::filesystem::current_path(path);
    std::filesystem::path xxx = std::filesystem::current_path();


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
            break;

        case ExitGame:
            isGameRunning = false; 
            break;
 
        }

    }

    //------------------------------------------------------------------------- sprawdzanie czy sie wczytalo
   
    
    return 0;
}
