
#include "board.hpp"
Board::Board() 
{
    //initializeBoard();
}
Board::~Board() {
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            delete grid[i][j]; // Free allocated memory
            grid[i][j] = nullptr; // Set pointer to null after deletion
        }
    }
    delete usable;
    usable = nullptr;
}
void Board::initializeBoard() 
{
    //Todo: Initialize the board with fixed maze cards and starting players position
    Coordinates c(56, 48); FixedMaze* yellowBase = new FixedMaze(c); yellowBase->setsrc(allmazecards[0]);yellowBase->setID("0"); yellowBase->setType(corner); yellowBase->setTreasure(none); FM.push_back(*yellowBase);
    c.x = 226; FixedMaze* Books = new FixedMaze(c); Books->setsrc(allmazecards[8]); Books->setID("1"); Books->setType(three_sided); Books->setTreasure(books);FM.push_back(*Books);
    c.x=374; FixedMaze* Stash = new FixedMaze(c); Stash->setsrc(allmazecards[8]); Stash->setID("2"); Stash->setType(three_sided); Stash->setTreasure(stash);FM.push_back(*Stash);
    c.x = 534; FixedMaze* redBase = new FixedMaze(c); redBase->setsrc(allmazecards[2]); redBase->setID("3"); redBase->setType(corner); redBase->setTreasure(none);FM.push_back(*redBase);
    c.x = 56; c.y = 238; FixedMaze* Map = new FixedMaze(c); Map->setsrc(allmazecards[9]); Map->setID("4"); Map->setType(three_sided); Map->setTreasure(map);FM.push_back(*Map);
    c.x = 226; FixedMaze* Crown = new FixedMaze(c); Crown->setsrc(allmazecards[9]); Crown->setID("5"); Crown->setType(three_sided); Crown->setTreasure(crown);FM.push_back(*Crown);
    c.x=374; FixedMaze* Key = new FixedMaze(c); Key->setsrc(allmazecards[8]); Key->setID("6"); Key->setType(three_sided); Key->setTreasure(key);FM.push_back(*Key);
    c.x = 534; FixedMaze* Skull = new FixedMaze(c); Skull->setsrc(allmazecards[6]); Skull->setID("7"); Skull->setType(three_sided); Skull->setTreasure(skull);FM.push_back(*Skull);
    c.x = 56; c.y = 428; FixedMaze* Ring = new FixedMaze(c); Ring->setsrc(allmazecards[9]); Ring->setID("8"); Ring->setType(three_sided); Ring->setTreasure(ring);FM.push_back(*Ring);
    c.x = 226; FixedMaze* Chest = new FixedMaze(c); Chest->setsrc(allmazecards[7]); Chest->setID("9"); Chest->setType(three_sided); Chest->setTreasure(treasure_chest);FM.push_back(*Chest);
    c.x=374; FixedMaze* Emerald = new FixedMaze(c); Emerald->setsrc(allmazecards[6]); Emerald->setID("10"); Emerald->setType(three_sided); Emerald->setTreasure(emerald);FM.push_back(*Emerald);
    c.x = 534; FixedMaze* Sword = new FixedMaze(c); Sword->setsrc(allmazecards[6]); Sword->setID("11"); Sword->setType(three_sided); Sword->setTreasure(sword);FM.push_back(*Sword);
    c.x = 56; c.y = 618; FixedMaze* greenBase = new FixedMaze(c); greenBase->setsrc(allmazecards[1]); greenBase->setID("12"); greenBase->setType(corner); greenBase->setTreasure(none);FM.push_back(*greenBase);
    c.x = 226; FixedMaze* Candles = new FixedMaze(c); Candles->setsrc(allmazecards[7]); Candles->setID("13"); Candles->setType(three_sided); Candles->setTreasure(candles);FM.push_back(*Candles);
    c.x=374; FixedMaze* Helmet = new FixedMaze(c); Helmet->setsrc(allmazecards[7]); Helmet->setID("14"); Helmet->setType(three_sided); Helmet->setTreasure(helmet);FM.push_back(*Helmet);
    c.x = 534; FixedMaze* blueBase = new FixedMaze(c); blueBase->setsrc(allmazecards[3]); blueBase->setID("15"); blueBase->setType(corner); blueBase->setTreasure(none);FM.push_back(*blueBase);

    c.x = 146; c.y =48; MazeCards check(c, allmazecards[0]); check.setID("16"); check.setType(corner); check.setTreasure(none); check.setOrientation("SE"); //filler card
    grid = {
        {yellowBase, &check, Books, &check, Stash, &check, redBase},
        {&check, &check, &check, &check, &check, &check, &check},
        {Map, &check, Crown, &check, Key, &check, Skull},
        {&check, &check, &check, &check, &check, &check, &check},
        {Ring, &check, Chest, &check, Emerald, &check, Sword},
        {&check, &check, &check, &check, &check, &check, &check},
        {greenBase, &check, Candles, &check, Helmet, &check, blueBase}
    };

    std::vector<Treasure> T_assign = {none, none, none, none, none, dragon, none, none, none, none, owl, lizard, none, none, none, witch, bug, mouse, bat, spider, princess, genie,
                                    none,moth,none,none, none, none, ghost, none, none, none, none};
    int startingX[] = {146, 321, 496}; // X coordinates for columns
    int startingY = 48; // Initial Y coordinate
    int mazecardindex[] = {1, 3, 5};
    int cardindex[] = {0, 2, 4, 6};

    for (int col = 0; col < 3; col++) {
        int currentX = startingX[col];
        for (int row = 0; row < 7; row++) {
            int randomIndex = rand() % allmazecards.size();
            int randomTreasure = rand() % T_assign.size();
            SDL_Rect srcRect = allmazecards[randomIndex];

            Coordinates c(currentX, startingY + row * 87); // Calculate Y coordinate for each row
            Cards* mazeCard = new MazeCards(c, srcRect);
            mazeCard->setID(to_string(3 * col + row + 1)); // Assigning unique IDs
            switch(randomIndex)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                    mazeCard->setType(corner); // You can set the type as needed
                    break;
                case 4:
                case 5:
                    mazeCard->setType(line); // You can set the type as needed
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                    mazeCard->setType(three_sided); // You can set the type as needed
                    break;
            }
            

            mazeCard->setTreasure(T_assign[randomTreasure]); // Set the treasure type
            T_assign.erase(T_assign.begin()+randomTreasure);
            grid[row][mazecardindex[col]] = mazeCard;            // grid[row][mazecardindex[col]] = mazeCard;
        
        }
    }
    //cout<<"columns made"<<endl;

    int startingRowYCoords[] = {139, 313, 489}; // Y coordinates for rows
    int startingRowXCoords[] = {57, 236, 409, 588}; // X coordinates for rows

    for (int row = 0; row < 3; row++) {
        int currentY = startingRowYCoords[row];
        
        for (int col = 0; col < 4; col++) {
            int randomIndex = rand() % allmazecards.size();
            int randomTreasure = rand() % T_assign.size();
            SDL_Rect srcRect = allmazecards[randomIndex];
            Coordinates c(startingRowXCoords[col], currentY); // Calculate X coordinate for each column
            Cards* mazeCard = new MazeCards(c, srcRect);
            mazeCard->setID(to_string(3 * col + row + 1)); // Assigning unique IDs
            switch(randomIndex)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                    mazeCard->setType(corner); // You can set the type as needed
                    break;
                case 4:
                case 5:
                    mazeCard->setType(line); // You can set the type as needed
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                    mazeCard->setType(three_sided); // You can set the type as needed
                    break;
            }
            

            mazeCard->setTreasure(T_assign[randomTreasure]); // Set the treasure type
            T_assign.erase(T_assign.begin()+randomTreasure);
            grid[mazecardindex[row]][cardindex[col]] = mazeCard;
        }

    }
    int i = rand() % allmazecards.size();
    SDL_Rect srcRect = allmazecards[i];

    Coordinates usable_card(815, 413); // Define the coordinates
    usable->setsrc(srcRect);
    usable->setmove({815, 413, 85, 85});
    usable->setcoordinates(usable_card);
    usable->setID("0"); // Assign a unique ID
    switch(i)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                    usable->setType(corner); // You can set the type as needed
                    break;
                case 4:
                case 5:
                    usable->setType(line); // You can set the type as needed
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                    usable->setType(three_sided); // You can set the type as needed
                    break;
            }
    usable->setTreasure(none); // Set the treasure type

};

