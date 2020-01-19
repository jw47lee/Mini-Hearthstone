#include "banish.h"

using namespace std;

string banish_description = "Destroy target minion or ritual";

Banish::Banish(): Spell("Banish", banish_description, 2){}

Banish::~Banish(){}
