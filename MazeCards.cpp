#include "MazeCards.hpp"

void MazeCards::setOrientation(char* arr)
{
    MazeCards::orientation = arr;
}
char* MazeCards::getOrientation()
{
    return orientation;
}