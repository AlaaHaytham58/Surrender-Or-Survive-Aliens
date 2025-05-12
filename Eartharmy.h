#pragma once
#include "EarthSoldier.h"
#include "LinkedQueue.h"
#include "EarthTank.h"
#include "ArrayStack.h"
#include "EarthGunnery.h"
#include "P_Queue.h"
#include "Units.h"
#include"PQ_Node.h"
#include"Node.h"
#include <iostream>
class EarthHeal;
class unit;  // shawki byhbed
using namespace std;

class Eartharmy {
private:
    LinkedQueue<EarthSoldier*>*& ES_list;
    ArrayStack<EarthTank*> *&  ET_list;
    P_Queue<EarthGunnery*> *&  EG_list;
    ArrayStack<EarthHeal*> *&  EH_list; // all heal units stored as lifo

    

public:
    Eartharmy();
    bool Add_to_list(Units* E);
    void print();
    bool pickupearthsolider(EarthSoldier*&);
    bool pickupHeal(EarthHeal*& Heal);
    bool pickupgunnery(EarthGunnery*&);
    bool pickupTank(EarthTank*&);
    /*void attack_tank(Game* game_Tank);*/
    int Earth_Soldier_Count();
    P_Queue <EarthGunnery*>* getEGList();
    ArrayStack<EarthTank*>*  getET_list();
    LinkedQueue<EarthSoldier*>*  getES_list();
    ArrayStack<EarthHeal*>*getEH_list();
    void earthattacking(Game*);


   };

