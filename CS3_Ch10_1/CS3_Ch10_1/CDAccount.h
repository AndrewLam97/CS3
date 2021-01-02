#pragma once
class CDAccount
{
private:
	double balance;
	double interestRate;
	int term; //months until maturity

public:
	double getBalanceInitial();
	double getBalanceFinal();
	double getInterestRate();
	int getTerm();

	CDAccount();
	CDAccount(double balance, double interestRate, int term);
};

