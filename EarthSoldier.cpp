#include "EarthSoldier.h"
#include"Game.h"
EarthSoldier::EarthSoldier(int i, string t, int tj, int h, int p, int ac) : Units(i, t, tj, h, p, ac)
{

}
EarthSoldier::EarthSoldier():Units()
{

}

void EarthSoldier::setUML_s_time(int time)
{
	UML_s_time = time;
}

int EarthSoldier::getUML_s_time()
{
	return UML_s_time;
}


void EarthSoldier::attack(Game* Gptr)
{
	LinkedQueue<AlienSoldier*> *AS_list_temp=Gptr->getAliensArmy()->getAS_list();
	/*LinkedQueue<AlienSoldier*> originalas = Gptr->getAliensArmy()->getAS_list();*/
	AlienSoldier* as;
	AlienArmy* tempAS = Gptr->getAliensArmy();
	for (int i = 0; this->getAttackCapacity(); i++) {
		if (Gptr->getAliensArmy()->pickupaliensolider(as)) {
			if (as->getHealth() > 20) {
				double damage = as->getHealth() - (getPower() * getHealth() / 100) / sqrt(as->getHealth());
				as->setHealth(damage);
				int a = getAttackCapacity();
				setAttackCapacity(a--);
			}

			if (as->getHealth() <= 0) {
				Gptr->moveTokill(as);
			}
			else {
				//game->moveTotemp(as);
				AS_list_temp->enqueue(as);
			}
			while (Gptr->isEmptyTemp())
			{
				AS_list_temp->dequeue(as);
				tempAS->Add_to_list(as);
				/*originalas->enqueue(as);*/

			}
		}
	}
}


ostream& operator<<(std::ostream& o, EarthSoldier* u)
{
	o << u->getID();
	return o;
}