void Board::insertMazeCard(int arrow_num, Player* players[]) 
{
    Coordinates c(815, 413);
    Cards* temp = new MazeCards();
    int movable_index;
    if (arrow_num >= 0 && arrow_num <= 2) {
        movable_index = (arrow_num*2)+1; // Convert arrow number to index
        temp->setsrc(*(grid[movable_index][0]->getsrc()));
        temp->setID((grid[movable_index][0]->getID()));
        temp->setType((grid[movable_index][0]->getType()));
        temp->setTreasure((grid[movable_index][0]->getTreasure()));

        
        for (int i = 0; i < 6; i++) {
            MazeCards* currentCard = dynamic_cast<MazeCards*>(grid[movable_index][i + 1]);
            grid[movable_index][i]->setsrc(*(currentCard->getsrc()));
            grid[movable_index][i]->setID((currentCard->getID()));
            grid[movable_index][i]->setType((currentCard->getType()));
            grid[movable_index][i]->setTreasure((currentCard->getTreasure()));
        }
        grid[movable_index][6]->setsrc(*(usable->getsrc()));
        grid[movable_index][6]->setID((usable->getID()));
        grid[movable_index][6]->setType((usable->getType()));
        grid[movable_index][6]->setTreasure((usable->getTreasure()));
        // Update the properties of the 'usable' card
        for(int p = 0;p < 4;p++)
        {
            if (players[p]->row == movable_index)
            {
                players[p]->move_player('a', &grid, allmazecards, false);
            }
        }
        
    } 
    else if (arrow_num >= 3 && arrow_num <= 5)
    {
        movable_index = (-arrow_num * 2) + 11; // Convert arrow number to index
        temp->setsrc(*(grid[0][movable_index]->getsrc()));
        temp->setID((grid[0][movable_index]->getID()));
        temp->setType((grid[0][movable_index]->getType()));
        temp->setTreasure((grid[0][movable_index]->getTreasure()));

        
        for (int i = 0; i < 6; i++) {
            MazeCards* currentCard = dynamic_cast<MazeCards*>(grid[i+1][movable_index]);
            grid[i][movable_index]->setsrc(*(currentCard->getsrc()));
            grid[i][movable_index]->setID((currentCard->getID()));
            grid[i][movable_index]->setType((currentCard->getType()));
            grid[i][movable_index]->setTreasure((currentCard->getTreasure()));
        }
        grid[6][movable_index]->setsrc(*(usable->getsrc()));
        grid[6][movable_index]->setID((usable->getID()));
        grid[6][movable_index]->setType((usable->getType()));
        grid[6][movable_index]->setTreasure((usable->getTreasure()));
        for(int p = 0;p < 4;p++)
        {
            if (players[p]->col == movable_index)
            {
                players[p]->move_player('w', &grid, allmazecards, false);
            }
        }
    }
    else if (arrow_num >= 6 && arrow_num <= 8) {
        movable_index = (-arrow_num * 2) + 17;
        temp->setsrc(*(grid[movable_index][6]->getsrc()));
        temp->setID((grid[movable_index][6]->getID()));
        temp->setType((grid[movable_index][6]->getType()));
        temp->setTreasure((grid[movable_index][6]->getTreasure()));

        
        for (int i = 6; i > 0; i--) {
            MazeCards* currentCard = dynamic_cast<MazeCards*>(grid[movable_index][i-1]);
            grid[movable_index][i]->setsrc(*(currentCard->getsrc()));
            grid[movable_index][i]->setID((currentCard->getID()));
            grid[movable_index][i]->setType((currentCard->getType()));
            grid[movable_index][i]->setTreasure((currentCard->getTreasure()));
        }
        grid[movable_index][0]->setsrc(*(usable->getsrc()));
        grid[movable_index][0]->setID((usable->getID()));
        grid[movable_index][0]->setType((usable->getType()));
        grid[movable_index][0]->setTreasure((usable->getTreasure()));
        for(int p = 0;p < 4;p++)
        {
            if (players[p]->row == movable_index)
            {
                players[p]->move_player('d', &grid, allmazecards, false);
            }
        }
    }
    else if (arrow_num >= 9 && arrow_num <= 11) {
        movable_index = (arrow_num * 2) - 17;
        temp->setsrc(*(grid[6][movable_index]->getsrc()));
        temp->setID((grid[6][movable_index]->getID()));
        temp->setType((grid[6][movable_index]->getType()));
        temp->setTreasure((grid[6][movable_index]->getTreasure()));

        
        for (int i = 6; i > 0; i--) {
            MazeCards* currentCard = dynamic_cast<MazeCards*>(grid[i-1][movable_index]);
            grid[i][movable_index]->setsrc(*(currentCard->getsrc()));
            grid[i][movable_index]->setID((currentCard->getID()));
            grid[i][movable_index]->setType((currentCard->getType()));
            grid[i][movable_index]->setTreasure((currentCard->getTreasure()));
        }
        grid[0][movable_index]->setsrc(*(usable->getsrc()));
        grid[0][movable_index]->setID((usable->getID()));
        grid[0][movable_index]->setType((usable->getType()));
        grid[0][movable_index]->setTreasure((usable->getTreasure()));
        for(int p = 0;p < 4;p++)
        {
            if (players[p]->col == movable_index)
            {
                players[p]->move_player('s', &grid, allmazecards, false);
            }
        }
    }
        usable->setsrc(*(temp->getsrc()));
        usable->setmove({ 815, 413, 85, 85 });
        usable->setTreasuremove({830, 428, 50, 50});
        usable->setcoordinates(c);
        usable->setID((temp->getID()));
        usable->setType((temp->getType()));
        usable->setTreasure((temp->getTreasure()));
        delete temp;
        temp = nullptr;
}
void Board::rotateUsable()
{
    CardType c = usable->getType();
    SDL_Rect current = *(usable->getsrc());
    int newindex; 
    if (compareRects(current, allmazecards[0]))
    {
        newindex = 1;
    }
    else if (compareRects(current, allmazecards[1]))
    {
        newindex = 2;
    }
    else if (compareRects(current, allmazecards[2]))
    {
        newindex = 3;
    }
    else if (compareRects(current, allmazecards[3]))
    {
        newindex = 0;
    }
    else if (compareRects(current, allmazecards[4]))
    {
        newindex = 5;
    }
    else if (compareRects(current, allmazecards[5]))
    {
        newindex = 4;
    }
    else if (compareRects(current, allmazecards[6]))
    {
        newindex = 7;
    }
    else if (compareRects(current, allmazecards[7]))
    {
        newindex = 8;
    }
    else if (compareRects(current, allmazecards[8]))
    {
        newindex = 9;
    }
    else if (compareRects(current, allmazecards[9]))
    {
        newindex = 6;
    }
    usable->setsrc(allmazecards[newindex]);
}
bool Board::compareRects(SDL_Rect a, SDL_Rect b)
{
    return (a.x == b.x && a.y == b.y && a.w == b.w && a.h == b.h);
}
void Board::DrawBoard(SDL_Renderer* gRenderer, SDL_Texture* asset1, SDL_Texture* asset2)
{
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            
            if (grid[i][j] != nullptr) {
                MazeCards* mazeCard = dynamic_cast<MazeCards*>(grid[i][j]);
                if (mazeCard != nullptr) {
                    SDL_RenderCopy(gRenderer, asset1, mazeCard->getsrc(), mazeCard->getmove());
                    DrawTreasures(gRenderer, asset2, mazeCard);
                }
            }
        }
    }
    SDL_RenderCopy(gRenderer, asset1, usable->getsrc(), usable->getmove());
    MazeCards* temp = dynamic_cast<MazeCards*> (usable);
    DrawTreasures(gRenderer, asset2, temp);
}

