#pragma once
#include <stdlib.h>
#include <time.h>
using namespace std;
class Organism
{
public:
	int posX;
	int posY;

	int lifeStep;
	char drawChar;

	virtual void move();
};

