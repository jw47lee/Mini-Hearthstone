#include "trigger_minion.h"

using namespace std;

TriggerMinion::TriggerMinion(int att_pt, int def_pt, int act_pt,
	string name, string description, int cost)
	: Minion(att_pt, def_pt, act_pt, name,description, cost){}

card_template_t TriggerMinion::display(){
	return display_minion_triggered_ability(get_name(), get_cost(),
		get_att_pt(), get_def_pt(), get_description());
}
