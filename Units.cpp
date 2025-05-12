#include"Units.h"
#include"Game.h"
//////////////////////////Setter Functions//////////////////////////
void Units::setID(int i)
{
	ID = i;
}
void Units::setType(string t)
{
	Type = t;
}
void Units::setTj(int tj)
{
	if (tj < 0)
	{
		cout << "Invalid join time! Please re-enter: ";
	}
	else
		Tj = tj;
}

void Units::setTa(int ta)
{
	Ta = ta;
}

void Units::setTd(int td)
{
	Td = td;
}


void Units::setHealth(int h)
{
	if (h < 0 || h > 100)
	{
		cout << "Invalid health! Please re-enter: ";
	}
	else
		Health = h;
}
void Units::setPower(int p)
{
	if (p < 0)
	{
		cout << "Invalid power! Please re-enter: ";
	}
	else
		Power = p;
}
void Units::setAttackCapacity(int ac)
{
	if (ac < 0)
	{
		cout << "Invalid Attack Capacity! Please re-enter: ";
	}
	else
		AttackCapacity = ac;
}
//////////////////////////Getter Functions//////////////////////////
int Units::getID() { return ID; }
string Units::getType() { return Type; }
int Units::getTj() { return Tj; }
int Units::getHealth() { return Health; }
int Units::getPower() { return Power; }
int Units::getTa(){return Ta; }
int Units::getTd(){return Td;}
int Units::getAttackCapacity() { return AttackCapacity; }
int Units::getPowerHealth() { return (Power + Health); }
//////////////////////////Attack Function//////////////////////////

ostream& operator<<(std::ostream& O, Units *U) {
	O << U->getID();
	return O;
}

Units::Units(int i, string t, int tj, int h, int p, int ac=0)
{
	setID(i);
	setType(t);
	setTj(tj);
	setHealth(h);
	setPower(p);
	setAttackCapacity(ac);
}
Units::Units()
{
}

int Units::getCombo()
{
	return getPower() * getHealth();
	//return 1;
}

