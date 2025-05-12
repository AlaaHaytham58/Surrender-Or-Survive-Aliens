#include "EarthGunnery.h"
#include "Game.h"

EarthGunnery::EarthGunnery(int i, string t, int tj, int h, int p, int ac) : Units(i, t, tj, h, p, ac)
{

}
EarthGunnery::EarthGunnery() :Units()
{

}
void EarthGunnery::attack(Game* gm)
{
    P_Queue<EarthGunnery*>* eglist = gm->getEarthsArmy()->getEGList();
    doubleQueue Ad = gm->getAliensArmy()->getAD_list();
    AlienMonster* Am = gm->getAliensArmy()->getAM_list();

    doubleQueue AdTemp;
    AlienMonster* AMlistTemp[400];
    int countAM = 0;

    int aC = getAttackCapacity();
    int aCDrone = aC / 2 + aC % 2;
    int aCMonster = aC / 2;
    //int aCDrone = aC;
    //int aCMonster = aC;


    EarthGunnery* ego;
    AlienMonster* amo;
    bool conditionalzz = gm->getEarthsArmy()->pickupgunnery(ego);
    bool conditionalzm = gm->getAliensArmy()->pickmonster(amo);

    if (!conditionalzz)
    {
        return;
    }
    else if (conditionalzz && (gm->getAliensArmy()->getAD_list().getSize() == 0 || !conditionalzm))
    {
        return;
    }
    else if (conditionalzz && gm->getAliensArmy()->getAD_list().getSize() == 1 && !conditionalzm)
    {
        AlienDrone*& frntAD = new AlienDrone();
        Ad.dequeueFront(frntAD);
        frntAD->setHealth(frntAD->getHealth() - (getPower()));
        AdTemp.enqueue(frntAD);
    }
    else if (conditionalzz && gm->getAliensArmy()->getAD_list().getSize() > 1 && !conditionalzm)
    {
        for (int i = 0; i < aCDrone; i++)
        {
            AlienDrone*& frntAD = new AlienDrone();
            AlienDrone*& bckAD = new AlienDrone();
            Ad.dequeueFront(frntAD);
            Ad.dequeueBack(bckAD);

            frntAD->setHealth(frntAD->getHealth() - (ego->getPower()));
            bckAD->setHealth(bckAD->getHealth() - (ego->getPower()));

            AdTemp.enqueue(frntAD);
            AdTemp.enqueue(bckAD);
        }
    }
    else if (conditionalzz && gm->getAliensArmy()->getAD_list().getSize() == 0 && conditionalzm)
    {
        amo->setHealth(amo->getHealth() - ego->getPower());
        AMlistTemp[countAM] = amo;
        countAM++;
        while (gm->getAliensArmy()->pickmonster(amo))
        {
            amo->setHealth(amo->getHealth() - ego->getPower());
            AMlistTemp[countAM] = amo;
            countAM++;
        }
    }
    else if (conditionalzz && gm->getAliensArmy()->getAD_list().getSize() == 1 && conditionalzm)
    {
        AlienDrone*& frntAD = new AlienDrone();
        Ad.dequeueFront(frntAD);
        frntAD->setHealth(frntAD->getHealth() - (getPower()));
        AdTemp.enqueue(frntAD);

        amo->setHealth(amo->getHealth() - ego->getPower());
        AMlistTemp[countAM] = amo;
        countAM++;
        while (gm->getAliensArmy()->pickmonster(amo))
        {
            amo->setHealth(amo->getHealth() - ego->getPower());
            AMlistTemp[countAM] = amo;
            countAM++;
        }
    }
    else
    {
        for (int i = 0; i < aCDrone; i++)
        {
            AlienDrone*& frntAD = new AlienDrone();
            AlienDrone*& bckAD = new AlienDrone();
            Ad.dequeueFront(frntAD);
            Ad.dequeueBack(bckAD);

            frntAD->setHealth(frntAD->getHealth() - (ego->getPower()));
            bckAD->setHealth(bckAD->getHealth() - (ego->getPower()));

            AdTemp.enqueue(frntAD);
            AdTemp.enqueue(bckAD);
        }

        amo->setHealth(amo->getHealth() - ego->getPower());
        AMlistTemp[countAM] = amo;
        countAM++;
        while (gm->getAliensArmy()->pickmonster(amo))
        {
            amo->setHealth(amo->getHealth() - ego->getPower());
            AMlistTemp[countAM] = amo;
            countAM++;
        }
    }

    for (int i = countAM; i <= 0; i--)
    {
        AlienMonster* amTemp = AMlistTemp[i];
        gm->getAliensArmy()->Add_to_list(amTemp);
    }

    while (AdTemp.isEmpty())
    {
        AlienDrone*& frntAD = new AlienDrone();
        if (AdTemp.dequeueFront(frntAD))
            gm->getAliensArmy()->Add_to_list(frntAD);
    }
}

ostream& operator<<(std::ostream& o, EarthGunnery* u)
{
    o << u->getID();
    return o;
}
