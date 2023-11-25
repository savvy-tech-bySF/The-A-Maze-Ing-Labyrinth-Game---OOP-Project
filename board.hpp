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
    SDL_Rect c1 = {158,388,304,303};
    SDL_Rect c2 = {158,753,303,304};
    SDL_Rect c3 = {556,389,303,304};
    SDL_Rect c4 = {556,753,304,303};

    SDL_Rect l1 = {556, 46, 304, 303};
    SDL_Rect l2 = {1061, 43, 303, 304};

    SDL_Rect t1 = {1061,388,303,305};
    SDL_Rect t2 = {1060,733,305,303};
    SDL_Rect t3 = {1506,388,305,303};
    SDL_Rect t4 = {1498,732,303,305};
};
