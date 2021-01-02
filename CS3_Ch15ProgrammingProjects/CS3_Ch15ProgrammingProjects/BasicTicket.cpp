#include "BasicTicket.h"

double BasicTicket::getPrice() {
	return ticketPrice;
}

BasicTicket::BasicTicket() {
	cout << "Enter Passenger Name: " << endl;
	cin >> this->passengerName;

	cout << "Enter Departure City: " << endl;
	cin >> this->departureCity;

	cout << "Enter Arrival City: " << endl;
	cin >> this->arrivalCity;

	cout << "Enter Flight Number: " << endl;
	cin >> this->flightNumber;

	cout << "Enter Ticket Price: " << endl;
	cin >> this->ticketPrice;
}