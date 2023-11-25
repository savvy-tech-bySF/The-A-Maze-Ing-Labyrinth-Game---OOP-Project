#include "MazeCards.hpp"

MazeCards::MazeCards()=default;
MazeCards::MazeCards(Coordinates c) : coords(c){}
MazeCards::MazeCards(Coordinates c, SDL_Rect s) : coords(c)
{
    src.x = s.x; src.y = s.y; src.w = s.w; src.h = s.h;
    move.x = c.x; move.y = c.y; move.w = move.h = 85;
}


void MazeCards::setOrientation(char* arr)
{
    MazeCards::orientation = arr;
}
char* MazeCards::getOrientation()
{
    return orientation;
}