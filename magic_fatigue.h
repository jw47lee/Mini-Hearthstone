#ifndef _MAGIC_FATIGUE_H_
#define _MAGIC_FATIGUE_H_

#include "enchantment.h"

class MagicFatigue : public Enchantment {

	public:
	MagicFatigue();
	card_template_t display() override;
};



#endif

