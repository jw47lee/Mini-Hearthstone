#include "potion_seller.h"

using namespace std;


string potion_seller_desc = "At the end of your turn. all your minions gain +0/+1.";

PotionSeller::PotionSeller()
	:TriggerMinion(1, 3, 0, "Potion Seller", potion_seller_desc, 2){};
