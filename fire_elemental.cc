#include "fire_elemental.h"

using namespace std;


string fire_elemental_desc = "Whenever an opponent's minion enters play, deal 1 damage to it.";

FireElemental::FireElemental()
	:TriggerMinion(2, 2, 0, "Fire Elemental", fire_elemental_desc, 2){};
