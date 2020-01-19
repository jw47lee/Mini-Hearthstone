#include "standstill.h"

using namespace std;

string standstill_name = "Standstill";
string standstill_desc = "Whenever a minion enters plat, destroy it";
int standstill_cost = 3;
int standstill_charge = 4;
int standstill_action_cost = 2;

Standstill::Standstill()
	: Ritual(standstill_name, standstill_desc, standstill_cost,
		standstill_charge, standstill_action_cost){}
