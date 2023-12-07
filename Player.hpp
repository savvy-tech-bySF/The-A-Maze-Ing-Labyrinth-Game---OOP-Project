#pragma once
#include "Stack.hpp" 
#include "Coordinates.hpp"
#include "TreasureCards.cpp" 
#include "MazeCards.hpp" 
#include <vector>
#include <SDL.h>
#ifndef PLAYER_HPP
#define PLAYER_HPP
//Todo: define and then #include <SDL.h> 

class Player {

public:
    Player();
    Player(int ID, int startX, int startY);

    void setID(int ID);
    int getID() const;
    void addCard(Treasure t);
    Treasure getTop();
    void pop();
    void DrawPlayer(SDL_Renderer* gRenderer, SDL_Texture* asset, SDL_Rect src, SDL_Rect move);
    bool treasurefound(std::vector<std::vector<Cards*>> *grid);
    bool validate_move(SDL_Rect* adjacentCard, char direction, std::vector<std::vector<Cards*>> *grid, std::vector<SDL_Rect> allmazecards, bool current = false);
    void place_maze_card(); // Place the out of range maze card on the board
    void move_player(char direction, std::vector<std::vector<Cards*>> *grid, std::vector<SDL_Rect> allmazecards, bool validate=true);
    bool isplacingcardallowed();
    bool isrotationallowed();
    bool ismovementallowed();
    int playerID;
    SDL_Rect framesrc;
    int row; 
    int col;
    SDL_Rect src;
    SDL_Rect move; 
    bool card_placed = false, playermovement = false, rotation = true, player_turn_ended = false;
    std::vector<Treasure> toFind; /*
    //! Assuming there are four players playing so each player gets 6 treasure cards */ 
    MazeCards mazecard;
};

#endif