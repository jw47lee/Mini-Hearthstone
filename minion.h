#ifndef _MINION_H_
#define _MINION_H_

#include "card.h"

class Minion : public Card{

	int att_pt;
	int def_pt;
	int act_pt;

	public:
    	Minion(int att_pt, int def_pt, int act_pt, 
    		std::string name, std::string description, int cost);
	int get_att_pt();
	int get_def_pt();
	int get_act_pt();
	


};

#endif
