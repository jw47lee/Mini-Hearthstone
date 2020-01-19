#ifndef _ABILITY_MINION_
#define _ABILITY_MINION_

#include "minion.h"

class AbilityMinion: public Minion{
	int ability_cost;

	public:
		AbilityMinion(int att_pt, int def_pt, int act_pt,
			std::string name, std::string description, int cost, int ability_cost);
		card_template_t display() override;
};

#endif
