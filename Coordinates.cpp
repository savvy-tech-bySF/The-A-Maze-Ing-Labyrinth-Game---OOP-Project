
#include "Coordinates.hpp"
Coordinates::Coordinates()
{
    
}
Coordinates::Coordinates(int xVal, int yVal) : x(xVal), y(yVal) 
{
    
}
bool Coordinates::validate()
{
    return false;
}

//Todo Set up validation according to board size and coordinates