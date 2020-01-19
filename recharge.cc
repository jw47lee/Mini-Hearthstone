#include "recharge.h"

using namespace std;

string recharge_description = "Your ritual gains 3 charges";

Recharge::Recharge(): Spell("Recharge", recharge_description, 1){}

Recharge::~Recharge(){}
