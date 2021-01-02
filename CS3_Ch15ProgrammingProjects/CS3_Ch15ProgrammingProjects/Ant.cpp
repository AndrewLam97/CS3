#include "Ant.h"
bool Ant::checkBreed() {
	if (lifeStep == 3) {
		lifeStep = 0;
		return true;
	}
		
	else return false;
}

Ant::Ant() {
	lifeStep = 0;
}