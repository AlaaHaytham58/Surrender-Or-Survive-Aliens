#pragma once
#include"AlienSoldier.h"
#include"AlienMonster.h"
#include"AlienDrone.h"
#include"AlienSoldier.h"
#include"LinkedQueue.h"
#include "doubleQueue.h"
#include"units.h"
#include<iostream>
#include "AlienDrone.h"
#define MAX 400 

using namespace std;
class AlienArmy {
    LinkedQueue<AlienSoldier*> AS_list;  // aliensoldier *
    doubleQueue AD_list;
    AlienMonster* AM_list[MAX];
  
    int Arrsize = 0;

public:
    AlienArmy();
    bool Add_to_list(Units* A);
    bool pickupaliensolider(AlienSoldier*& soldier);
    bool pickdrone(AlienDrone*& unit1, AlienDrone*& unit2);
    bool pickmonster(AlienMonster*& monster);
    int Alien_Soldier_Count();
    int Alien_Monster_Count();
    void attack_monster(Game* game_Monster);
    bool peekmonster(AlienMonster*& monster);
    bool addmonster(AlienMonster* monster);
    LinkedQueue<AlienSoldier*>* getAS_list();
    doubleQueue& getAD_list();
    AlienMonster* getAM_list();
    void Alienattacking(Game*Gptr);
    ~AlienArmy();
    void print();

};