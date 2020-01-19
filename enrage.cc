#include "enrage.h"

Enrage::Enrage()
	:Enchantment("Enrage", "", 2){}

card_template_t Enrage::display(){
	return display_enchantment_attack_defence(get_name(), get_cost(),
		get_description(), "*2", "*2");
}
