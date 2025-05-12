#include "AlienSoldier.h"
#include"Node.h"
#include"Eartharmy.h"
#include"Game.h"
AlienSoldier::AlienSoldier(int i, string t, int tj, int h, int p, int ac) : Units(i, t, tj, h, p, ac)
{

}
AlienSoldier::AlienSoldier() :Units()
{

}
void AlienSoldier::attack(Game*Gptr)
{
	LinkedQueue<EarthSoldier*> *ES_list_temp = Gptr->getEarthsArmy()->getES_list();
	/*LinkedQueue<AlienSoldier*> originales = Gptr->getAliensArmy()->getAS_list();*/
	EarthSoldier* es;
	Eartharmy* tempES = Gptr->getEarthsArmy();
	for (int i = 0; this->getAttackCapacity(); i++) {
		if (Gptr->getEarthsArmy()->pickupearthsolider(es)) {
			if (es->getHealth() > 20) {
				double damage = es->getHealth() - (getPower() * getHealth() / 100) / sqrt(es->getHealth());
				es->setHealth(damage);
				int a = getAttackCapacity();
				setAttackCapacity(a--);
			}

			if (es->getHealth() <= 0) {
				Gptr->moveTokill(es);
			}
			else {
				//game->moveTotemp(as);
				ES_list_temp->enqueue(es);
			}
			while (Gptr->isEmptyTemp())
			{
					ES_list_temp->dequeue(es);
					/*originales->enqueue(es);*/
					tempES->Add_to_list(es);
				
			}
		}
	}
}

//void AlienSoldier::attack(Units *as)
//{
//	Game* aliensolider;
//	EarthSoldier* es;
//	Eartharmy* tempAS;
//	for (int i = 0;getAttackCapacity(); i++) {
//		if (aliensolider->getEarthsArmy()->pickupearthsolider(es)) {
//			double damage = es->getHealth() - (getPower() * getHealth() / 100) / sqrt(es->getHealth());
//			es->setHealth(damage);
//			int a = getAttackCapacity();
//			setAttackCapacity(a--);
//		}
//		if (es->getHealth() <= 0) {
//			aliensolider->moveTokill(es);
//		}
//		else {
//			aliensolider->moveTotemp(es);
//		}
//		while (!aliensolider->isEmptyTemp())
//		{
//			
//			aliensolider->dequeuetemp(es);
//			
//			tempAS->Add_to_list(es);   //make sure that this concept is true
//			
//		}
//	}
//}

ostream& operator<<(std::ostream& o, AlienSoldier* u)
{
	o << u->getID();
	return o;
}
