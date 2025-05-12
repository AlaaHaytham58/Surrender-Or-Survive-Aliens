#pragma once
#include "Units.h"
class Game;
class EarthSoldier;
class EarthTank;
class Eartharmy;
class AlienArmy;
class AlienMonster : public Units
{
private:
	Game* game_Monster;
	AlienMonster* Monster;

public:
	void attack(Game* game_Monster);
	int calculateDamage(Units* U1, Units* U2);
};

ostream& operator<<(std::ostream& o, AlienMonster* u);