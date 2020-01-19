#include "card.h"

using namespace std;

Card::Card(string name, string description, int cost, string type)
	: name{name}, description{description}, cost{cost}, type{type}{}

Card::~Card(){};

string Card::get_name(){
	return this->name;
}

string Card::get_description(){
	return this->description;
}

int Card::get_cost(){
	return this->cost;
}

string Card::get_type(){
	return this->type;
}
