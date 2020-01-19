#include "blizzard.h"

using namespace std;

string blizzard_description = "Deal 2 damage to all minions";

Blizzard::Blizzard(): Spell("Blizzard", blizzard_description, 3){}

Blizzard::~Blizzard(){}
