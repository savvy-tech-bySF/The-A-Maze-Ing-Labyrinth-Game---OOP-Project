#pragma once
#include "cards.hpp"
class MazeCards : public Cards
{
public:
    MazeCards();
    MazeCards(Coordinates c) : coords(c){}
    void setOrientation(char* arr);
    char* getOrientation();
    Coordinates coords;
    SDL_Rect src;
    SDL_Rect move;
private:
    char* orientation;
};