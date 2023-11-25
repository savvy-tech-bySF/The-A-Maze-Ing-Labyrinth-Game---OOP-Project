#pragma once
#include <iostream>
#include <string>
#include "Enums.cpp"
#include "Coordinates.hpp"
#ifndef CARDS_HPP
#define CARDS_HPP
class Cards
{
public:
    std::string getID();
    void setID(std::string ID);
    CardType getType();
    void setType(CardType type);
    Treasure getTreasure();
    void setTreasure(Treasure t);
private:
    std::string _cardID;
    CardType _cardType;
    Treasure _treasure;
};
#endif