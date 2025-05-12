#pragma once
#include "AlienArmy.h"
#include"Eartharmy.h"
#include"Units.h"
#include<stdlib.h>
#include<cstdlib>
#include<time.h>
#include <iostream>
//#include "Game.h"
using namespace std;


class RandomGen
{
private:
	//pointer that points on class game
	Game *gameptr;
	//we need pointers to classes earth army and alienarmy
	Eartharmy* EAptr;
	AlienArmy* AAptr;
	// the prob and N given in the input file
	int probabilitytogen;
	int NOofunits;
	// inputs needed for human army to be generated 
	int minhumanhealth, maxhumanhealth;
	int minhumanpower, maxhumanpower;
	int minhumanattackcap, maxhumanattackcap;
	int percentHS, percentHT, percentHG;

	// inputs needed for alien army to be generated 
	int minalienhealth, maxalienhealth;
	int minalienpower, maxalienpower;
	int minalienattackcap, maxalienattackcap;
	int percentAS, percentAM, percentAD;

	// id to be incremented 
	int earthid = 1;
	int alienid = 2000;

public:
	RandomGen(Game*); //constructor
	void randomAction();
	// take parameters from input file function in class game and assign them here
	bool assignbasic(int N, int prob);
	bool assignEartharmy(int pes, int pet, int peg, int minPower, int maxPower, int minHealth, int maxHealth, int minAttack, int maxAttack,int HealPer);
	bool assignAlienarmy(int pas, int pat, int pag, int minPower, int maxPower, int minHealth, int maxHealth, int minAttack, int maxAttack);
	//these functions will generate two armies
	void generationearth();
	void generationalien();
	//these functions will generate Earth units
	EarthSoldier* genESoldier();
	EarthTank* genETank();
	EarthGunnery* genEGunnery();
	//these functions will generate alien units
	AlienSoldier* genASoldier();
	AlienMonster* genAMonester();
	AlienDrone* genADrone();

	//this function is the main function will generate all of the game
	void generation();

	~RandomGen();// destructor
};

