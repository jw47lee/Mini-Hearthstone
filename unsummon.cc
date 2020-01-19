#include "unsummon.h"

using namespace std;

string unsummon_description = "Return target minion to its owner's hand";

Unsummon::Unsummon(): Spell("Unsummon", unsummon_description, 1){}

Unsummon::~Unsummon(){}
