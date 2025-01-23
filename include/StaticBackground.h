#pragma once
#include "GameElement.h"
#include <string>

/**
 * @class StaticBackground
 * @brief Represents a static background element in the game.
 * 
 * This class inherits from GameElement and is used to manage and render
 * a static background image in the game.
 */
class StaticBackground : public GameElement
{
private:
    std::string image_path{}; ///< Path to the background image file.
public:
    /**
     * @brief Constructs a StaticBackground object with the specified image path.
     * 
     * @param path The file path to the background image.
     */
    StaticBackground(std::string path);
};
