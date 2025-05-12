#pragma once 
#include"Game.h"
#include"Units.h"
#include"Eartharmy.h"
#include "RandomGen.h"
#include "AlienArmy.h"

Game::Game()
{
	eA = new Eartharmy();
	aA = new AlienArmy();
	Gen = new RandomGen(this);
}

void Game::moveTokill(Units* u)
{
	  K_L.enqueue(u);

}

void Game::moveTotemp(Units* u)
{
	T_L.enqueue(u);
}

Units* Game::Removefromotemp()
{
	Units* u;
	T_L.dequeue(u);
	return u;
}
bool Game::isEmptyTemp()
{
	return T_L.isEmpty();
}
bool Game::dequeuetemp(Units* u)
{
	return T_L.dequeue(u);
}
void Game::printGame(int time)
{
	cout << endl;
	cout << "Current Timestep " << time << endl;
	cout << "==============  Earth Army Alive Units =============" << endl;
	//count ES, "ES", ES list
	//count ET, "ET", ES list
	//count EG, "EG", ES list
	eA->print();

	cout << endl;
	cout << "==============  Alien Army Alive Units =============" << endl;
	//count AS, "AS", ES list
	//count AT, "AT", ES list
	//count AG, "AG", ES list
	aA->print();

	cout << endl;
	cout << "==============  Killed/Destructed Units =============" << endl;
	cout << K_L.getSize() << " units [ ";
	K_L.print();
	cout << " ]" << endl;
	cout << endl;
	cout << "==============  Unit Maintenance =============" << endl;
	cout << Tankuml.getSize() << "Tank Unit Maintenance list [ ";
	Tankuml.print();
	cout << endl;
	cout << soldieruml.getSize() << "Soldier Unit Maintenance list [ ";
	soldieruml.print();
	cout << endl;
}

void Game::TestFunc()
{
	int time = 0;
	inputfile();
	
	while (time <= 50)
	 {
		Gen->generation();
		/*Gen->randomAction();*/
		//earthattacking();
		alienattacking();
		printGame(time);
		//cout << time;
		time++;
	}
}

//void Game::es_UML(EarthSoldier* es)
//{
//	EarthSoldier* es = NULL;
//
//}

LinkedQueue<EarthTank*> Game::getUML_T()
{
	return Tankuml;
}


P_Queue<EarthSoldier*> Game::getUML_S() {
	return soldieruml;
}
void Game:: addtoUML_S(EarthSoldier* UMLS) {
	EarthSoldier* soldierptr = nullptr;
	int priority = 100 - UMLS->getHealth();
	soldierptr->setUML_s_time(getTimeStep());
	soldieruml.enqueue(UMLS, priority);
}
void Game::addtoUML_T(EarthTank*UMLT) {
	EarthTank* tankptr = nullptr;
	tankptr->setUML_t_time(getTimeStep());
	Tankuml.enqueue(UMLT);
}
EarthSoldier* Game::removeUML_S()
{
	EarthSoldier* soldierptr = new EarthSoldier;
	int importance=1;
	if (!soldieruml.isEmpty())
		soldieruml.dequeue(soldierptr);
	return soldierptr;
}
EarthTank* Game::removeUML_T()
{
	EarthTank* tankptr = new EarthTank;
	if (!Tankuml.isEmpty())
		Tankuml.dequeue(tankptr);
	return tankptr;
}

int Game::getTimeStep()
{
	return timestep;
}



bool Game::inputfile( )
{
	ifstream inputfile("7.txt");
	if (!inputfile.is_open()) {
		cout << "Error: Could not open file "  << endl;
		return false;
	}
	int N, prob;
	inputfile >> N >> prob;
	/*if (grandsim) {
		N = N * 10;
	}
	else {                        // not needed for now phase 2
		N = N;
	}*/
	if (!Gen->assignbasic(N, prob)) {
		return false;
	}
	int ES, ET, EG, EH, AS, AM, AD;
	int Powermin, Powermax, Healthmin, Healthmax, Attackmin, Attackmax,HealPer;
	inputfile >> ES >> ET >> EG;
	inputfile >> Powermin;
	inputfile.ignore();
	inputfile >> Powermax >> Healthmin;
	inputfile.ignore(); 
	inputfile >> Healthmax >> Attackmin;
    inputfile.ignore();
    inputfile>>Attackmax >>HealPer;
	if (!Gen->assignEartharmy(ES, ET, EG, Powermin, Powermax, Healthmin, Healthmax, Attackmin, Attackmax,HealPer))
	{
		return false;  // i removed earth heal as it will not be needed in phase1 for now and changed some names
	}
	inputfile >> AS >> AM >> AD;
	inputfile >> Powermin;
	inputfile.ignore();
	inputfile >> Powermax >> Healthmin;
	inputfile.ignore();
	inputfile>> Healthmax >> Attackmin >> Attackmax;
	if (!Gen->assignAlienarmy(AS, AM, AD, Powermin, Powermax, Healthmin, Healthmax, Attackmin, Attackmax)) {
		return false;
	}
	inputfile.close();
	return true;
}

