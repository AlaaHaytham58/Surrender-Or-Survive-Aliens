#pragma once
#include "Units.h"
class Game;

class EarthGunnery : public Units
{
public:
	EarthGunnery(int i, string t, int tj, int h, int p, int ac);
	EarthGunnery();
	void attack(Game*u);
	
};

ostream& operator<<(std::ostream& o, EarthGunnery*u);