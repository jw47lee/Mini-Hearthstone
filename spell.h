#ifndef _SPELL_H_
#define _SPELL_H_

#include "card.h"

class Spell : public Card{
	public:
	Spell(std::string name, std::string description, int cost);
	~Spell();
	card_template_t display() override;
};

#endif