//void Game::ATTACK_TANK()
//{
//	eA->attack_tank(this);
//}
//
//void Game::ATTACK_MONSTER()
//{
//	aA->attack_monster(this);
//}
void Game::outputfile()
{

	ofstream outputfile;
	string filename = "output_" + to_string(time(NULL)) + ".txt";
	string path = "Outputfiles/" + filename;
	outputfile.open(path, ios::out);
	outputfile << "Td\tID\tDf\tDd\tDb" << endl;
	while (!K_L.isEmpty()) {
		Units* mohamed;
		K_L.dequeue(mohamed);
		outputfile << mohamed->getTd() << "\t" << mohamed->getID() << "\t" << mohamed->getTa() - mohamed->getTj() << "\t" << mohamed->getTd() - mohamed->getTj() << endl;
	}
	//should inplement the rest of the output file like win lose draw etc..
	outputfile << "Battle Result: ";
	//if (//Condition)
	//{
	//	Code 1 should be here
	//}
	//else
	//{
	//	Code 2 should be here
	//}
	//Get this code :: Code 1
	outputfile << "Earth solider count: " << getEarthsArmy()->getES_list()->getSize() << endl;
	outputfile << "Earth tank count: " << getEarthsArmy()->getET_list()->getCapacity() << endl;
	outputfile << "Earth gunnery count: " << getEarthsArmy()->getEGList()->getSize() << endl;
	outputfile << "% destructed unit Earth soldier" <</*function returns number of dead Es divided by */ getEarthsArmy()->getES_list()->getSize() /*multiply by 100*/ << endl;
	outputfile << "% destructed unit Earth tank" <</*function returns number of dead Et divided by */ getEarthsArmy()->getET_list()->getCapacity() /*multiply by 100*/ << endl;
	outputfile << "% destructed unit Earth gunnery" <</*function returns number of dead Eg divided by */ getEarthsArmy()->getEGList()->getSize() /*multiply by 100*/ << endl;
	outputfile << "% destructed units" <<( (getEarthsArmy()->getES_list()->getSize() + getEarthsArmy()->getET_list()->getCapacity() + getEarthsArmy()->getEGList()->getSize()) /K_L.getSize() )* 100 << endl;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Get this code :: Code 2
	outputfile << "Alien solider count: " << getAliensArmy()->getAS_list()->getSize() << endl;
	outputfile << "Alien monster count: " << getAliensArmy()->Alien_Monster_Count() << endl;
	outputfile << "Alien drones count: " << getAliensArmy()->getAD_list()->getSize() << endl;
	outputfile << "% destructed unit Alien soldier" <</*function returns number of dead As divided by */ getAliensArmy()->getAS_list()->getSize() /*multiply by 100*/ << endl;
	outputfile << "% destructed unit Alien monster" <</*function returns number of dead Am divided by */ getAliensArmy()->Alien_Monster_Count()  /*multiply by 100*/ << endl;
	outputfile << "% destructed unit Alien drone" <</*function returns number of dead Ad divided by */ getAliensArmy()->getAD_list()->getSize() /*multiply by 100*/ << endl;
	outputfile << "% destructed units" << ((getAliensArmy()->getAS_list()->getSize() + getAliensArmy()->Alien_Monster_Count() + getAliensArmy()->getAD_list()->getSize()) / K_L.getSize()) * 100 << endl;

}

// void Game::earthattacking() {
//	/* EarthSoldier *es=eA->pickupearthsolider();
//	 AlienSoldier*as = aA->pickupaliensolider();*/
//	 EarthSoldier* es;
//	 AlienSoldier* as;
//	 if (es) {
//		 as->attack();
//	 }
//	 if (as) {
//		 es->attack(as);
//	 }
//	
//}
char Game::perferredmode() 
{
	cout << "Enter S for silent and I for interactive: ";
	cin >> mode_to_disp;
	return mode_to_disp;
}

 

 void Game::run()
 {
	 char pf = perferredmode();
	 if (pf == 'I')
	 {
		 int t = 0;
		 eA->earthattacking(this);
		 aA->Alienattacking(this);
		 printGame(t);
	 }
	 else
	 {
		 eA->earthattacking(this);
		 aA->Alienattacking(this);
		 outputfile();
	 }
 }

Game::~Game()
{

}