#pragma once
#include "GameElement.h"
#include "constants.h"

#define NUMBEROFSELECTION 3
class Pointer:public GameElement
{
private:
	std::string path{ ".\\Textures\\pointer.jpg" };
	GameElementPosition Selection[NUMBEROFSELECTION];
	int currentSelection{};

public:
	Pointer(GameElementPosition* Pos1, GameElementPosition* Pos2, GameElementPosition* Pos3);
	void  moveDown();
	void moveUp();
	int getCurrentSelection();
};

