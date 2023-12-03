
#include "cards.hpp"
class FixedMaze : public Cards
{
public:
    FixedMaze(Coordinates c) : coords(c)
    {}
    FixedMaze(){}
    Coordinates coords;
    void setsrc(const SDL_Rect& s)
    {
        src = s;
    }
    SDL_Rect* getsrc()
    {
        return &src;
    }
    void setmove(const SDL_Rect& m)
    {
        move = m;
    }
    SDL_Rect* getmove()
    {
        return &move;
    }
private:
};