#include <iostream>
#include "Game.hpp"
using namespace std;
// void Game::initializePlayers() {
// 	for (int i = 0; i < 4; ++i) {
// 		for (int j = 0; j < 6; ++j) {
// 			//TreasureCards card = treasureDeck.pop();
// 			//players[i].addTreasureCard(&card);
// 		}
// 	}
// }
bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "The A-MAZE-ing Labyrinth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	assets = loadTexture("mazecards.png");
	assets1 = loadTexture("highlightedarrow.png");
	player_asset = loadTexture("playerdots.png");
    cards1 = loadTexture("1.png");
    cards2 = loadTexture("2.png");
    cards3 = loadTexture("3.png");
	treasureTexture = loadTexture("treasuresallinone.png");
	ShowTreasure = loadTexture("treasurecardsallinone.png");
    gTexture = loadTexture("gamescreen.png");
	if(assets==NULL || gTexture==NULL || cards1==NULL || cards2==NULL || cards3==NULL || treasureTexture == NULL || ShowTreasure == NULL || player_asset == NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::startGame( )
{
	bool quit = false;
	SDL_Event e;
	Initialize();

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN) {
                // Handle keyboard events
				//cout << "Keyboard key pressed"<< endl;
                tick = keyevents.handleKeyboardEvent(e, board, players, &current);
				if (tick!=0)
				{
					showCard=true;
				}
				cout << "key pressed\n";
            }
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		board.DrawBoard(gRenderer, assets, treasureTexture);
		players[0]->DrawPlayer(gRenderer, player_asset);
		players[1]->DrawPlayer(gRenderer, player_asset);
		players[2]->DrawPlayer(gRenderer, player_asset);
		players[3]->DrawPlayer(gRenderer, player_asset);
		current->DrawPlayer(gRenderer, player_asset);
		SDL_RenderCopy(gRenderer, assets1, &arrow[keyevents.arrow_num], &arrow_dest[keyevents.arrow_num]);

		
		if(showCard)
		{
			board.showTreasure(current, gRenderer, ShowTreasure);
			if (SDL_GetTicks() >= tick + 2000)
			{
				showCard = false;
			}
		}

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
	}
			
}

Game::Game() {
    //Todo: Initialize players with their treasure cards
	
}

void Game::Initialize()
{
	board.initializeBoard();
	initializePlayers();
	board.AllocateCards(players);
	current = players[0];
}

void Game::initializePlayers()
{
	red = new Player();
	red->src = {603, 73, 40, 41};
	red->move = {603, 73, 40, 41};
	red->row = 0;
	red->col = 6;
	yellow = new Player();
	yellow->src = {82, 73, 41, 42};
	yellow->move = {82, 73, 41, 42};
	yellow->row = 0;
	yellow->col = 0;
	green = new Player();
	green->src = {83,591,37,37};
	green->move = {83,591,37,37};
	green->row = 6;
	green->col = 0;
	blue = new Player();
	blue->src = {611,592,35,35};
	blue->move = {611,592,35,35};
	blue->row = 6;
	blue->col = 6;
	players[0] = red;
	players[1] = yellow;
	players[2] = green;
	players[3] = blue;
	current = players[0];
}

// void Game::startGame() {
//Todo: Logic to initialize the game, distribute cards, set up the board
// }

void Game::playTurn(SDL_Event e) {
    
}

bool Game::isGameOver() {
    // Todo: Logic to determine if the game is over
    return false;
}

void Game::displayWinner() {
    //Todo: Logic to display the winner of the game
}