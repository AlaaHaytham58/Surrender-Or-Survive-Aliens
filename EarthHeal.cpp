#include "EarthHeal.h"
#include"Game.h"
#include"EarthSoldier.h"
#include"EarthTank.h"
#include"Eartharmy.h"
EarthHeal::EarthHeal(int i, string t, int tj, int h, int p, int ac) : Units(i, t, tj, h, p, ac)
{

}
EarthHeal::EarthHeal() :Units()
{

}
void EarthHeal::attack(Game* Gptr)
{
	int beforehealthsoldier;
	int beforehealthtank;
	Eartharmy* EA = Gptr->getEarthsArmy();
	while (!EA->getEH_list()->isEmpty())
	{
		LinkedQueue<EarthTank*>ET_templist;
		LinkedQueue<EarthSoldier*>ES_templist;
		EarthHeal* Hu;
		EA->pickupHeal(Hu);

		if (!(Gptr->getUML_S().isEmpty()))
		{
			EarthSoldier* earthpointer = Gptr->removeUML_S();
			int time = (Gptr->getTimeStep()) - (earthpointer->getUML_s_time());
			if (time <= 10)
			{
				beforehealthsoldier = earthpointer->getHealth();
				int increaseinhealth = (getPower() * (getHealth() / 100) / (earthpointer->getHealth()) ^ 2);
				earthpointer->setHealth(increaseinhealth);

			}
			else
				Gptr->moveTokill(earthpointer);
			
			if (((earthpointer->getHealth() / beforehealthsoldier) * 100) > 20)
				Gptr->getEarthsArmy()->Add_to_list(earthpointer);
			else
				Gptr->moveTotemp(earthpointer);
		}
		else 
		{
			EarthTank* tankpointer = Gptr->removeUML_T();
			int time2= (Gptr->getTimeStep()) - (tankpointer->getUML_t_time());
			if (time2 <= 10)
			{
				beforehealthtank = tankpointer->getHealth();
				int increseinhealth = (getPower() * (getHealth() / 100)) / (tankpointer->getHealth()) ^ 2;
				tankpointer->setHealth(increseinhealth);

			}
			else 
				Gptr->moveTotemp(tankpointer);
			if (((tankpointer->getHealth() / beforehealthtank) * 100) > 20)
				Gptr->getEarthsArmy()->Add_to_list(tankpointer);
			else
				Gptr->moveTotemp(tankpointer);
		}
		while (!ES_templist.isEmpty())
		{
			EarthSoldier* es = nullptr;
			ES_templist.dequeue(es);
			Gptr->addtoUML_S(es);
		}
		while (!ET_templist.isEmpty())
		{
			EarthTank* et = nullptr;
			ET_templist.dequeue(et);
			Gptr->addtoUML_T(et);
		}




	}
}
//void EarthSoldier::attack(Game* Gptr)
//{
//	LinkedQueue<AlienSoldier*>* AS_list_temp;
//
//	AlienSoldier* as;
//	AlienArmy* tempAS;
//	for (int i = 0; this->getAttackCapacity(); i++) {
//		if (Gptr->getAliensArmy()->pickupaliensolider(as)) {
//			if (as->getHealth() > 20) {
//				double damage = as->getHealth() - (getPower() * getHealth() / 100) / sqrt(as->getHealth());
//				as->setHealth(damage);
//				/*int H = getHealth();
//				setHealth(H--);*/
//			}
//
//			if (as->getHealth() <= 0) {
//				Gptr->moveTokill(as);
//			}
//			else {
//				//game->moveTotemp(as);
//				AS_list_temp->enqueue(as);
//			}
//			while (Gptr->isEmptyTemp())
//			{
//				AS_list_temp->dequeue(as);
//
//				tempAS->Add_to_list(as);
//
//			}
//		}
//	}
//}


ostream& operator<<(std::ostream& o, EarthHeal* u)
{
	o << u->getID();
	return o;
}
