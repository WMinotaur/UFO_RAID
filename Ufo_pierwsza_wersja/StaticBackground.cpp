#include "StaticBackground.h"

/**
 * @brief Construct a new Static Background object
 * 
 * @param path The file path to the image used for the background
 */
StaticBackground::StaticBackground(std::string path) : GameElement() {
    image_path = path;
    Create(image_path);
    sprite.setPosition(0.f, 0.f);
}
