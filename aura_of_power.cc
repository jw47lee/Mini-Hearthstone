#include "aura_of_power.h"

using namespace std;

string aura_name = "Aura of Power";
string aura_desc = "Whenever a minion enters play under your control, it gains +1/+1";
int aura_cost = 1;
int aura_charge = 4;
int aura_action_cost = 1;

AuraOfPower::AuraOfPower()
	: Ritual(aura_name, aura_desc, aura_cost,
		aura_charge, aura_action_cost){}
