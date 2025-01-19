#include "Pointer.h"

Pointer::Pointer(GameElementPosition* Pos1, GameElementPosition* Pos2, GameElementPosition* Pos3) : GameElement(){
    Create(path);
    sprite.setScale(0.07f, 0.07f);
    
    Selection[0] = *Pos1;
    Selection[1] = *Pos2;
    Selection[2] = *Pos3;
    sprite.setPosition(Selection[0].x, Selection[0].y);
}
void  Pointer::moveDown() {
    GameElementPosition NewPosition{};
    if (this->currentSelection == NUMBEROFSELECTION - 1)
    {
        currentSelection = 0;
    }
    else 
    {
        currentSelection++;
    }
    NewPosition = Selection[currentSelection];
    sprite.setPosition(NewPosition.x, NewPosition.y);
}

void  Pointer::moveUp() {
    GameElementPosition NewPosition{};
    if (this->currentSelection == 0)
    {
        currentSelection = NUMBEROFSELECTION-1;
    }
    else
    {
        currentSelection--;
    }
    NewPosition = Selection[currentSelection];
    sprite.setPosition(NewPosition.x, NewPosition.y);
}

int Pointer::getCurrentSelection() {
    return currentSelection;
}