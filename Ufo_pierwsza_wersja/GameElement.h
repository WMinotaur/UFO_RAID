#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class GameElement
{
protected:
    Texture texture;
    Sprite sprite;
    bool is_initialised{ false };

public:
    GameElement();
    bool if_initialised();
    void draw(RenderWindow* okno);
    void Create(std::string image_path);
    FloatRect get_bounding_box() const noexcept;

};



class moving_GameElement : public GameElement {
protected:
    sf::Vector2f velocity{ 0.f,0.f };
public:
};
