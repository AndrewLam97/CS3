#pragma once
#include "Organism.h"
class Doodlebug :
	public Organism
{
public:
	int hungerStep;
	bool checkHunger();
	bool checkBreed();

	Doodlebug();
};

