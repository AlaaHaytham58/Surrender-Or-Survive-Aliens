#include "AlienMonster.h"
#include"EarthTank.h"
#include"EarthSoldier.h"
#include"Eartharmy.h"
#include"AlienArmy.h"
#include"Game.h"

void AlienMonster::attack(Game* game_Monster)
{
    Eartharmy* eartharmy = game_Monster->getEarthsArmy();
    AlienArmy* alienarmy = game_Monster->getAliensArmy();
    EarthSoldier* earthSoldier;
    EarthTank* earthTank;

    // temp list for EarthTank and EarthSoldier //
    LinkedQueue<EarthTank*>* ET_list_Temp;
    LinkedQueue<EarthSoldier*>* ES_list_Temp;

    // peek one monster randomly //
    alienarmy->peekmonster(Monster);

    // calculating the damage //
    int damage_Tank = 0;
    int damage_ES = 0;

    // Monster picks number of tanks to attack, according to this monster attack capacity //
    for (int i = 0; i < Monster->getAttackCapacity(); i++)
    {
        if (eartharmy->pickupTank() || eartharmy->pickupearthsolider())
        {
            damage_Tank = calculateDamage(Monster, earthTank);
            damage_ES = calculateDamage(Monster, earthSoldier);

            earthTank->setHealth(earthTank->getHealth() - damage_Tank);
            earthSoldier->setHealth(earthSoldier->getHealth() - damage_ES);

            // check if the Earth Tank killed or still alive //
            if (earthTank->getHealth() <= 0)
            {
                game_Monster->moveTokill(earthTank);
            }
            else
            {
                ET_list_Temp->enqueue(earthTank);
            }
            while (!ET_list_Temp->isEmpty())
            {
                ET_list_Temp->dequeue(earthTank);
                eartharmy->Add_to_list(earthTank);
            }
            // check if the Earth Soldier killed or still alive //
            if (earthSoldier->getHealth() <= 0)
            {
                game_Monster->moveTokill(earthSoldier);
            }
            else
            {
                ES_list_Temp->enqueue(earthSoldier);
            }
            while (!ES_list_Temp->isEmpty())
            {
                ES_list_Temp->dequeue(earthSoldier);
                eartharmy->Add_to_list(earthSoldier);
            }
        }
    }
}

int AlienMonster::calculateDamage(Units* U1, Units* U2)
{
    int Damage = 0;
    Damage = (U1->getPower() * U1->getHealth() / 100) / sqrt(U2->getHealth());
    return Damage;
}

ostream& operator<<(std::ostream& o, AlienMonster* u)
{
    o << u->getID();
    return o;
}