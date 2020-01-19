#ifndef _SILENCE_H_
#define _SILENCE_H_

#include "enchantment.h"

class Silence : public Enchantment {

	public:
	Silence();
	card_template_t display() override;
};



#endif

