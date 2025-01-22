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

void displayMessageBox(const std::string& message) {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(600, 200), "Problem with loading game elements");

    // Load a font
    //sf::Font font;
    //if (!font.loadFromFile("arial.ttf")) {
    //    std::cerr << "Error loading font\n";
    //    return;
    //}

    // Create a text
    sf::Text text;
    text.setString(message);
    text.setFillColor(sf::Color::Black);
    text.setPosition(50, 80);

    // Run the program as long as the window is open
    while (window.isOpen()) {
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window with white color
        window.clear(sf::Color::White);

        // Draw the text
        window.draw(text);

        // End the current frame
        window.display();
    }
}


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
                displayMessageBox("Game cannot be initialized, exiting");
                isGameRunning = false;
                break; 
        }
    } 
    
    return 0;
}
