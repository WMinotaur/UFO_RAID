#pragma once
#include <SFML/Graphics.hpp>

/**
 * @namespace constants
 * @brief Contains constant values used throughout the application.
 */
namespace constants {
    /**
     * @brief The width of the application window.
     */
    constexpr float window_width = 1920;  

    /**
     * @brief The height of the application window.
     */
    constexpr float window_height = 1080;

    /**
     * @brief The horizontal velocity of the missile.
     */
    constexpr float missile_velocity_x = 0;

    /**
     * @brief The vertical velocity of the missile.
     */
    constexpr float missile_velocity_y = 13.0f;

    /**
     * @brief The period for missile generation in milliseconds.
     */
    constexpr int MISSILE_GENERATION_PERIOD = 1500;

    /**
     * @brief The horizontal velocity of the background.
     */
    constexpr float background_velocity_x = 0;

    /**
     * @brief The vertical velocity of the background.
     */
    constexpr float background_velocity_y = 4.0f;

    /**
     * @brief The vertical velocity of the friendly missile.
     */
    constexpr float friendlymissile_velocity_y{ missile_velocity_y / 1.5f };

    /**
     * @brief Position constants.
     */
    constexpr int Position = 647;
    constexpr int Position1 = 855;
    constexpr int Position2 = 950;
    constexpr int Position3 = 1040;
}
