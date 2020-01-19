#include "ability_minion.h"

using namespace std;

AbilityMinion::AbilityMinion(int att_pt, int def_pt, int act_pt,
	string name, string description, int cost, int ability_cost)
	: Minion(att_pt, def_pt, act_pt, name, description, cost),
		ability_cost{ability_cost}{}

card_template_t AbilityMinion::display(){
	return display_minion_activated_ability(get_name(),get_cost(), get_att_pt(),
		get_def_pt(), this->ability_cost, get_description());

}
