#include "spell.h"

using namespace std;

Spell::Spell(string name, string description, int cost):
	Card(name, description, cost, "Spell"){}

Spell::~Spell(){}

card_template_t Spell::display(){
	return display_spell(get_name(), get_cost(), get_description());
}


