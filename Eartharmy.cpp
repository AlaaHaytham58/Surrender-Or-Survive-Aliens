#pragma once
#include"Eartharmy.h"
#include<iostream>
#include "EarthHeal.h"
using namespace std;
Eartharmy::Eartharmy()
{
   
}

bool Eartharmy::Add_to_list(Units* E) {
    if (E->getType() == "ES")
        ES_list->enqueue(dynamic_cast<EarthSoldier*>(E));
    else if (E->getType() == "ET")
        ET_list->push(dynamic_cast<EarthTank*>(E));
    else if (E->getType() == "EG")
        EG_list->enqueue(dynamic_cast<EarthGunnery*>(E), E->getCombo());
    else if (E->getType() == "EH")
        EH_list->push(dynamic_cast<EarthHeal*>(E));
    else return false;
}
void Eartharmy::print() {
    /* cout << "==============   Earth Army Alive Units  ================" << endl;*/
    cout << ES_list->getSize() << " ES [ ";
    ES_list->print();
    cout << "]" << endl;
    cout << ET_list->StackSize() << " ET [ ";
    ET_list->print();
    cout << "]" << endl;
    cout << EG_list->getSize() << "EG [ ";
    EG_list->print();
    cout << "]" << endl;
    cout << EH_list->StackSize() << "EH [ ";
    EH_list->print();
    cout << "]" << endl;
}
bool Eartharmy::pickupearthsolider(EarthSoldier*& unit) {
    
    return ES_list->dequeue(unit);
}
bool Eartharmy::pickupgunnery(EarthGunnery*& unit) {
    return EG_list->dequeue(unit);  
}
bool Eartharmy::pickupTank(EarthTank*& tank) {
    return ET_list->pop(tank);
}
bool Eartharmy::pickupHeal(EarthHeal*& Heal) {
    return EH_list->pop(Heal);
}
P_Queue<EarthGunnery*>& Eartharmy::getEGList()
{
    return this->EG_list;
}

//void Eartharmy::attack_tank(Game* game_Tank)
//{
//    EarthTank* tank = pickupTank();
//    if (tank)
//        tank->attack(game_Tank);
//}
int Eartharmy::Earth_Soldier_Count()
{
    return ES_list->getSize();
}

ArrayStack<EarthTank*>* Eartharmy::getET_list()
{
    return ET_list;
}

LinkedQueue<EarthSoldier*>* Eartharmy::getES_list()
{
    return ES_list;
}

ArrayStack<EarthHeal*>* Eartharmy::getEH_list()
{
    return EH_list;
}


void Eartharmy::earthattacking(Game * Gptr)
{
        	 EarthSoldier* es=NULL;
        	 if (ES_list->peek(es)) {
        		 es->attack(Gptr);
        	 }
             EarthTank* et = NULL;
             if (ET_list->peek(et))
             {
                 et->attack(Gptr);
             }
             EarthGunnery* eg = NULL;
             if (EG_list->peek(eg))
             {
                 eg->attack(Gptr);
             }
}

