#include "ShowTicket.h"
#include <iostream>
using namespace std;

bool ShowTicket::getSold() {
	return sold;
}

void ShowTicket::setSold() {
	this->sold = true;
}

void ShowTicket::getTicket() {
	cout << "Seat: " << row << seat << ", sold: " << sold << endl;
}

ShowTicket::ShowTicket(char row, int seat) {
	this->row = row;
	this->seat = seat;
	sold = false;
}
