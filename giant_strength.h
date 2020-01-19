#ifndef _GIANT_STRENGTH_H_
#define _GIANT_STRENGTH_H_

#include "enchantment.h"

class GiantStrength : public Enchantment {

	public:
	GiantStrength();
	card_template_t display() override;
};



#endif

