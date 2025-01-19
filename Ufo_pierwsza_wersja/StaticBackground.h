#pragma once
#include "GameElement.h"
class StaticBackground :public GameElement
{
private:
	std::string image_path{};
public:
	StaticBackground(std::string path);
};

