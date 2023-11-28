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
    void initializeBoard(); 
    void insertMazeCard(int arrow_num); 
    void movePlayer(); 
    void moveCard(); 
    void DrawBoard(SDL_Renderer*gRenderer, SDL_Texture* asset);

private:
    std::vector<MazeCards> rows;
    std::vector<MazeCards> cols;
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
    MazeCards usable;

};
