#include "bone_golem.h"

using namespace std;


string bone_golem_desc = "Gain +1/+1 whenever a minion leaves play.";

BoneGolem::BoneGolem()
	:TriggerMinion(1, 3, 0, "Bone Golem", bone_golem_desc, 2){};
