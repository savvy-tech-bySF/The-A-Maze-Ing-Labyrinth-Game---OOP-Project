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
    void insertMazeCard(const MazeCards& card, const Coordinates& coordinates); 
    void movePlayer(); 
    void moveCard(); 
    void DrawBoard(SDL_Renderer*gRenderer, SDL_Texture* asset);

private:
    std::vector<MazeCards> rows;
    std::vector<MazeCards> cols;
    std::vector<FixedMaze> FM;
};
