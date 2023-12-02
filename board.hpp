#pragma once
#include <vector>
#include "MazeCards.hpp" 
#include "FixedMazeCards.cpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

class Board {
public:
    Board(); 
    ~Board();
    void initializeBoard(); 
    void insertMazeCard(int arrow_num); 
    void movePlayer(); 
    void moveCard();
    void rotateUsable(); 
    void DrawBoard(SDL_Renderer*gRenderer, SDL_Texture* asset1, SDL_Texture* asset2);
    void DrawTreasures(SDL_Renderer* gRenderer, SDL_Texture* asset, MazeCards* mazeCard);
    bool compareRects(SDL_Rect a, SDL_Rect b);
private:
    std::vector<std::vector<Cards*>> grid;
    std::vector<FixedMaze> FM;
    std::vector<SDL_Rect> allmazecards = {

        {158,388,304,303},
        {158,753,303,304},
        {556,389,303,304},
        {556,753,304,303},

        {556, 46, 304, 303},
        {1061, 43, 303, 304},

        {1061,388,303,305},
        {1060,733,305,303},
        {1506,388,305,303},
        {1498,732,303,305}
    };

    std::vector<SDL_Rect> allTreasures =
    {
        {378,221,168,195}, //dragon
        {165,548,135,184}, //owl
        {392,520,130,219}, //lizard
        {619,524,138,219}, //witch
        {869,548,100,178}, //bug
        {381,1208,161,161}, //mouse
        {615,1235,159,106}, //bat
        {847,1235,156,108}, //spidey
        {161,1536,118,197}, //Princess
        {631,1529,128,197}, //genie
        {620,1920,152,90},  //moth
        {866,1856,128,204}, //ghost
    };
    Cards* usable = new MazeCards();

};
