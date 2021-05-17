#include "fruite.h"
#include "snake.h"
#include "gameboard.h"
#include <cstdlib>
#include <time.h>


Fruite::Fruite()
{
    srand(static_cast<unsigned int>(time(NULL)));

    coordBuffer = rand() % GameBoard::getBoardSizeX();
    remainderBuffer = coordBuffer % gridSize;
    coordX = coordBuffer + (gridSize - remainderBuffer);

    coordBuffer = rand() % gridSize;
    remainderBuffer = coordBuffer % gridSize;
    coordY = coordBuffer + (gridSize - remainderBuffer);
}

void Fruite::relocateFruite()
{
    coordBuffer = rand() % GameBoard::getBoardSizeX();
    remainderBuffer = coordBuffer % gridSize;
    coordX = coordBuffer + (gridSize - remainderBuffer);

    coordBuffer = rand() % GameBoard::getBoardSizeY();
    remainderBuffer = coordBuffer % gridSize;
    coordY = coordBuffer + (gridSize - remainderBuffer);
}
