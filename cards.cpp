#include "cards.hpp"

std::string Cards::getID()
{
    return _cardID;
}
void Cards::setID(std::string ID)
{
    _cardID = ID;
}
CardType Cards::getType()
{
    return _cardType;
}
void Cards::setType(CardType type)
{
    _cardType = type;
}
Treasure Cards::getTreasure()
{
    return _treasure;
}
void Cards::setTreasure(Treasure t)
{
    _treasure = t;
}
void Cards::setsrc(const SDL_Rect& s)  
{}
SDL_Rect* Cards::getsrc()
{}
void Cards::setmove(const SDL_Rect& m)
{}
SDL_Rect* Cards::getmove()
{}
SDL_Rect* Cards::getTreasureMove()
{}
void Cards::setTreasuremove(const SDL_Rect& tmove)
{}

void Cards::setcoordinates(Coordinates c)
{}
