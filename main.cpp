#pragma once
#include "Game.hpp"

int main(int argc, char* argv[])
{
    Game game;
    srand(time(NULL));
    //system("gameintrovid.mp4");
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
		//Load media
    if( !game.loadMedia() ){
        printf( "Failed to load media!\n" );
        return 0;
    }
    // Show the starting screen
    if (!game.showStartingScreen())
    {
        cout << "Starting screen display failed." << endl;
        return 0;
    }

    game.startGame();
    if (!game.showEndScreen())
    {
        cout << "End screen display failed." << endl;
        return 0;
    }
    game.close();
    return 0;
}