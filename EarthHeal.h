#pragma once
#include "Units.h"
class Game;
class Eartharmy;
class EarthSoldier;
class EarthTank;

class EarthHeal : public Units
{
public:
	EarthHeal(int i, string t, int tj, int h, int p, int ac);
	EarthHeal();
	void attack(Game*);

};

ostream& operator<<(std::ostream& o, EarthHeal* u);


