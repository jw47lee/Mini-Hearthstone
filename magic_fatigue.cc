#include "magic_fatigue.h"

MagicFatigue::MagicFatigue()
	:Enchantment("Magic Fatigue", "Enchanted minion's activated ability costs 2 more", 0){}

card_template_t MagicFatigue::display(){
	return display_enchantment(get_name(), get_cost(), get_description());
}
