#pragma once
#include "GameElement.h"
#include "constants.h"

#define NUMBEROFSELECTION 3

/**
 * @class Pointer
 * @brief Manages the selection pointer in the game.
 */
class Pointer:public GameElement
{
private:
    std::string path{ ".\\Textures\\pointer.png" }; ///< Path to the pointer texture.
    GameElementPosition Selection[NUMBEROFSELECTION]; ///< Array of selection positions.
    int currentSelection{}; ///< Index of the current selection.

public:
    /**
     * @brief Constructs a Pointer object with three selection positions.
     * @param Pos1 First selection position.
     * @param Pos2 Second selection position.
     * @param Pos3 Third selection position.
     */
    Pointer(GameElementPosition* Pos1, GameElementPosition* Pos2, GameElementPosition* Pos3);

    /**
     * @brief Moves the selection pointer down.
     */
    void moveDown();

    /**
     * @brief Moves the selection pointer up.
     */
    void moveUp();

    /**
     * @brief Gets the current selection index.
     * @return The current selection index.
     */
    int getCurrentSelection();
};
