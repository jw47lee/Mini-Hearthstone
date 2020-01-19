#include "ritual.h"

using namespace std;

Ritual::Ritual(string name, string description, int cost, int charge, int action_cost):
	Card(name, description, cost, "Ritual"), charge{charge}, action_cost{action_cost}{}

Ritual::~Ritual(){}


int Ritual::get_charge(){
	return charge;
};

int Ritual::get_action_cost(){
	return action_cost;
};

card_template_t Ritual::display(){
	return display_ritual(get_name(), get_cost(), get_action_cost(),
		get_description(), get_charge());
}
