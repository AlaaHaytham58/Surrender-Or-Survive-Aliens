#pragma once
#include "string.h"
#include "string"
#include <iostream>
using namespace std;
class Game;

class Units
{
private:
	int ID;
	string Type;
	int Tj;
	int Health;
	int Power;
	int AttackCapacity;
	int Ta;
	int Td;

public:
	//////////////////////////Setter Functions//////////////////////////
	Units(int i, string t, int tj, int h, int p, int ac);
	Units();
	void setID(int i);
	void setType(string t);
	void setTj(int tj);
	void setTa(int ta);
	void setTd(int td);
	void setHealth(int h);
	void setPower(int p);
	void setAttackCapacity(int ac);
	//////////////////////////Getter Functions//////////////////////////
	int getID();
	string getType();
	int getTj();
	int getHealth();
	int getPower();
	int getTa();
	int getTd();
	int getAttackCapacity();
	int getPowerHealth();
	int getCombo();

	//////////////////////////Attack Function//////////////////////////

	virtual void attack(Game *)=0; // attack in all classes  //law shelt parameter of units am3el eh?

};

ostream& operator<<(std::ostream& O, Units* U);