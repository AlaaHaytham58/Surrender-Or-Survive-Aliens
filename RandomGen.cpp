#include "RandomGen.h"
#include "Game.h"


/*
* TA Modification
* Error#1 Game pointer was null and left unintialized
* sol : pass it to the constructor and assign it to 'gameptr' data member										//Solved
* 
* Error#2 EAptr and AAptr were instatiated as separate objects from that of the gamed			
* sol: make getters in the game class and intialize EAptr and AAptr with these getters				//Solved
*/
RandomGen::RandomGen(Game* xGameptr) // try to intialize all the class variables to default values 
{
	EAptr = xGameptr->getEarthsArmy();
	AAptr = xGameptr->getAliensArmy();
	gameptr = xGameptr;
	srand(time(NULL));
}

bool RandomGen::assignbasic(int N, int prob)
{
	NOofunits = N;
	probabilitytogen = prob;
	return true;
}

bool RandomGen::assignEartharmy(int pes, int pet, int peg, int minPower, int maxPower, int minHealth, int maxHealth, int minAttack, int maxAttack,int HealPer) {
	percentHS = pes;
	percentHT = pet;
	percentHG = peg;
	minhumanpower = minPower;
	maxhumanpower = maxPower;
	minhumanhealth = minHealth;
	maxhumanhealth = maxHealth;
	minhumanattackcap = minAttack;
	maxhumanattackcap = maxAttack;
	HealthPercentage = HealPer;
	return true;
}
bool RandomGen::assignAlienarmy(int pas, int pat, int pag, int minPower, int maxPower, int minHealth, int maxHealth, int minAttack, int maxAttack) {
	percentAS = pas;
	percentAM = pat;
	percentAD = pag;
	minalienpower = minPower;
	maxalienpower = maxPower;
	minalienhealth = minHealth;
	maxalienhealth = maxHealth;
	minalienattackcap = minAttack;
	maxalienattackcap = maxAttack;
	return true;
}

EarthSoldier* RandomGen::genESoldier()
{
	if (earthid < 999)
	{
		EarthSoldier* Es = new EarthSoldier();
		Es->setID(earthid);
		Es->setType("ES");
		Es->setPower(minhumanpower + (rand() % (maxhumanpower - minhumanpower + 1)));
		Es->setHealth(minhumanhealth + (rand() % (maxhumanhealth - minhumanhealth + 1)));
		Es->setAttackCapacity(minhumanattackcap + (rand() % (maxhumanattackcap - minhumanattackcap + 1)));
		earthid++;
		return Es;
	}
}

EarthTank* RandomGen::genETank()
{
	if (earthid < 999)
	{
		EarthTank* Et = new EarthTank();
		Et->setID(earthid);
		Et->setType("ET");
		Et->setPower(minhumanpower + (rand() % (maxhumanpower - minhumanpower + 1)));
		Et->setHealth(minhumanhealth + (rand() % (maxhumanhealth - minhumanhealth + 1)));
		Et->setAttackCapacity(minhumanattackcap + (rand() % (maxhumanattackcap - minhumanattackcap + 1)));
		earthid++;
		return Et;
	}
}

EarthGunnery* RandomGen::genEGunnery()
{
	if (earthid < 999)
	{
		EarthGunnery* Eg = new EarthGunnery();
		Eg->setID(earthid);
		Eg->setType("EG");
		Eg->setPower(minhumanpower + (rand() % (maxhumanpower - minhumanpower + 1)));
		Eg->setHealth(minhumanhealth + (rand() % (maxhumanhealth - minhumanhealth + 1)));
		Eg->setAttackCapacity(minhumanattackcap + (rand() % (maxhumanattackcap - minhumanattackcap + 1)));
		earthid++;
		return Eg;
	}
}

AlienSoldier* RandomGen::genASoldier()
{
	if (alienid < 2999)
	{
		AlienSoldier* As = new AlienSoldier();
		As->setID(alienid);
		As->setType("AS");
		As->setPower(minhumanpower + (rand() % (maxhumanpower - minhumanpower + 1)));
		As->setHealth(minhumanhealth + (rand() % (maxhumanhealth - minhumanhealth + 1)));
		As->setAttackCapacity(minhumanattackcap + (rand() % (maxhumanattackcap - minhumanattackcap + 1)));
		alienid++;
		return As;
	}
}