void Board::DrawTreasures(SDL_Renderer* gRenderer, SDL_Texture* asset, MazeCards* mazeCard)
{
    int index = -1;
    switch(mazeCard->getTreasure())
    {
        case dragon:
            index = 0;
            break;
        case owl:
            index = 1;
            break;
        case lizard:
            index = 2;
            break;
        case witch:
            index = 3;
            break;
        case bug:
            index = 4;
            break;
        case mouse:
            index = 5;
            break;
        case bat:
            index = 6;
            break;
        case spider:
            index = 7;
            break;
        case princess:
            index = 8;
            break;
        case genie:
            index = 9;
            break;
        case moth:
            index = 10;
            break;
        case ghost:
            index = 11;
            break;
    }
    if(index != -1)
    {
        SDL_RenderCopy(gRenderer, asset, &allTreasures[index], mazeCard->getTreasuremove());
    }
}

void Board::AllocateCards(Player* players[])
{
    std::vector<Treasure> assign = {crown, dragon, ring, books, owl, lizard, witch, bug, 
                emerald, key, helmet, sword, stash, mouse, bat, spider,
                princess, map, genie, skull, candles, treasure_chest, moth, ghost};
    for (int i = 0;i < 4;i++)
    {
        for (int j = 0;j<6;j++)
        {
            int randomIndex = rand() % assign.size();
            players[i]->addCard(assign[randomIndex]);
            assign.erase(assign.begin() + randomIndex);
        }
    }
}
void Board::showTreasure(Player* p, SDL_Renderer* gRenderer, SDL_Texture* asset)
{
    Treasure toShow = p->getTop();
    SDL_RenderCopy(gRenderer, asset, &showTreasures[toShow-1], &ShowMover);
}
