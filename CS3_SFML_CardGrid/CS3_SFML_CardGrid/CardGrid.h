#pragma once
#include "PokerCard.h"
#include <SFML/Graphics.hpp>

class CardGrid
{
	PokerCard** arr = nullptr;
	int row;
	int col;
public:
	void drawGrid(sf::RenderWindow& window);

	CardGrid(int row, int col);
	~CardGrid();
};