AlienMonster* RandomGen::genAMonester()
{
	if (alienid < 2999)
	{
		AlienMonster* Am = new AlienMonster();
		Am->setID(earthid);
		Am->setType("AM");
		Am->setPower(minhumanpower + (rand() % (maxhumanpower - minhumanpower + 1)));
		Am->setHealth(minhumanhealth + (rand() % (maxhumanhealth - minhumanhealth + 1)));
		Am->setAttackCapacity(minhumanattackcap + (rand() % (maxhumanattackcap - minhumanattackcap + 1)));
		alienid++;
		return Am;
	}
}

AlienDrone* RandomGen::genADrone()
{
	if (alienid < 2999)
	{
		AlienDrone* Ad = new AlienDrone();
		Ad->setID(earthid);
		Ad->setType("AD");
		Ad->setPower(minhumanpower + (rand() % (maxhumanpower - minhumanpower + 1)));
		Ad->setHealth(minhumanhealth + (rand() % (maxhumanhealth - minhumanhealth + 1)));
		Ad->setAttackCapacity(minhumanattackcap + (rand() % (maxhumanattackcap - minhumanattackcap + 1)));
		alienid++;
		return Ad;
	}
}

void RandomGen::generationearth()
{
	int A = 1 + (rand() % (100 - 1 + 1));
	if (A < probabilitytogen)
	{
		int* arr = new int[NOofunits];
		for (int i = 0; i < NOofunits; ++i)
		{
			arr[i] = rand() % 100 + 1;
		}
		for (int i = 0; i < NOofunits; i++) {
			if (arr[i] <= percentHS)
			{
				EAptr->Add_to_list(genESoldier());
			}
			else if (arr[i] <= (percentHS + percentHT)) 
			{
				EAptr->Add_to_list(genETank());
			}
			else 
			{
				int H = 0;
				EAptr->Add_to_list(genEGunnery());
			}
		}
	}
}

void RandomGen::generationalien()
{
	int A = 1 + (rand() % (100 - 1 + 1));

	if (A < probabilitytogen)
	{
		int* arr = new int[NOofunits]; // memory leak , this should be deleted at the end of the function
		for (int i = 0; i < NOofunits; ++i)
		{
			arr[i] = rand() % 100 + 1;
		}
		for (int i = 0; i < NOofunits; i++)
		{
			if (arr[i] <= percentAS)
			{
				AAptr->Add_to_list(genASoldier());
			}
			else if (arr[i] <= (percentAS + percentAM))
			{
				AAptr->Add_to_list(genAMonester());
			}
			else 
			{
				AAptr->Add_to_list(genADrone());
			}
		}
	}

}

void RandomGen::generation()
{
	generationearth();
	generationalien();
}

RandomGen::~RandomGen()
{
	delete EAptr;
	delete AAptr;
}

void RandomGen::randomAction()
{
	int x= 1 + (rand() % (100 - 1 + 1));
	//cout << x<<endl;
	if (x > 0 && x < 10)
	{
	    EarthSoldier*es;
		if (EAptr->pickupearthsolider(es)) { EAptr->Add_to_list(es); }
	}
	if (x >10 && x < 20)
	{

		EarthTank* et ;
		if (EAptr->pickupTank(et)) { gameptr->moveTokill(et); }
		//gameptr->moveTokill(et);

	}
	if (x > 20 && x < 30)
	{
		EarthGunnery* eg ;
		if (EAptr->pickupgunnery(eg))
		{
			eg->setHealth(eg->getHealth() / 2);
			if (eg->getHealth() == 0)
				gameptr->moveTokill(eg);
			else
				EAptr->Add_to_list(eg);
		}
	}
	if (x > 30 && x < 40)
	{
		for (int i = 0; i < 5; i++)
		{
			 
			AlienSoldier* as ;
			if (AAptr->pickupaliensolider(as)) {
				as->setHealth(rand() % (as->getHealth() - 1));
				gameptr->moveTotemp(as);
				AAptr->Add_to_list(as);
			}
		}
	}if (x > 40 && x < 50)
	{
		for (int i = 0; i < 5; i++)
		{
			AlienMonster* am;
			if (AAptr->pickmonster(am))
			{
				AAptr->addmonster(am);
			}// not sure 
		}
	}
	if (x >50 && x < 60)
	{
		for (int i = 0; i < 3; i++)
		{
			/*
				TA Modification
				Error : ad and ad2 were not intialized to nullptr
			*/
			AlienDrone* ad = nullptr;
			AlienDrone* ad2 = nullptr;
			
			AAptr->pickdrone(ad,ad2);
			
			if (ad && ad2) 
				gameptr->moveTokill(ad);
			if (ad && ad2)
			{
				gameptr->moveTokill(ad2);
			}
		}
	}
}