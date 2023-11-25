#pragma once
#include "Player.hpp" 
#include "Board.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class Game {
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 700;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assets = NULL;
    SDL_Texture* cards1 = NULL;
    SDL_Texture* cards2 = NULL;
    SDL_Texture* cards3 = NULL;


public:
    Game(); 
    void startGame(); 
    void playTurn(); 
    bool isGameOver(); 
    void displayWinner(); 
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    

private:
    Player players[4]; // Assuming all 4 players are playing
    Player* currentPlayer; 
    Board board;
};