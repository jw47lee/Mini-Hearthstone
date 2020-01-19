#ifndef _ENRAGE_H_
#define _ENRAGE_H_

#include "enchantment.h"

class Enrage : public Enchantment {

	public:
	Enrage();
	card_template_t display() override;
};



#endif

