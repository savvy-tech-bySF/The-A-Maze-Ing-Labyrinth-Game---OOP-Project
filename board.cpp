
#include "board.hpp"
Board::Board() 
{}

void Board::initializeBoard() 
{
    //Todo: Initialize the board with fixed maze cards and starting players position
    Coordinates c(56, 48); FixedMaze yellowBase(c); yellowBase.setID("0"); yellowBase.setType(corner); yellowBase.setTreasure(none);FM.push_back(yellowBase);
    c.x = 226; FixedMaze Books(c); Books.setID("1"); Books.setType(three_sided); Books.setTreasure(books);FM.push_back(Books);
    c.x=374; FixedMaze Stash(c); Stash.setID("2"); Stash.setType(three_sided); Stash.setTreasure(stash);FM.push_back(Stash);
    c.x = 534; FixedMaze redBase(c); redBase.setID("3"); redBase.setType(corner); redBase.setTreasure(none);FM.push_back(redBase);
    c.x = 56; c.y = 238; FixedMaze Map(c); Map.setID("4"); Map.setType(three_sided); Map.setTreasure(map);FM.push_back(Map);
    c.x = 226; FixedMaze Crown(c); Crown.setID("5"); Crown.setType(three_sided); Crown.setTreasure(crown);FM.push_back(Crown);
    c.x=374; FixedMaze Key(c); Key.setID("6"); Key.setType(three_sided); Key.setTreasure(key);FM.push_back(Key);
    c.x = 534; FixedMaze Skull(c); Skull.setID("7"); Skull.setType(three_sided); Skull.setTreasure(skull);FM.push_back(Skull);
    c.x = 56; c.y = 428; FixedMaze Ring(c); Ring.setID("8"); Ring.setType(three_sided); Ring.setTreasure(ring);FM.push_back(Ring);
    c.x = 226; FixedMaze Chest(c); Chest.setID("9"); Chest.setType(three_sided); Chest.setTreasure(treasure_chest);FM.push_back(Chest);
    c.x=374; FixedMaze Emerald(c); Emerald.setID("10"); Emerald.setType(three_sided); Emerald.setTreasure(emerald);FM.push_back(Emerald);
    c.x = 534; FixedMaze Sword(c); Sword.setID("11"); Sword.setType(three_sided); Sword.setTreasure(sword);FM.push_back(Sword);
    c.x = 56; c.y = 618; FixedMaze greenBase(c); greenBase.setID("12"); greenBase.setType(corner); greenBase.setTreasure(none);FM.push_back(greenBase);
    c.x = 226; FixedMaze Candles(c); Candles.setID("13"); Candles.setType(three_sided); Candles.setTreasure(candles);FM.push_back(Candles);
    c.x=374; FixedMaze Helmet(c); Helmet.setID("14"); Helmet.setType(three_sided); Helmet.setTreasure(helmet);FM.push_back(Helmet);
    c.x = 534; FixedMaze blueBase(c); blueBase.setID("15"); blueBase.setType(corner); blueBase.setTreasure(none);FM.push_back(blueBase);

    c.x = 146; c.y =48; MazeCards check(c,c1); check.setID("16"); check.setType(corner); check.setTreasure(none); check.setOrientation("SE");
    c.x = 321; MazeCards check2(c,l1); check2.setID("17"); check2.setType(line); check2.setTreasure(none); check2.setOrientation("WE");
    c.x = 146;c.y = 136; MazeCards check3(c,t3); check2.setID("18"); check3.setType(three_sided); check3.setTreasure(none); check3.setOrientation("WSE");
    c.x = 321; MazeCards check4(c,c4); check4.setID("19"); check4.setType(corner); check4.setTreasure(none); check4.setOrientation("NW");
    rows.push_back(check);
    rows.push_back(check2);
    rows.push_back(check3);
    rows.push_back(check4);
}
void Board::insertMazeCard(const MazeCards& card, const Coordinates& coordinates) 
{
    //Todo: Insert the provided maze card at the specified coordinates on the board
}

void Board::movePlayer() {
    // Todo: Implement the logic to move the player on the board
}

void Board::moveCard() {
    //Todo: Implement the logic to move the out of range card on the board
}
void Board::DrawBoard(SDL_Renderer* gRenderer, SDL_Texture* asset)
{
    for(int i = 0;i < rows.size();i++)
    {
        // cout << rows[i].src.x << " " << rows[i].src.y << " " << rows[i].src.w << " " << rows[i].src.h << endl;
	    SDL_RenderCopy(gRenderer, asset, &rows[i].src, &rows[i].move);
    }

}