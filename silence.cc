#include "silence.h"

Silence::Silence()
	:Enchantment("Silence", "Enchanted minion cannot use abilities", 1){}

card_template_t Silence::display(){
	return display_enchantment(get_name(), get_cost(), get_description());

}

