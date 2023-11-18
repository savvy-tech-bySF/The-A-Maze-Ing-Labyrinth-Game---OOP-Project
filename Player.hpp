#include "stack.cpp" 
#include "coordinates.cpp"
#include "TreasureCards.cpp" 
#include "MazeCards.cpp" 
//Todo: define and then #include <SDL.h> 

class Player {

public:
    Player();
    Player(int ID, int startX, int startY);

    void setID(int ID);
    int getID() const;

    //void move(SDL_KeyboardEvent event); //Todo: Handle player movement based on SDL keyboard event (to be defined) 

    bool checkTreasure(); // Check if the player found any treasure

    TreasureCards* getFound(); // Return array of found treasure cards

    void place_maze_card(); // Place the out of range maze card on the board

private:
    int playerID;
    //int treasures; if we change the amount of players who can play. Default are 4
    Stack cards;
    Coordinates position;
    TreasureCards foundTreasure[6]; /*
    ! Assuming there are four players playing so each player gets 6 treasure cards */ 
    MazeCards mazecard;
};