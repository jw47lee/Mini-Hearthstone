#ifndef _BOARD_H_
#define _BOARD_H_
#include "card.h"
#include "player.h"
#include <vector>
#include "ascii_graphics.h"

//typedef std::vector<std::string> card_template_t;

class Board{
	int minion_size = 0;
	bool player1_turn = true;

	std::shared_ptr<Player> p1;
	std::shared_ptr<Player> p2;
	public:
	Board(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2);
	std::string display();	
	void end_turn();
	std::string display_hand();
	void draw();
	void discard(int discard_i);
	std::string inspect(int i);
	void play(int play_i);
};


#endif
