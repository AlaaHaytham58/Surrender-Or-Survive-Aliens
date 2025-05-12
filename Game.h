#pragma once
//#include "Eartharmy.h"
//#include "AlienArmy.h"
//#include"Units.h"
#include <fstream>
#include <sstream>
//#include "KilledList.h"
#include"RandomGen.h"
//class RandomGen;

class Units;
class AlienArmy;
class Eartharmy;

class Game
{
private:
	RandomGen* Gen;
	LinkedQueue<Units *> K_L;
	LinkedQueue<Units*> T_L;
	Eartharmy* eA;
	AlienArmy* aA;
	LinkedQueue<EarthTank*> Tankuml;
	P_Queue<EarthSoldier*> soldieruml;
	int timestep;
	char mode_to_disp;
	 
public:

	Game();
	void moveTokill(Units *);
	void moveTotemp(Units*);
	Units* Removefromotemp();
	void printGame(int time);
	void TestFunc();
	bool isEmptyTemp();
	/*void ATTACK_TANK();
	void ATTACK_MONSTER();*/
	bool dequeuetemp(Units*u );
	Eartharmy* getEarthsArmy() { return eA ; }
	AlienArmy* getAliensArmy() { return aA ; }//why need new earth army
	
	//heal maintainance lists for soldiers and tanks
	LinkedQueue<EarthTank*> getUML_T();
	P_Queue<EarthSoldier*> getUML_S();
	void addtoUML_S(EarthSoldier*);
	void addtoUML_T(EarthTank*);
	EarthSoldier* removeUML_S();
	EarthTank* removeUML_T();
	
	char perferredmode(); // silent or active
	bool inputfile( );
	void outputfile();
	int getTimeStep();
	void run();
	~Game();

};

