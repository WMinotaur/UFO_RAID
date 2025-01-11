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
//#include "interactions.h"

using namespace sf;
//DOTO list
// nie wychodzenie poza plansze
//S


class Message_box {
public:
    Message_box(std::string message, std::string title) {
        RectangleShape wi0adomosc;
        //todo:dorobic pozniej

    }
};

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    std::string path{ "C:\\git\\jpo_ufo_gra" };//zmienic na koniec

    std::filesystem::current_path(path);
    std::filesystem::path xxx = std::filesystem::current_path();


    RenderWindow okno({ constants::window_width, constants::window_height }, "gra_ufo");
    okno.setFramerateLimit(60);

    sf::Vector2f wymiary{ 1000,constants::window_height };
    RectangleShape plansza(wymiary);
    plansza.setFillColor(sf::Color(212, 106, 48));
    float x_position = (constants::window_width - wymiary.x) / 2;
    plansza.setPosition(x_position, 0.f);



    //------------------------------------------------------------------------- sprawdzanie czy sie wczytalo
    Background background;
    if (background.if_initialised() == false)
    {
        Message_box box("nie udalo sie zaladowac tla", "blad");
        return -1;
    }
    
    Ship ship;
    if (ship.if_initialised() == false) {
        Message_box box("nie udalo sie zaladowac statku", "blad");
        return -1;
    }
    std::vector<Missile*> missiles;
    


    if (ship.if_initialised() == false) {
        Message_box box("nie udalo sie zaladowac statku", "blad");
        return -1;
    }
    //interactions game_interactions;
    DWORD start_time{ GetTickCount() };
    DWORD CurrentTime{ GetTickCount() };

    //-------------------------------------------------------------------------------
    while (okno.isOpen()) {
        Event event;
        while (okno.pollEvent(event)) {
            if (event.type == Event::Closed) {
                okno.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            okno.close();
        }
        if (GetTickCount() - CurrentTime > constants::MISSILE_GENERATION_PERIOD && ship.isShipDetonated()==false)
        {
            GameElementPosition* ShipPosition = ship.getPosition();
            Missile* newMissile = new Missile(ShipPosition->x,0);
            missiles.push_back(newMissile);
            CurrentTime = GetTickCount();
        }
        

        // Obs³uga klawiatury: ruch statku
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            ship.move(-5.f, 0.f); // Przesuwanie w lewo
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            ship.move(5.f, 0.f); // Przesuwanie w prawo
        }
        //update
        for (Missile* m : missiles) {
            m->update();
            m->detectColision(&ship);
        }
        if (ship.isShipDetonated()) {
            
            for (Missile* m : missiles) {
                delete m;
            }
            missiles.erase(missiles.begin(), missiles.end());
            background.ShowEndGameScreen();
        }

       // game_interactions.clash(ship, *missile[0]);

        // Rysowanie
        okno.clear();
        background.draw(&okno);
        if (ship.isShipDetonated() == false) { okno.draw(plansza); }
        ship.draw(&okno);
        for (int i{}; i < missiles.size(); i++) {
            Missile* m = missiles[i];
            if (m != NULL) {
                if (m->toBeDeleted()) {
                    missiles.erase(missiles.begin()+i);
                    delete m;
                    break;
                }
                m->draw(&okno);
                
            }
            
        }
        okno.display();
    }
    
    return 0;
}
