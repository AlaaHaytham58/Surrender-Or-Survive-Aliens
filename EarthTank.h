#pragma once
#include "Units.h"
//#include "AlienMonster.h"
//#include "Game.h"
//#include "Eartharmy.h"
//#include "AlienArmy.h"

class Game;
class AlienMonester;
class AlienSoldier;
class Earthsoldier;
class AlienArmy; 
class EarthArmy;

class EarthTank : public Units
{
private:
	Game* game_Tank;
	Eartharmy* eartharmy = game_Tank->getEarthsArmy();
	AlienArmy* alienarmy = game_Tank->getAliensArmy();
	AlienMonster* Monster;
	AlienSoldier* aliensoldier;

public:
	void attack(Game* game_Tank);
	int calculateDamage(Units* U1, Units* U2);
	bool Attack_Condition();
};

ostream& operator<<(std::ostream& o, EarthTank* u);