#include "Organism.h"
void Organism::move() {
	srand(time(NULL));
	int randnum = rand() % 4 + 1;
	switch (randnum) {
	case 1:
		posX += 1;
		break;
	case 2:
		posX -= 1;
		break;
	case 3:
		posY += 1;
		break;
	case 4:
		posY -= 1;
		break;
	}
}