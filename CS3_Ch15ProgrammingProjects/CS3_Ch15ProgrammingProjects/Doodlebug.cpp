#include "Doodlebug.h"
bool Doodlebug::checkHunger() {
	if (hungerStep == 3) {
		return true;
	}
	else return false;
}


bool Doodlebug::checkBreed() {
	if (lifeStep == 8) {
		lifeStep = 0;
		return true;
	}
	else return false;
}

Doodlebug::Doodlebug() {
	lifeStep = 0;
	hungerStep = 0;
}