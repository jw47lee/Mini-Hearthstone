#include "disenchant.h"

using namespace std;

string disenchant_description = "Destroy the top enchantment on target minion";

Disenchant::Disenchant(): Spell("Disenchant", disenchant_description, 1){}

Disenchant::~Disenchant(){}
