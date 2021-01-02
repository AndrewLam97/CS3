#include "CardGrid.h"

void CardGrid::drawGrid(sf::RenderWindow& window) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			arr[i][j].draw(window);
		}
	}
}

CardGrid::CardGrid(int row, int col) {
	this->row = row;
	this->col = col;

	arr = new PokerCard* [row];
	for (int i = 0; i < row; ++i)
		arr[i] = new PokerCard[col];
	int yOff = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			arr[i][j].addOffset(300 * j, yOff);
		}
		yOff += 400;
	}
}

CardGrid::~CardGrid() {
	for (int i = 0; i < row; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}
