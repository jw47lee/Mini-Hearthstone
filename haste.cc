#include "haste.h"

Haste::Haste()
	:Enchantment("Haste", "Enchanted minion gains +1 action each turn", 2){}

card_template_t Haste::display(){
	return display_enchantment(get_name(), get_cost(), get_description());	
}

