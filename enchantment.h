#ifndef _ENCHANTMENT_H_
#define _ENCHANTMENT_H_

#include "card.h"

class Enchantment : public Card {

	protected:
	Card *component;
	
	public:
	Enchantment(std::string name, std::string description, int cost);

};




#endif

