
#include "MazeCards.hpp"

MazeCards::MazeCards()
{

}

void MazeCards::setOrientation(char* arr)
{
    MazeCards::orientation = arr;
}
char* MazeCards::getOrientation()
{
    return orientation;
}