#ifndef _TRIGGER_MINION_
#define _TRIGGER_MINION_

#include "minion.h"

class TriggerMinion: public Minion{
	public:
	TriggerMinion(int att_pt, int def_pt, int act_pt,
			std::string name, std::string description, int cost);
	card_template_t display() override;
};

#endif
