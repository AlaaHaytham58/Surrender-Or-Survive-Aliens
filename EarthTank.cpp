#include "EarthTank.h"
#include "AlienMonster.h"
#include "Game.h"
#include "Eartharmy.h"
#include "AlienArmy.h"
#include "EarthSoldier.h"
#include"AlienSoldier.h"

void EarthTank::attack(Game* game_Tank)
{
    AlienMonster* Monster;
    AlienSoldier* aliensoldier;
    LinkedQueue<AlienMonster*>* AM_list_Temp;
    LinkedQueue<AlienSoldier*>* AS_list_Temp;
    // calculating the damage //
    int damage_monster = 0;
    int damage_aliensoldier = 0;
    // tanks attack monsters as defult //

    if (this->Attack_Condition() == false)
    {
        // Tank picks number of monsters to attack, according to this tank attack capacity //
        for (int i = 0; i < this->getAttackCapacity(); i++)
        {
            if (alienarmy->pickmonster(Monster))
            {
                damage_monster = calculateDamage(this, Monster);
                Monster->setHealth(Monster->getHealth() - damage_monster);
                // check if the monster killed or still alive //
                if (Monster->getHealth() <= 0)
                {
                    game_Tank->moveTokill(Monster);
                }
                else
                {
                    AM_list_Temp->enqueue(Monster);
                }
                while (!AM_list_Temp->isEmpty())
                {
                    AM_list_Temp->dequeue(Monster);
                    alienarmy->Add_to_list(Monster);
                }
            }
        }
    }
    // tanks attacks alien monsters and alien soldiers //
    if (this->Attack_Condition() == true)
    {
        // Tank picks number of monsters and alien soldiers to attack, according to this tank attack capacity //
        for (int i = 0; i < this->getAttackCapacity(); i++)
        {
            if (alienarmy->pickmonster(Monster))
            {
                damage_monster = calculateDamage(this, Monster);
                Monster->setHealth(Monster->getHealth() - damage_monster);
                // check if the monster killed or still alive //
                if (Monster->getHealth() <= 0)
                {
                    game_Tank->moveTokill(Monster);
                }
                else
                {
                    AM_list_Temp->enqueue(Monster);
                }
                while (!AM_list_Temp->isEmpty())
                {
                    AM_list_Temp->dequeue(Monster);
                    alienarmy->Add_to_list(Monster);
                }
            }

            if (alienarmy->pickupaliensolider(aliensoldier))
            {
                damage_aliensoldier = calculateDamage(this, aliensoldier);
                aliensoldier->setHealth(aliensoldier->getHealth() - damage_aliensoldier);
                // Check if Alien Soldier is killed
                if (aliensoldier->getHealth() <= 0)
                {
                    game_Tank->moveTokill(aliensoldier);
                }
                else
                {
                    AS_list_Temp->enqueue(aliensoldier);
                }
                while (!AS_list_Temp->isEmpty())
                {
                    AS_list_Temp->dequeue(aliensoldier);
                    alienarmy->Add_to_list(aliensoldier);
                }
            }
        }
    }
}


ostream& operator<<(std::ostream& o, EarthTank* u)
{
    o << u->getID();
    return o;
}

int EarthTank::calculateDamage(Units* U1, Units* U2)
{
    int Damage = 0;
    Damage = (U1->getPower() * U1->getHealth() / 100) / sqrt(U2->getHealth());
    return Damage;
}

bool EarthTank::Attack_Condition()
{
    // Check if Earth soldiers count is less than 30% of alien soldiers count
    if (eartharmy->Earth_Soldier_Count() < (0.3 * alienarmy->Alien_Soldier_Count()))
    {
        return true;
    }
    // Check if Earth soldiers count reaches 80% of alien soldiers count
    if (eartharmy->Earth_Soldier_Count() >= (0.8 * alienarmy->Alien_Soldier_Count()))
    {
        return false;
    }
}