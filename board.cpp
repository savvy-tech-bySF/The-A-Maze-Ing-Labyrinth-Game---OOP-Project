
#include "Board.hpp"

Board::Board() 
{}

void Board::initializeBoard() 
{
    //Todo: Initialize the board with fixed maze cards and starting players position
    // Coordinates c(54, 50); FixedMaze yellowBase(c); yellowBase.setID("0"); yellowBase.setType(corner); yellowBase.setTreasure(none);
    // Coordinates d(214, 210); FixedMaze Books(d); Books.setID("1"); Books.setType(three_sided); Books.setTreasure(books);
    // Coordinates e(374, 370); FixedMaze Stash(e); Stash.setID("2"); Stash.setType(three_sided); Stash.setTreasure(stash);
    // Coordinates f(534, 530); FixedMaze redBase(f); redBase.setID("3"); redBase.setType(corner); redBase.setTreasure(none);
    // Coordinates g(54, 50); FixedMaze Map(g); Map.setID("4"); Map.setType(three_sided); Map.setTreasure(map);
    // Coordinates h(214, 210); FixedMaze Crown(h); Crown.setID("5"); Crown.setType(three_sided); Crown.setTreasure(crown);
    // Coordinates i(374, 370); FixedMaze Key(i); Key.setID("6"); Key.setType(three_sided); Key.setTreasure(key);
    // Coordinates j(534, 530); FixedMaze Skull(j); Skull.setID("7"); Skull.setType(three_sided); Skull.setTreasure(skull);
    // Coordinates k(54, 50); FixedMaze Ring(k); Ring.setID("8"); Ring.setType(three_sided); Ring.setTreasure(ring);
    // Coordinates l(214, 210); FixedMaze Chest(l); Chest.setID("9"); Chest.setType(three_sided); Chest.setTreasure(treasure_chest);
    // Coordinates m(374, 370); FixedMaze Emerald(m); Emerald.setID("10"); Emerald.setType(three_sided); Emerald.setTreasure(emerald);
    // Coordinates n(534, 530); FixedMaze Sword(n); Sword.setID("11"); Sword.setType(three_sided); Sword.setTreasure(sword);
    // Coordinates o(54, 50); FixedMaze greenBase(o); greenBase.setID("12"); greenBase.setType(corner); greenBase.setTreasure(none);
    // Coordinates p(214, 210); FixedMaze Candles(p); Candles.setID("13"); Candles.setType(three_sided); Candles.setTreasure(candles);
    // Coordinates q(374, 370); FixedMaze Helmet(q); Helmet.setID("14"); Helmet.setType(three_sided); Helmet.setTreasure(helmet);
    // Coordinates r(534, 530); FixedMaze blueBase(r); blueBase.setID("15"); blueBase.setType(corner); blueBase.setTreasure(none);

    Coordinates s(134,50); MazeCards check(s); check.setID("16"); check.setType(corner); check.setTreasure(none); check.setOrientation("SE"); check.src = {154, 335, 411, 411}; check.move = {check.coords.x, check.coords.y, 80, 80};
    Coordinates t(274,50); MazeCards check2(t); check2.setID("17"); check2.setType(corner); check2.setTreasure(none); check2.setOrientation("SE"); check2.src = {154, 335, 411, 411}; check2.move = {check.coords.x, check.coords.y, 80, 80};
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
        cout << "draw called" << endl;
    }

}