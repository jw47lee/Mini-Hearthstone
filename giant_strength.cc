#include "giant_strength.h"

GiantStrength::GiantStrength()
	:Enchantment("Giant Strength", "", 1){}
card_template_t GiantStrength::display(){
	return display_enchantment_attack_defence(get_name(), get_cost(),
		get_description(), "+2", "+2");
}
