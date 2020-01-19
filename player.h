#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "card.h"
#include <vector>
#include <memory>
#include <cstdlib>
#include "board.h"

class Player{
	std::string name;
	int life = 20;
	int magic = 3;
	int MAX_HAND_SIZE = 5;
	int hand_size = 0;
	int deck_size;
	
	int player_num;
	
	bool is_testing;

//	std::vector<std::shared_ptr<Card>> hand;
//	std::vector<std::shared_ptr<Card>> deck;
//	std::shared_ptr<Card> ritual;
//	std::vector<std::shared_ptr<Card>> minion_on_board;
	int minion_num = 0;
	int MAX_MINION_NUM = 5;

	public:
	Player(std::string name, std::vector<std::shared_ptr<Card>> deck,
		 bool is_testing, int player_num);
	std::string get_name();
	int get_life();
	int get_magic();
	std::shared_ptr<Card> get_ritual();
//	void change_life(int change);
	void change_magic(int magic);
	void play_hand(int i);
	void draw();
	void discard(int i);

	card_template_t display();
	std::string display_hand();
	int get_minion_num();
	std::vector<std::shared_ptr<Card>> get_minion_on_board();
	std::string inspect(int i);
};



#endif
