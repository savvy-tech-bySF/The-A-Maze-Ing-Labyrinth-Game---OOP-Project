
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