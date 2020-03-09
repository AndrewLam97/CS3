#pragma once
#include <cmath>
class CDAccount
{
private:
	int dollars;
	int cents;
	double interestRate;
	int term;
public:
	double getBalanceInitial();
	double getBalanceFinal();
	double getInterestRate();
	int getTerm();

	CDAccount();
	CDAccount(int dollars, int cents, double interestRate, int term);
	CDAccount(int dollars, double interestRate, int term);
};

