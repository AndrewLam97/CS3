#pragma once
#include <string>
#include <iostream>
using namespace std;
class BasicTicket
{
public:
	string passengerName;
	string departureCity;
	string arrivalCity;
	int flightNumber;
	double ticketPrice;

	virtual double getPrice();
	BasicTicket();
};

