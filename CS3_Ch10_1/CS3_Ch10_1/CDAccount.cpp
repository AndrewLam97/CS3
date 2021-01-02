#include "CDAccount.h"

double CDAccount::getBalanceInitial() {
	return balance;
}

double CDAccount::getInterestRate() {
	return interestRate;
}

int CDAccount::getTerm() {
	return term;
}

double CDAccount::getBalanceFinal() {
	double rateFraction, interest;
	rateFraction = interestRate / 100.0;
	interest = balance * rateFraction * (term / 12.0);
	balance += interest;
	return balance;
}

CDAccount::CDAccount(){
	this->balance = 0;
	this->interestRate = 0;
	this->term = 0;
}

CDAccount::CDAccount(double balance, double interestRate, int term) {
	this->balance = balance;
	this->interestRate = interestRate;
	this->term = term;
}
