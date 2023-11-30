
#include "board.hpp"
Board::Board() 
{}
Board::~Board() {
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            delete grid[i][j]; // Free allocated memory
            grid[i][j] = nullptr; // Set pointer to null after deletion
        }
    }
}
void Board::initializeBoard() 
{
    //Todo: Initialize the board with fixed maze cards and starting players position
    Coordinates c(56, 48); FixedMaze* yellowBase = new FixedMaze(c); yellowBase->setID("0"); yellowBase->setType(corner); yellowBase->setTreasure(none); FM.push_back(*yellowBase);
    c.x = 226; FixedMaze* Books = new FixedMaze(c); Books->setID("1"); Books->setType(three_sided); Books->setTreasure(books);FM.push_back(*Books);
    c.x=374; FixedMaze* Stash = new FixedMaze(c); Stash->setID("2"); Stash->setType(three_sided); Stash->setTreasure(stash);FM.push_back(*Stash);
    c.x = 534; FixedMaze* redBase = new FixedMaze(c); redBase->setID("3"); redBase->setType(corner); redBase->setTreasure(none);FM.push_back(*redBase);
    c.x = 56; c.y = 238; FixedMaze* Map = new FixedMaze(c); Map->setID("4"); Map->setType(three_sided); Map->setTreasure(map);FM.push_back(*Map);
    c.x = 226; FixedMaze* Crown = new FixedMaze(c); Crown->setID("5"); Crown->setType(three_sided); Crown->setTreasure(crown);FM.push_back(*Crown);
    c.x=374; FixedMaze* Key = new FixedMaze(c); Key->setID("6"); Key->setType(three_sided); Key->setTreasure(key);FM.push_back(*Key);
    c.x = 534; FixedMaze* Skull = new FixedMaze(c); Skull->setID("7"); Skull->setType(three_sided); Skull->setTreasure(skull);FM.push_back(*Skull);
    c.x = 56; c.y = 428; FixedMaze* Ring = new FixedMaze(c); Ring->setID("8"); Ring->setType(three_sided); Ring->setTreasure(ring);FM.push_back(*Ring);
    c.x = 226; FixedMaze* Chest = new FixedMaze(c); Chest->setID("9"); Chest->setType(three_sided); Chest->setTreasure(treasure_chest);FM.push_back(*Chest);
    c.x=374; FixedMaze* Emerald = new FixedMaze(c); Emerald->setID("10"); Emerald->setType(three_sided); Emerald->setTreasure(emerald);FM.push_back(*Emerald);
    c.x = 534; FixedMaze* Sword = new FixedMaze(c); Sword->setID("11"); Sword->setType(three_sided); Sword->setTreasure(sword);FM.push_back(*Sword);
    c.x = 56; c.y = 618; FixedMaze* greenBase = new FixedMaze(c); greenBase->setID("12"); greenBase->setType(corner); greenBase->setTreasure(none);FM.push_back(*greenBase);
    c.x = 226; FixedMaze* Candles = new FixedMaze(c); Candles->setID("13"); Candles->setType(three_sided); Candles->setTreasure(candles);FM.push_back(*Candles);
    c.x=374; FixedMaze* Helmet = new FixedMaze(c); Helmet->setID("14"); Helmet->setType(three_sided); Helmet->setTreasure(helmet);FM.push_back(*Helmet);
    c.x = 534; FixedMaze* blueBase = new FixedMaze(c); blueBase->setID("15"); blueBase->setType(corner); blueBase->setTreasure(none);FM.push_back(*blueBase);

    c.x = 146; c.y =48; MazeCards check(c, allmazecards[0]); check.setID("16"); check.setType(corner); check.setTreasure(none); check.setOrientation("SE");
    // c.x = 321; MazeCards check2(c,l1); check2.setID("17"); check2.setType(line); check2.setTreasure(none); check2.setOrientation("WE");
    // c.x = 146;c.y = 136; MazeCards check3(c,t3); check2.setID("18"); check3.setType(three_sided); check3.setTreasure(none); check3.setOrientation("WSE");
    // c.x = 321; MazeCards check4(c,c4); check4.setID("19"); check4.setType(corner); check4.setTreasure(none); check4.setOrientation("NW");
    // rows.push_back(check);
    // rows.push_back(check2);
    // rows.push_back(check3);
    // rows.push_back(check4);
    // 
    std::vector<std::vector<bool>> cannot_move = {
        {true, false, true, false, true, false, true},
        {false, false, false, false, false, false, false},
        {true, false, true, false, true, false, true},
        {false, false, false, false, false, false, false},
        {true, false, true, false, true, false, true},
        {false, false, false, false, false, false, false},
        {true, false, true, false, true, false, true}
    };
    grid = {
        {yellowBase, &check, Books, &check, Stash, &check, redBase},
        {&check, &check, &check, &check, &check, &check, &check},
        {Map, &check, Crown, &check, Key, &check, Skull},
        {&check, &check, &check, &check, &check, &check, &check},
        {Ring, &check, Chest, &check, Emerald, &check, Sword},
        {&check, &check, &check, &check, &check, &check, &check},
        {greenBase, &check, Candles, &check, Helmet, &check, blueBase}
    };
    //cout<<"grid made"<<endl;
    int startingX[] = {146, 321, 496}; // X coordinates for columns
    int startingY = 48; // Initial Y coordinate
    int mazecardindex[] = {1, 3, 5};
    int cardindex[] = {0, 2, 4, 6};

    for (int col = 0; col < 3; col++) {
        int currentX = startingX[col];
        for (int row = 0; row < 7; row++) {
            int randomIndex = rand() % allmazecards.size();
            SDL_Rect srcRect = allmazecards[randomIndex];

            Coordinates c(currentX, startingY + row * 87); // Calculate Y coordinate for each row
            MazeCards* mazeCard = new MazeCards(c, srcRect);
            
            mazeCard->setID(to_string(3 * col + row + 1)); // Assigning unique IDs
            mazeCard->setType(three_sided); // You can set the type as needed
            mazeCard->setTreasure(none); // Set the treasure type
            grid[row][mazecardindex[col]] = mazeCard;
           
        }
    }
    //cout<<"columns made"<<endl;

    int startingRowYCoords[] = {139, 313, 489}; // Y coordinates for rows
    int startingRowXCoords[] = {57, 236, 409, 588}; // X coordinates for rows

    for (int row = 0; row < 3; row++) {
        int currentY = startingRowYCoords[row];
        
        for (int col = 0; col < 4; col++) {
            int randomIndex = rand() % allmazecards.size();
            SDL_Rect srcRect = allmazecards[randomIndex];

            Coordinates c(startingRowXCoords[col], currentY); // Calculate X coordinate for each column

            MazeCards* mazeCard = new MazeCards(c, srcRect);
            mazeCard->setID(to_string(3 * col + row + 1)); // Assigning unique IDs
            mazeCard->setType(three_sided); // You can set the type as needed
            mazeCard->setTreasure(none); // Set the treasure type

            grid[mazecardindex[row]][cardindex[col]] = mazeCard;
        }
    }
    //cout<<"rows made"<<endl;
    int i = rand() % allmazecards.size();
    SDL_Rect srcRect = allmazecards[i];

    Coordinates usable_card(815, 413); // Define the coordinates
    usable->setsrc(srcRect);
    usable->setmove({815, 413, 85, 85});
    usable->setcoordinates(usable_card);
    usable->setID("0"); // Assign a unique ID
    usable->setType(three_sided); // Set the type
    usable->setTreasure(none); // Set the treasure type

};

