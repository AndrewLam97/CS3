#include <iostream>
#include <string>
#include <vector>
//#include "SalariedEmployee.h"
//#include "Doctor.h"
#include "BasicTicket.h"
#include "PremiumTicket.h"
using namespace std;

int main()
{
	vector<BasicTicket*> tickets;
	BasicTicket* firstPassenger = new BasicTicket;
	tickets.push_back(firstPassenger);
	BasicTicket* secondPassenger = new BasicTicket;
	tickets.push_back(secondPassenger);
	PremiumTicket* thirdPassenger = new PremiumTicket;
	tickets.push_back(thirdPassenger);

	double ticketSum = 0;
	for (auto x : tickets) {
		ticketSum += x->getPrice();
	}
	cout << "Flight Sum: " << ticketSum;
}

