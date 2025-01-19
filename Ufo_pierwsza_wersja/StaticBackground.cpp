#include "StaticBackground.h"

StaticBackground::StaticBackground(std::string path) : GameElement() {
	image_path = path;
	Create(image_path);
	sprite.setPosition(0.f, 0.f);
	
}
