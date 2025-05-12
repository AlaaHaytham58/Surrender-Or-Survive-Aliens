#pragma once
#include "Units.h"
class Game;
class EarthSoldier : public Units
{
private:
	int UML_s_time;
	

public:
	EarthSoldier(int i, string t, int tj, int h, int p, int ac);
	EarthSoldier();
	void setUML_s_time(int time);
	int getUML_s_time();
	void attack(Game*);
};

ostream& operator<<(std::ostream& o, EarthSoldier* u);