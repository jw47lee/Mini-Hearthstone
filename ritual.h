#ifndef _RITUAL_H_
#define _RITUAL_H_

#include "card.h"

class Ritual : public Card{
	
	int charge;
	int action_cost;

	public:
	Ritual(std::string name, std::string description, int cost, int charge, int action_cost);
	~Ritual();
	int get_charge();
	int get_action_cost();
	card_template_t display() override;
};

#endif
