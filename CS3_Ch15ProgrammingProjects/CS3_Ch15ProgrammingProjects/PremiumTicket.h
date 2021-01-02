#pragma once
#include "BasicTicket.h"
class PremiumTicket :
	public BasicTicket
{
public:
	string seatNumber;

	double getPrice();
	string getSeat();

	PremiumTicket();
};

