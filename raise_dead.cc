#include "raise_dead.h"

using namespace std;

string raise_dead_description = "Resurrect the top minion in your graveyard and set its defence to 1";

RaiseDead::RaiseDead(): Spell("Raise Dead", raise_dead_description, 1){}

RaiseDead::~RaiseDead(){}
