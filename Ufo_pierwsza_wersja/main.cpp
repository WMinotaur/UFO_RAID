#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "constants.h"
#include <iostream>
#include <filesystem>

using namespace sf;


class GameElement {
protected:
    Texture texture;
    Sprite sprite;
    bool is_initialised{ false };
    
public:
    

    GameElement (){
        
     }
    bool if_initialised() {
        return is_initialised;
    }
    void draw(RenderWindow* okno) {
        okno->draw(sprite);
    }
    void Create(std::string image_path) {
        is_initialised = texture.loadFromFile(image_path);
        if (is_initialised == true) {
            sprite.setTexture(texture);
        }
        std::filesystem::path xxx = std::filesystem::current_path();
    }
    
};
class Background:public GameElement {
private:
    std::string path = ".\\Textures\\background.jpg" ;

 public:

     Background():GameElement() {
         Create(path);
    }
    ~Background()
    {
        std::cout << "destruktor sie wykonal" << std::endl;
    }


};

class Ship:public GameElement {
private:
    std::string path{ ".\\Textures\\ufo.png" };
    float pozycja_x{};
    float pozycja_y{};
     
public:
    Ship():GameElement() {
        Create(path);
        sprite.setScale(0.15f, 0.15f);
        pozycja_x = (constants::window_width - sprite.getGlobalBounds().width) / 2;
        pozycja_y = constants::window_height - sprite.getGlobalBounds().height;
        sprite.setPosition(pozycja_x, pozycja_y);
    }

    void move(float offsetX, float offsetY) {
        pozycja_x += offsetX;
        pozycja_y += offsetY;
        if (pozycja_x < 0) {
            pozycja_x = 0;
            offsetX = 0;
        }
        if (pozycja_x + sprite.getGlobalBounds().width > constants::window_width) {
            pozycja_x = constants::window_width - sprite.getGlobalBounds().width;
            offsetY = 0;
        }
        sprite.move(offsetX, offsetY);
        
    }
};
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

        // Obs³uga klawiatury: ruch statku
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            ship.move(-5.f, 0.f); // Przesuwanie w lewo
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            ship.move(5.f, 0.f); // Przesuwanie w prawo
        }

        // Rysowanie
        okno.clear();
        background.draw(&okno);
        ship.draw(&okno);
        okno.display();
    }

    return 0;
}
