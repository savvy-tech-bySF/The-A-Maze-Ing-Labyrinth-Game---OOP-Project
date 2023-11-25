
#include "board.hpp"

Board::Board() 
{}

void Board::initializeBoard() 
{
    //Todo: Initialize the board with fixed maze cards and starting players position
    Coordinates c(56, 48); FixedMaze yellowBase(c); yellowBase.setID("0"); yellowBase.setType(corner); yellowBase.setTreasure(none);FM.push_back(yellowBase);
    Coordinates d(226, 210); FixedMaze Books(d); Books.setID("1"); Books.setType(three_sided); Books.setTreasure(books);FM.push_back(Books);
    Coordinates e(374, 370); FixedMaze Stash(e); Stash.setID("2"); Stash.setType(three_sided); Stash.setTreasure(stash);FM.push_back(Stash);
    Coordinates f(534, 530); FixedMaze redBase(f); redBase.setID("3"); redBase.setType(corner); redBase.setTreasure(none);FM.push_back(redBase);
    Coordinates g(56, 50); FixedMaze Map(g); Map.setID("4"); Map.setType(three_sided); Map.setTreasure(map);FM.push_back(Map);
    Coordinates h(226, 210); FixedMaze Crown(h); Crown.setID("5"); Crown.setType(three_sided); Crown.setTreasure(crown);FM.push_back(Crown);
    Coordinates i(374, 370); FixedMaze Key(i); Key.setID("6"); Key.setType(three_sided); Key.setTreasure(key);FM.push_back(Key);
    Coordinates j(534, 530); FixedMaze Skull(j); Skull.setID("7"); Skull.setType(three_sided); Skull.setTreasure(skull);FM.push_back(Skull);
    Coordinates k(56, 50); FixedMaze Ring(k); Ring.setID("8"); Ring.setType(three_sided); Ring.setTreasure(ring);FM.push_back(Ring);
    Coordinates l(226, 210); FixedMaze Chest(l); Chest.setID("9"); Chest.setType(three_sided); Chest.setTreasure(treasure_chest);FM.push_back(Chest);
    Coordinates m(374, 370); FixedMaze Emerald(m); Emerald.setID("10"); Emerald.setType(three_sided); Emerald.setTreasure(emerald);FM.push_back(Emerald);
    Coordinates n(534, 530); FixedMaze Sword(n); Sword.setID("11"); Sword.setType(three_sided); Sword.setTreasure(sword);FM.push_back(Sword);
    Coordinates o(56, 50); FixedMaze greenBase(o); greenBase.setID("12"); greenBase.setType(corner); greenBase.setTreasure(none);FM.push_back(greenBase);
    Coordinates p(226, 210); FixedMaze Candles(p); Candles.setID("13"); Candles.setType(three_sided); Candles.setTreasure(candles);FM.push_back(Candles);
    Coordinates q(374, 370); FixedMaze Helmet(q); Helmet.setID("14"); Helmet.setType(three_sided); Helmet.setTreasure(helmet);FM.push_back(Helmet);
    Coordinates r(534, 530); FixedMaze blueBase(r); blueBase.setID("15"); blueBase.setType(corner); blueBase.setTreasure(none);FM.push_back(blueBase);

    Coordinates s(146,48); MazeCards check(s); check.setID("16"); check.setType(corner); check.setTreasure(none); check.setOrientation("SE"); check.src = {154, 335, 411, 411}; check.move = {check.coords.x, check.coords.y, 85, 85};
    Coordinates t(321,48); MazeCards check2(t); check2.setID("17"); check2.setType(line); check2.setTreasure(none); check2.setOrientation("SE"); check2.src = {755, 335, 411, 411}; check2.move = {check2.coords.x, check2.coords.y, 85, 85};
    rows.push_back(check);
    rows.push_back(check2);
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
	    SDL_RenderCopy(gRenderer, asset, &rows[i].src, &rows[i].move);
    }

}