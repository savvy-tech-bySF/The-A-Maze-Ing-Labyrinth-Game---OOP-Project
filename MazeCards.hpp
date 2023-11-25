#pragma once
#include "cards.hpp"
#include <SDL.h>
class MazeCards : public Cards
{
public:
    MazeCards();
    MazeCards(Coordinates c);
    MazeCards(Coordinates c, SDL_Rect s);
    void setOrientation(char* arr);
    char* getOrientation();
    Coordinates coords;
    SDL_Rect src;
    SDL_Rect move;
private:
    char* orientation;
};