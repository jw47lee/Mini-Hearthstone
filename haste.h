#ifndef _HASTE_H_
#define _HASTE_H_

#include "enchantment.h"

class Haste : public Enchantment {

	public:
	Haste();
	card_template_t display() override;
};



#endif

