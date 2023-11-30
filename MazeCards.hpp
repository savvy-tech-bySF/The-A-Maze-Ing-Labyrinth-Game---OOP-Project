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
    void setsrc(SDL_Rect src);
    SDL_Rect* getsrc();
    SDL_Rect* getmove();
    void setmove(SDL_Rect move);
    void setcoordinates(Coordinates c);
private:
    char* orientation;
};