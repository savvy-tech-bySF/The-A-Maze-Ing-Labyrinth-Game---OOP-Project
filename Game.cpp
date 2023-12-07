#include <iostream>
#include "Game.hpp"
using namespace std;

bool Game::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
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
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    else
    {
        Mix_Music *bgMusic = Mix_LoadMUS("sneakysnitch.mp3"); // Replace "background_music.mp3" with your audio file
        if (bgMusic == nullptr)
        {
            printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
            success = false;
        }
        else
        {
            Mix_PlayMusic(bgMusic, -1); // Play the music in an infinite loop (-1)
        }
    }
	return success;
}
bool Game::showStartingScreen()
{
    SDL_Texture* startingScreenTexture = loadTexture("startingscreen.png");
    if (startingScreenTexture == nullptr)
    {
        printf("Failed to load starting screen texture! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Show starting screen for 7 seconds (7000 milliseconds)
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, startingScreenTexture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);

    // Delay for 7 seconds before transitioning
    SDL_Delay(7000);  // Adjust this delay as needed (in milliseconds)

    // Free texture
    SDL_DestroyTexture(startingScreenTexture);

    return true;
}
bool Game::showEndScreen(Player* p)
{
    SDL_Texture* endScreenTexture = nullptr;
	if (p == red)
	{
		endScreenTexture = loadTexture("redWin.png");
	}
	else if (p == yellow)
	{
		endScreenTexture = loadTexture("yellowWin.png");
	}
	else if (p == green)
	{
		endScreenTexture = loadTexture("greenWin.png");
	}
	else if (p == blue)
	{
		endScreenTexture = loadTexture("blueWin.png");
	}
    if (endScreenTexture == nullptr)
    {
        printf("Failed to load end screen texture! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Show end screen for 7 seconds (7000 milliseconds)
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, endScreenTexture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);

    // Delay for 7 seconds before transitioning
    SDL_Delay(7000);  // Adjust this delay as needed (in milliseconds)

    // Free texture
    SDL_DestroyTexture(endScreenTexture);

    return true;
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
	frames = loadTexture("currentframes.png");
	treasureTexture = loadTexture("treasuresallinone.png");
	ShowTreasure = loadTexture("treasurecardsallinone.png");
	treasurefound = loadTexture("treasurefound.png");
    gTexture = loadTexture("gamescreen.png");
	if(assets==NULL || gTexture==NULL || cards1==NULL || cards2==NULL || cards3==NULL || treasureTexture == NULL || ShowTreasure == NULL || player_asset == NULL || treasurefound == NULL)
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
	Mix_Quit();
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
				// cout << "key pressed\n";
            }
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		board.DrawBoard(gRenderer, assets, treasureTexture);
		players[0]->DrawPlayer(gRenderer, player_asset, players[0]->src, players[0]->move);
		players[1]->DrawPlayer(gRenderer, player_asset, players[1]->src, players[1]->move);
		players[2]->DrawPlayer(gRenderer, player_asset, players[2]->src, players[2]->move);
		players[3]->DrawPlayer(gRenderer, player_asset, players[3]->src, players[3]->move);
		current->DrawPlayer(gRenderer, player_asset, current->src, current->move);
		current->DrawPlayer(gRenderer, frames, current->framesrc, current->framesrc);
		
		SDL_RenderCopy(gRenderer, assets1, &arrow[keyevents.arrow_num], &arrow_dest[keyevents.arrow_num]);
		if (current->treasurefound(&board.grid))
		{
			current->card_placed = false;
			current->playermovement = false;
			current->player_turn_ended = false;
			keyevents.i += 1;

			// Display the treasure found texture
			SDL_RenderCopy(gRenderer, treasurefound, &treasurefoundsrcandmove, &treasurefoundsrcandmove);
			treasureDisplayStartTime = SDL_GetTicks();
			treasureDisplayed = true;

			current = players[keyevents.i % 4];
		}

		// Check if 2 seconds have passed since displaying the treasure
		if (treasureDisplayed && SDL_GetTicks() < treasureDisplayStartTime + 2000)
		{
			SDL_RenderCopy(gRenderer, treasurefound, &treasurefoundsrcandmove, &treasurefoundsrcandmove);
		// Move to the next player or perform other actions after 2 seconds
		}
		else {
			treasureDisplayed = false;
		}
		if(showCard)
		{
			board.showTreasure(current, gRenderer, ShowTreasure);
			if (SDL_GetTicks() >= tick + 2000)
			{
				showCard = false;
			}
		}
		if (isGameOver())
		{
			displayWinner();
			quit = true;
		}

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
	}
			
}

Game::Game() {
    
	
}

Game::~Game()
{
	deletion(red);
	deletion(green);
	deletion(blue);
	deletion(yellow);
	deletion(players[1]);
	deletion(players[2]);
	deletion(players[3]);
	deletion(players[0]);
	deletion(current);
	red = green = blue = yellow = players[0] = players[1] = players[2] = players[3] = current = nullptr;
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
	red->framesrc = {584, 49, 89, 89};
	red->row = 0;
	red->col = 6;
	yellow = new Player();
	yellow->src = {82, 73, 41, 42};
	yellow->move = {82, 73, 41, 42};
	yellow->framesrc = {55, 47, 88, 89};
	yellow->row = 0;
	yellow->col = 0;
	green = new Player();
	green->src = {83,591,37,37};
	green->move = {83,591,37,37};
	green->framesrc = {55, 570, 88, 89};
	green->row = 6;
	green->col = 0;
	blue = new Player();
	blue->src = {611,592,35,35};
	blue->move = {611,592,35,35};
	blue->framesrc = {583, 568, 88, 89};
	blue->row = 6;
	blue->col = 6;
	players[0] = red;
	players[1] = yellow;
	players[2] = green;
	players[3] = blue;
}

bool Game::isGameOver() {
    if ((players[0]->toFind.size()==0 && players[0]->row == 0 && players[0]->col ==6) || (players[1]->toFind.size()==0 && players[1]->row == 0 && players[1]->col == 0) || (players[2]->toFind.size()==0 && players[2]->row == 6 && players[2]->col == 0) || (players[3]->toFind.size()==0 && players[3]->row == 6 && players[3]->col == 6)){
		return true;
	}
	else 
	{
		return false;
	}
}

void Game::displayWinner() {
    if (players[0]->toFind.size()==0 && players[0]->row == 0 && players[0]->col ==6){
		cout<<"Red wins"<<endl;
			if (!showEndScreen(red))
		{
			cout << "End screen display failed." << endl;
		}
	}
	else if (players[1]->toFind.size()==0 && players[1]->row == 0 && players[1]->col == 0){
		cout<<"Yellow wins"<<endl;
		if (!showEndScreen(yellow))
		{
			cout << "End screen display failed." << endl;
		}
	}
	else if (players[2]->toFind.size()==0 && players[2]->row == 6 && players[2]->col == 0){
		cout<<"Green wins"<<endl;
		if (!showEndScreen(green))
		{
			cout << "End screen display failed." << endl;
		}
	}
	else if (players[3]->toFind.size()==0 && players[3]->row == 6 && players[3]->col == 6){
		cout<<"Blue wins"<<endl;
		if (!showEndScreen(blue))
		{
			cout << "End screen display failed." << endl;
		}
	}
}
void Game::deletion(Player* p)
{
    if (p != nullptr)
    {
        delete p;
    }
}