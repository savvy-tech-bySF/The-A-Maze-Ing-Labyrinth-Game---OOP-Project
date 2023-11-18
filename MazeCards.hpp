#include "cards.cpp"
class MazeCards : public Cards
{
public:
    Coordinates coords;
    MazeCards();
    void setOrientation(char* arr);
    char* getOrientation();
private:
    char* orientation;
};