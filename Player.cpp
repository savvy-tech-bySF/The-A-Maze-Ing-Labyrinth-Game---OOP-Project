
#include "Player.hpp"
//#include "Coordinates.cpp"

Player::Player()
{
    
}
Player::Player(int ID, int startX, int startY) : playerID(ID)  {

}

void Player::setID(int ID) {
    playerID = ID;
}

int Player::getID() const {
    return playerID;
}
bool Player::validate_move(SDL_Rect* adjacentCard, char direction, std::vector<std::vector<Cards*>> *grid, std::vector<SDL_Rect> allmazecards, bool current)
{
    //for (const SDL_Rect& mazeCard : allmazecards) {
        //if (SDL_HasIntersection(adjacentCard, &mazeCard)) {
            // Logic for each type of maze card
            
            // Card c1
            if (adjacentCard->x == allmazecards[0].x && adjacentCard->y == allmazecards[0].y) {
                if ((direction == 'a' || direction == 'w') && !current) {
                    std::cout<<"Card c1"<<std::endl;
                    return true; // Valid move for c1
                }
                else if ((direction == 'd' || direction == 's') && current) {
                    std::cout<<"Card c1"<<std::endl;
                    return true; // Valid move for c1
                }
            }
            
            // Card c2
            if (adjacentCard->x == allmazecards[1].x && adjacentCard->y == allmazecards[1].y) {
                if ((direction == 'a' || direction == 's') && !current) {
                    std::cout<<"Card c2"<<std::endl;
                    return true; // Valid move for c2
                }
                else if ((direction == 'w' || direction == 'd') && current) {
                    std::cout<<"Card c2"<<std::endl;
                    return true; // Valid move for c1
                }
            }

            // Card c3
            if (adjacentCard->x == allmazecards[2].x && adjacentCard->y == allmazecards[2].y) {
                if ((direction == 'd' || direction == 'w') && !current) {
                    std::cout<<"Card c3"<<std::endl;
                    return true; // Valid move for c3
                }
                else if ((direction == 'a' || direction == 's') && current) {
                    std::cout<<"Card c3"<<std::endl;
                    return true; // Valid move for c3
                }
                else
                {
                    return false;
                }
            }

            // Card c4
            if (adjacentCard->x == allmazecards[3].x && adjacentCard->y == allmazecards[3].y) {
                if ((direction == 's' || direction == 'd' )&& !current) {
                    std::cout<<"Card c4"<<std::endl;
                    return true; // Valid move for c4
                }
                else if ((direction == 'a' || direction == 'w') && current) {
                    std::cout<<"Card c4"<<std::endl;
                    return true; // Valid move for c4
                }
            }

            // Card l1
            if (adjacentCard->x == allmazecards[4].x && adjacentCard->y == allmazecards[4].y) {
                if ((direction == 'a' || direction == 'd') && !current) {
                    std::cout<<"Card l1"<<std::endl;
                    return true; // Valid move for l1
                }
                else if ((direction == 'a' || direction == 'd') && current) {
                    std::cout<<"Card l1"<<std::endl;
                    return true; // Valid move for l1
                }
            }

            // Card l2
            if (adjacentCard->x == allmazecards[5].x && adjacentCard->y == allmazecards[5].y) {
                if ((direction == 'w' || direction == 's') && !current) {
                    std::cout<<"Card l2"<<std::endl;
                    return true; // Valid move for l2
                }
                else if ((direction == 'w' || direction == 's') && current) {
                    std::cout<<"Card l2"<<std::endl;
                    return true; // Valid move for l2
                }
            }

            // Card t1
            if (adjacentCard->x == allmazecards[6].x && adjacentCard->y == allmazecards[6].y) {
                if ((direction == 'd' || direction == 'w' || direction == 's' )&& !current) {
                    std::cout<<"Card t1"<<std::endl;
                    return true; // Valid move for t1
                }
                else if ((direction == 'a' || direction == 'w' || direction == 's') && current) {
                    std::cout<<"Card t1"<<std::endl;
                    return true; // Valid move for t1
                }
            }

            // Card t2
            if (adjacentCard->x == allmazecards[7].x && adjacentCard->y == allmazecards[7].y) {
                if ((direction == 'a' || direction == 's' || direction == 'd' )&& !current) {
                    std::cout<<"Card t2"<<std::endl;
                    return true; // Valid move for t2
                }
                else if ((direction == 'a' || direction == 'w' || direction == 'd') && current) {
                    std::cout<<"Card t2"<<std::endl;
                    return true; // Valid move for t2
                }
            }

            // Card t3
            if (adjacentCard->x == allmazecards[8].x && adjacentCard->y == allmazecards[8].y) {
                if ((direction == 'a' || direction == 'w' || direction == 'd') && !current) {
                    std::cout<<"Card t3"<<std::endl;
                    return true; // Valid move for t3
                }
                else if ((direction == 'a' || direction == 's' || direction == 'd') && current) {
                    std::cout<<"Card t3"<<std::endl;
                    return true; // Valid move for t3
                }
            }

            // Card t4
            if (adjacentCard->x == allmazecards[9].x && adjacentCard->y == allmazecards[9].y) {
                if ((direction == 'w' || direction == 's' || direction == 'a') && !current) {
                    std::cout<<"Card t4"<<std::endl;
                    return true; // Valid move for t4
                }
                else if ((direction == 'w' || direction == 's' || direction == 'd') && current) {
                    std::cout<<"Card t4"<<std::endl;
                    return true; // Valid move for t4
                }
            }

            // ...

        //}
    //}

    return false; // No matching card found for the adjacent move
}
// void Player::addTreasureCard(TreasureCards* Card){
//     cards.push(*Card);
// }
// bool Player::checkTreasure() {
//     //Todo: Implement logic to check for found treasure 
//     /*
//     !Return true if treasure found*/ 
// }

