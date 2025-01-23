#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

/**
 * @brief Represents the position of a game element.
 */
class GameElementPosition {
public:
    float x{}; ///< X coordinate of the position
    float y{}; ///< Y coordinate of the position

    /**
     * @brief Constructs a GameElementPosition with specified coordinates.
     * @param PosX X coordinate
     * @param PosY Y coordinate
     */
    GameElementPosition(float PosX, float PosY);

    /**
     * @brief Default constructor for GameElementPosition.
     */
    GameElementPosition();
};

/**
 * @brief Base class for all game elements.
 */
class GameElement
{
protected:
    Texture texture; ///< Texture of the game element
    Sprite sprite; ///< Sprite of the game element
    bool is_initialised{ false }; ///< Initialization status
    GameElementPosition position; ///< Position of the game element
    Image image; ///< Image of the game element

public:
    /**
     * @brief Constructs a GameElement.
     */
    GameElement();

    /**
     * @brief Checks if the game element is initialized.
     * @return True if initialized, false otherwise.
     */
    bool if_initialised();

    /**
     * @brief Draws the game element on the given window.
     * @param okno Pointer to the render window.
     */
    void draw(RenderWindow* okno);

    /**
     * @brief Creates the game element with the specified image.
     * @param image_path Path to the image file.
     */
    void Create(std::string image_path);

    /**
     * @brief Gets the bounding box of the game element.
     * @return Bounding box as a FloatRect.
     */
    FloatRect get_bounding_box() const noexcept;

    /**
     * @brief Gets the position of the game element.
     * @return Pointer to the position of the game element.
     */
    GameElementPosition* getPosition();

    /**
     * @brief Virtual function to handle detonation of the game element.
     */
    virtual void detonate();
};

/**
 * @brief Derived class for moving game elements.
 */
class MovingGameElement : public GameElement {
protected:
    sf::Vector2f velocity{ 0.f,0.f }; ///< Velocity of the moving game element

public:
    /**
     * @brief Constructs a MovingGameElement.
     */
    MovingGameElement();
};
