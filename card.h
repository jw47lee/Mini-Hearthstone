#ifndef _CARD_H_
#define _CARD_H_
#include <vector>
#include <string>
#include "ascii_graphics.h"
#include "board.h"

class Card{
	std::string name;
	std::string description;
	int cost;
	std::string type;
	public:
		Card();
		Card(std::string name, std::string description,
			int cost, std::string type);
		virtual ~Card();
		std::string get_name();
		std::string get_description();
		int get_cost();
		std::string get_type();
		virtual card_template_t display() = 0;
//		virtual play(Board *board);


};




#endif
