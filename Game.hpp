#pragma once
#include "Player.hpp" 

class Game {
public:
    Game(); 
    void startGame(); 
    void playTurn(); 
    bool isGameOver(); 
    void displayWinner(); 

private:
    Player players[4]; // Assuming all 4 players are playing
    Player* currentPlayer; 
};