void Board::insertMazeCard(int arrow_num) 
{
   Coordinates c(815, 413);

    if (arrow_num >= 1 && arrow_num <= 3) {
        int movable_index = arrow_num * 2 - 1; // Convert arrow number to index
        Cards* temp = grid[movable_index][0];
        for (int i = 6; i > 0; i--) {
            grid[movable_index][i-1] = grid[movable_index][i];
        }
        grid[movable_index][6] = usable;
        usable->setsrc(*(temp->getsrc()));
        usable->setmove({ 815, 413, 85, 85 });
        usable->setcoordinates(c);
        // Update the properties of the 'usable' card
    } else if (arrow_num >= 7 && arrow_num <= 9) {
        int movable_index = (arrow_num - 6) * 2 - 1; // Convert arrow number to index
        for (int i = 0; i < 6; i++) {
            grid[movable_index][i] = grid[movable_index][i + 1];
        }
        grid[movable_index][6] = usable;

        // Update the properties of the 'usable' card
        usable->setsrc(*(grid[movable_index][5]->getsrc()));
        usable->setmove({ 815, 413, 85, 85 });
        usable->setcoordinates(c);
    }
    
}

void Board::movePlayer() {
    // Todo: Implement the logic to move the player on the board
}

void Board::moveCard() {
    //Todo: Implement the logic to move the out of range card on the board
}
void Board::DrawBoard(SDL_Renderer* gRenderer, SDL_Texture* asset)
{
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            
            if (grid[i][j] != nullptr) {
                MazeCards* mazeCard = dynamic_cast<MazeCards*>(grid[i][j]);
                if (mazeCard != nullptr) {
                    SDL_RenderCopy(gRenderer, asset, mazeCard->getsrc(), mazeCard->getmove());
                    //cout<< mazeCard->getID()<<endl;
                }
            }
        }
    }
    SDL_RenderCopy(gRenderer, asset, usable->getsrc(), usable->getmove());

}