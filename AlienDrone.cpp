#include "AlienDrone.h"
#include"Game.h"
AlienDrone::AlienDrone(int i, string t, int tj, int h, int p, int ac) : Units(i, t, tj, h, p, ac)
{

}
AlienDrone::AlienDrone() :Units()
{

}
void AlienDrone::attack(Game* Gptr)
{
    int number = 0;
    EarthTank* tank;
    EarthGunnery* gunnery;
    if (Gptr->getAliensArmy()->getAD_list().getSize() == 1) 
    {
        return;
    }
    ArrayStack<EarthTank*> tank = Gptr->getEarthsArmy()->getET_list();
    P_Queue<EarthGunnery*>gun = Gptr->getEarthsArmy()->getEGList();
      
    P_Queue<EarthGunnery*>tempgun;
    ArrayStack<EarthTank*>temptank;

    for (int i = 0; getAttackCapacity(); i++)
    {
        AlienDrone* front = new AlienDrone();
        Gptr->getAliensArmy()->getAD_list().dequeueFront(front);
        AlienDrone* back = new AlienDrone();
        Gptr->getAliensArmy()->getAD_list().dequeueBack(back);
        if(number %2==0)
        {
            
            if(Gptr->getEarthsArmy()->getET_list().pop(tank))
            {
                double damage = tank->getHealth() - (getPower() * getHealth() / 100) / sqrt(tank->getHealth());
                tank->setHealth(damage);
                if (tank->getHealth() <= 0) {
                            Gptr->moveTokill(tank);
                  }
                else {
                     // Gptr->moveTotemp(tank);
                    temptank.push(tank);
                      }
                int a = getAttackCapacity();
                      setAttackCapacity(a--);
            }
        }
        else
        {
            if(Gptr->getEarthsArmy()->getEGList().dequeue(gunnery))
            {
                double damage = gunnery->getHealth() - (getPower() * getHealth() / 100) / sqrt(gunnery->getHealth());
                gunnery->setHealth(damage);
                if (tank->getHealth() <= 0) {
                    Gptr->moveTokill(gunnery);
                }
                else {
                    //Gptr->moveTotemp(gunnery);
                    tempgun.enqueue(gunnery);
                }
                int a = getAttackCapacity();
                setAttackCapacity(a--);
            }
        }
        number++;
    }

    while (!tempgun.isEmpty()) {
        EarthGunnery* eg = NULL;
        int Pri = eg->getCombo();
        tempgun.dequeue(eg);
        gun.enqueue(eg, Pri);
    }

    while (!temptank.isEmpty()) {
        EarthTank* et;
        temptank.pop(et);
        tank.push(et);
        //heal uml
    }

}
//void AlienDrone::attack()
//{						}

ostream& operator<<(std::ostream& o, AlienDrone* u)
{
    o << u->getID();
    return o;
}


//for (int i = 0; ad1->getAttackCapacity(), i++) {
//    if (ad1->getAttackCapacity() > 20) {
//        int damage = tank->getHealth() - (getPower() * getHealth() / 100) / sqrt(tank->getHealth());
//        int damage = gunnery->getHealth() - (getPower() * getHealth() / 100) / sqrt(gunnery->getHealth());
//        tank->setHealth(damage);
//        gunnery->setHealth(damage);
//        int a = ad1->getAttackCapacity();
//        ad1->setAttackCapacity(a--); //decrement health by one or two
//    }
//    if (tank->getHealth() <= 0) {
//        Drone1->moveTokill(tank);
//    }
//    else {
//        Drone1->moveTotemp(tank);
//    }
//    if (gunnery->getHealth() <= 0) {
//        Drone1->moveTokill(gunnery);
//    }
//    else {
//        Drone1->moveTotemp(gunnery);
//    }
//}

//for (int i = 0; ad1->getAttackCapacity(), i++) {
//    if (ad1->getAttackCapacity() > 20) {
//        int damage = tank->getHealth() - (getPower() * getHealth() / 100) / sqrt(tank->getHealth());
//        int damage = gunnery->getHealth() - (getPower() * getHealth() / 100) / sqrt(gunnery->getHealth());
//        tank->setHealth(damage);
//        gunnery->setHealth(damage);
//        int a = ad1->getAttackCapacity();
//        ad1->setAttackCapacity(a--); //decrement health by one or two
//    }
//    if (tank->getHealth() <= 0) {
//        Drone1->moveTokill(tank);
//    }
//    else {
//        Drone1->moveTotemp(tank);
//    }
//    if (gunnery->getHealth() <= 0) {
//        Drone1->moveTokill(gunnery);
//    }
//    else {
//        Drone1->moveTotemp(gunnery);
//    }
//}