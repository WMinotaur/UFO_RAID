#pragma once
#include <SFML/Graphics.hpp>

namespace constants {
	constexpr float window_width = 1920;  
	constexpr float window_height = 1080;
	constexpr float missile_velocity_x = 0;
	constexpr float missile_velocity_y = 13.0f;
	constexpr int MISSILE_GENERATION_PERIOD = 2000;
	constexpr float background_velocity_x = 0;
	constexpr float background_velocity_y = 6.0f;
	constexpr float friendlymissile_velocity_y{ missile_velocity_y / 1.5f };
	constexpr int Position = 647;
	constexpr int Position1 = 855;
	constexpr int Position2 = 950;
	constexpr int Position3 = 1040;

}