// TreasureCards* Player::getFound() {
//     return foundTreasure; 
// }
void Player::move_player(char direction, std::vector<std::vector<Cards*>> *grid, std::vector<SDL_Rect> allmazecards) {
    SDL_Rect* adjacentCard;
    SDL_Rect* current = (*grid)[row][col]->getsrc();
    switch (direction) {
        case 'w':
        if ((row-1)>=0)
            {
                adjacentCard = (*grid)[row-1][col]->getsrc();
            }
        if (validate_move(adjacentCard, direction, grid, allmazecards)&& validate_move(current, direction, grid, allmazecards, true))
        {
            move.y -= 85; // Decrease Y coordinate for upward movement
            row--;
        }
            break;
        case 's':
            if ((row+1)<=6)
            {
                adjacentCard = (*grid)[row+1][col]->getsrc();
            }
            if (validate_move(adjacentCard, direction, grid, allmazecards) && validate_move(current, direction, grid, allmazecards, true)){
                move.y += 85; // Increase Y coordinate for downward movement
                row++;
            }
            break;
        case 'a':
            if ((col-1)>=0)
            {
                adjacentCard = (*grid)[row][col-1]->getsrc();
            }
            if (validate_move(adjacentCard, direction, grid, allmazecards)&& validate_move(current, direction, grid, allmazecards, true)){
                move.x -= 85; // Decrease X coordinate for left movement
                col--;
            }
            break;
        case 'd':
            if ((col+1)<=6)
            {
                adjacentCard = (*grid)[row][col+1]->getsrc();
            }
            if (validate_move(adjacentCard, direction, grid, allmazecards)&& validate_move(current, direction, grid, allmazecards, true)){
                move.x += 85; // Increase X coordinate for right movement
                col++;
            }
            break;
        default:
            std::cout << "Invalid direction input!" << std::endl;
            break;
    }

    std::cout<<"move_player called"<<std::endl;
    std::cout<<"row "<<row<<" col "<<col<<std::endl;
}
void Player::addCard(Treasure t)
{
    toFind.push_back(t);
}

Treasure Player::getTop()
{
    return toFind[0];
}
void Player::pop()
{
    toFind.erase(toFind.begin());
}

void Player::place_maze_card() {
    //Todo: Implement logic to place the out of range maze card on the board along with changing it's orientation
}
void Player::DrawPlayer(SDL_Renderer* gRenderer, SDL_Texture* asset)
{
    SDL_RenderCopy(gRenderer, asset, &src, &move);
    //std::cout<<"draw called"<<std::endl;
}