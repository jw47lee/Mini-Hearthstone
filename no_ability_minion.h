#ifndef _NO_ABILITY_MINION_H_
#define _NO_ABILITY_MINION_H_
#include "minion.h"
#include <string>


class NoAbilityMinion: public Minion{

	public:
	NoAbilityMinion(int att_pt, int def_pt, int act_pt,
			std::string name, std::string description, int cost);
	card_template_t display() override;	





};





#endif
