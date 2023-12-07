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

class handlekeyboardevent {
public:
    handlekeyboardevent()= default; 
    int handleKeyboardEvent(SDL_Event& e, Board& board, Player* players[], Player** current);
    void highlightElements(bool highlightActiveRight, bool highlightActiveLeft);

    bool highlightActiveRight = false;
    bool highlightActiveLeft = false;
    int arrow_num{0};
    int tick;
    int i=0;
};

