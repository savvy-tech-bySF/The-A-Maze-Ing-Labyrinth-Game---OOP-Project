class Coordinates
{
public:
    Coordinates();
    Coordinates(int xVal, int yVal);
    bool validate();
private:
    int x;
    int y;
};