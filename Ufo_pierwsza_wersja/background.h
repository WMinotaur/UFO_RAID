#pragma once
#include <SFML/Graphics.hpp>
#include "GameElement.h"
#include "constants.h"
#include <string>

using namespace sf;

/**
 * @class Background
 * @brief Represents the background of the game, including end game and win game screens.
 */
class Background : public MovingGameElement
{
private:
    std::string gameover{ ".\\Textures\\background_lost.png" }; ///< Path to the game over background image.
    std::string gameLevelSuccess{}; ///< Path to the game level success background image.
    float distance_traveled{ 0 }; ///< Distance traveled by the background.
    float background_height{ 0 }; ///< Height of the background.

public:
    /**
     * @brief Constructs a new Background object.
     * @param path Path to the background image.
     * @param success_path Path to the success background image.
     */
    Background(std::string path, std::string success_path);

    /**
     * @brief Displays the end game screen.
     */
    void ShowEndGameScreen();

    /**
     * @brief Gets the image of the background.
     * @return Pointer to the Image object.
     */
    Image* getImage();

    /**
     * @brief Updates the background.
     */
    void update();

    /**
     * @brief Gets the distance traveled by the background.
     * @return Distance traveled.
     */
    float getDistanceTraveled();

    /**
     * @brief Gets the height of the background.
     * @return Background height.
     */
    float getBackgroundHeight();

    /**
     * @brief Displays the win game screen.
     */
    void ShowWinGameScreen();
};
