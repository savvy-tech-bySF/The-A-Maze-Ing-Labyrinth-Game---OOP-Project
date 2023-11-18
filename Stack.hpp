#include "TreasureCards.cpp"
#include <iostream>
#include<vector>
// class TreasureCards;

class Stack
{
public:
    void push(TreasureCards card);
    TreasureCards pop();
    bool isEmpty();
    TreasureCards top();
private:
    std::vector<TreasureCards> stack;
};