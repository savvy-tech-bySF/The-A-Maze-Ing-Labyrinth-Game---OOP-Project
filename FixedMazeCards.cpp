
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
        Cards::src = s;
    }
    SDL_Rect* getsrc()
    {
        return &(Cards::src);
    }
    void setmove(const SDL_Rect& m)
    {
        Cards::move = m;
    }
    SDL_Rect* getmove()
    {
        return &(Cards::move);
    }
private:
};