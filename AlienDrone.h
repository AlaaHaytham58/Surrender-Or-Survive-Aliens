#pragma once
#include "Units.h"
class Game;
class AlienDrone : public Units
{
public:
	AlienDrone(int i, string t, int tj, int h, int p, int ac);
	AlienDrone();
	void attack(Game*);
};
ostream& operator<<(std::ostream& O, AlienDrone*  U);
