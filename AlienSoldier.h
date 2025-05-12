#pragma once
#include "Units.h"
class Game;
class AlienSoldier : public Units
{
public:
	AlienSoldier(int i, string t, int tj, int h, int p, int ac);
	AlienSoldier();
	void attack(Game *es);
};
ostream& operator<<(std::ostream& o, AlienSoldier* u);
