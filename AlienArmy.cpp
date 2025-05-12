#include"AlienArmy.h"
#include<iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

AlienArmy::AlienArmy() 
{
    for (int i = 0; i < MAX; i++) {
        AM_list[i] = NULL;
    }
    Arrsize = 0;
    srand(time(NULL));
}
bool AlienArmy::Add_to_list(Units* A) {
    int k;
    int count = 0;
    if (A->getType() == "AS")
        AS_list.enqueue(dynamic_cast<AlienSoldier*> (A));
    else if (A->getType() == "AD")
        AD_list.enqueueFront(dynamic_cast<AlienDrone*>(A));
    else if (A->getType() == "AM") {
        addmonster(dynamic_cast<AlienMonster*>(A));
        Arrsize++;
    }
    return false;
}

int AlienArmy::Alien_Soldier_Count()
{
    return AS_list.getSize();
}

int AlienArmy::Alien_Monster_Count()
{
    return Arrsize;
}

void AlienArmy::attack_monster(Game* game_Monster)
{
    AlienMonster* Monster;
    this->peekmonster(Monster);
    if (Monster)
        Monster->attack(game_Monster);
}

bool AlienArmy::peekmonster(AlienMonster*& monster)
{
    int isEmpty = 1;
    for (int i = 0; i < MAX; i++)
    {
        if (AM_list[i] != NULL)
        {
            isEmpty = 0;
            break;
        }
    }
    if (isEmpty == 0 && Arrsize > 0)
    {
        int randI = rand() % Arrsize;
        monster = AM_list[randI];
        return true;
    }
    return false;
}

  bool AlienArmy::pickmonster(AlienMonster*& monster)
{
    //TA Modification
    //Error Checking on array size
    int isEmpty = 1;
    for (int i = 0; i < MAX; i++) {
        if (AM_list[i] != NULL) {
            isEmpty = 0;
            break;
        }
    }
    if (isEmpty == 0 && Arrsize > 0)
    {
        int randI = rand() % Arrsize;
        monster = AM_list[randI];
        AM_list[randI] = AM_list[--Arrsize];
        return true;
    }
    return false;
}
bool AlienArmy::addmonster(AlienMonster* monster)
{
    if (Arrsize == MAX)
        return false;

    AM_list[Arrsize++] = monster;
    //Arrsize++;
    return true;
}
LinkedQueue<AlienSoldier*>* AlienArmy::getAS_list()
{
    return AS_list;
}
doubleQueue & AlienArmy::getAD_list()
{
    return AD_list;
}
AlienMonster*  AlienArmy::getAM_list()
{
    for (int i = 0; i < Arrsize; i++)
        return AM_list[i];  

}
void AlienArmy::Alienattacking(Game*Gptr)
{
    AlienSoldier* as;
    if (AS_list.peek(as))
    {
        as->attack(Gptr);
    }
    AlienMonster* am;
    if (Arrsize > 0) {
        am->attack(Gptr);
    }
    AlienDrone* ad;
    if (AD_list.peek(ad)) {
        ad->attack(Gptr);
    }
    if (AD_list.peekback(ad) {
        ad->attack(Gptr);
    }
}
AlienArmy::~AlienArmy() {
    for (int i = 0; i < Arrsize; i++)
        delete AM_list[i];

}
bool AlienArmy::pickupaliensolider(AlienSoldier*& soldier) {
    return AS_list.dequeue(soldier);
}

bool AlienArmy::pickdrone(AlienDrone*& unit1, AlienDrone*& unit2)
{
    return AD_list.dequeueFront(unit1) && AD_list.dequeueBack(unit2);
}


void AlienArmy::print() {
    /* cout << "==============   Alien Army Alive Units  ================" << endl;*/
    int count = 0;
    cout << AS_list.getSize() << " AS [ ";
    AS_list.print();
    cout << " ]" << endl;
    cout << AD_list.getSize() << " AD [ ";
    AD_list.print();
    cout << " ]" << endl;
    cout << Arrsize << " AM [ ";
    for (int i = 0; i < Arrsize ; i++)
    {
        cout << AM_list[i]->getID()<<", ";
    }
    cout << " ]" << endl;
}