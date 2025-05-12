//#pragma once
//#include "KilledList.h"
//
//
//
//KilledList::KilledList()
//{
//
//}
//bool KilledList::addToList(Units* E)
//{
//    if (E->getType() == "ES")
//        kL.enqueue(dynamic_cast<EarthSoldier*>(E));
//    else if (E->getType() == "ET")
//        kL.enqueue(dynamic_cast<EarthTank*>(E));
//    else if (E->getType() == "EG")
//        kL.enqueue(dynamic_cast<EarthGunnery*>(E));
//    else if (E->getType() == "AS")
//        kL.enqueue(dynamic_cast<AlienSoldier*>(E));
//    else if (E->getType() == "AD")
//        kL.enqueue(dynamic_cast<AlienDrone*>(E));
//    else if (E->getType() == "AM")
//        kL.enqueue(dynamic_cast<AlienMonster*>(E));
//    else
//        return false;
//    return true;
//}
//void KilledList::print()
//{
//    cout << kL.getSize() << "units [";
//    kL.print();
//    cout << "]" << endl;
//}
//int KilledList::getSize()
//{
//    return kL.getSize();
//}