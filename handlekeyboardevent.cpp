#include "handlekeyboardevent.hpp"
using namespace std;
void handlekeyboardevent(){}
void handlekeyboardevent::highlightElements(bool highlightActiveRight, bool highlightActiveLeft){

		if (highlightActiveRight){
			arrow_num+=1;
		}
		if (highlightActiveLeft)
		{
			arrow_num-=1;
		}
		if (arrow_num <0)
		{
			arrow_num+=12;
		}
		arrow_num = (arrow_num % 12);
}

int handlekeyboardevent::handleKeyboardEvent(SDL_Event& e, Board& board, Player* players[], Player** current) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_RIGHT:
            if (!(*current)->card_placed)
            {
				highlightActiveRight = true;
				highlightElements(true, false);
            }
            break;
			case SDLK_LEFT:
            if (!(*current)->card_placed)
            {
				highlightElements(false, true);
            }
            break;
			case SDLK_r:
				board.rotateUsable();
				break;
			case SDLK_v:
				tick = SDL_GetTicks();
                return tick;
				break;
			case SDLK_e:
                if((*current)->card_placed)
                {
                    (*current)->playermovement = false;
                    (*current)->card_placed = false; 
                    (*current)->player_turn_ended = false;
                    i++;
                    cout<<"player: "<< i%4<<endl;
                    (*current) = players[i%4];
                }
                break;
            case SDLK_RETURN:
                if (!(*current)->card_placed)
                {
                    board.insertMazeCard(arrow_num, players);
                    (*current)->card_placed = true;
                }
                break;
			case SDLK_a:
            if ((*current)->card_placed)
            {
				(*current)->move_player('a', &(board.grid), board.allmazecards);	
				break;
            }
			case SDLK_w:
            if ((*current)->card_placed)
            {
				(*current)->move_player('w', &(board.grid), board.allmazecards);
				break;
            }
			case SDLK_s:
            if ((*current)->card_placed)
            {
				(*current)->move_player('s', &(board.grid), board.allmazecards);
				break;
            }
			case SDLK_d:
            if ((*current)->card_placed)
            {
				(*current)->move_player('d', &(board.grid), board.allmazecards);
				break;
            }
            default:
                break;
        }
    }
    return 0;
}