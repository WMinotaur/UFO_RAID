#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "constants.h"
#include <iostream>

using namespace sf;

class Background {
private:
    Texture texture;
    Sprite sprite;
public:
    bool prepare_enviroment()
    {
        texture.loadFromFile("background.jpg");
        sprite.setTexture(texture);
        return true;
    }
    Background() {
        
    }
    ~Background()
    {
        std::cout << "destruktor sie wykonal" << std::endl;
    }

    Sprite& getSprite() {
        return sprite;
    }


};

class Ship {
public:
    Ship() {
        is_initialised = false;
        
        if (!texture.loadFromFile("ufo.png")) {
            is_initialised = false;
        }
        else
        {
            is_initialised = true;
        }
           
       
        sprite.setTexture(texture);
        sprite.setScale(0.15f, 0.15f);
        float x = (constants::window_width - sprite.getGlobalBounds().width) / 2;
        float y = constants::window_height - sprite.getGlobalBounds().height;
        sprite.setPosition(x, y);
    }

    void move(float offsetX, float offsetY) {
        sprite.move(offsetX, offsetY);

        // Ograniczenie ruchu do obszaru okna
        if (sprite.getPosition().x < 0) {
            sprite.setPosition(0, sprite.getPosition().y);
        }
        if (sprite.getPosition().x + sprite.getGlobalBounds().width > constants::window_width) {
            sprite.setPosition(constants::window_width - sprite.getGlobalBounds().width, sprite.getPosition().y);
        }
    }

    Sprite& getSprite() {
        return sprite;
    }
    bool Got_initialized()
    {
        return is_initialised;
    }

private:
    Texture texture;
    Sprite sprite;
    bool is_initialised;
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

    RenderWindow okno({ constants::window_width, constants::window_height }, "gra_ufo");
    okno.setFramerateLimit(60);
    Background background;
    if (background.prepare_enviroment() == false)
    {
        Message_box box("nie udalo sie zaladowac tla", "blad");
        return -1;
    }
    
    Ship ship;
    if (ship.Got_initialized() == false) {
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
        okno.draw(background.getSprite());
        okno.draw(ship.getSprite());
        okno.display();
    }

    return 0;
}
