#include "PremiumTicket.h"

double PremiumTicket::getPrice() { 
	return BasicTicket::getPrice() * 1.10;
}

string PremiumTicket::getSeat() {
	return seatNumber;
}

PremiumTicket::PremiumTicket() {
	cout << "Enter Seat Number: " << endl;
	cin >> this->seatNumber;
}