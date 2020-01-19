#include "minion.h"

using namespace std;

Minion::Minion(int att_pt, int def_pt, int act_pt, string name,
		 string description, int cost)
	: Card(name, description, cost, "Minion"),
	att_pt{att_pt}, def_pt{def_pt}, act_pt{act_pt}{}

int Minion::get_att_pt(){
	return this->att_pt;
}

int Minion::get_def_pt(){
	return this->def_pt;
}

int Minion::get_act_pt(){
	return this->act_pt;
}
