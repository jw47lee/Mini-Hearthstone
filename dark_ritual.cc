#include "dark_ritual.h"

using namespace std;

string dark_ritual_name = "Dark Ritual";
string dark_ritual_desc = "At the start of your turn, gain 1 magic";
int dark_ritual_cost = 0;
int dark_ritual_charge = 5;
int dark_ritual_action_cost = 1;

DarkRitual::DarkRitual()
	: Ritual(dark_ritual_name, dark_ritual_desc, dark_ritual_cost,
		dark_ritual_charge, dark_ritual_action_cost){}
