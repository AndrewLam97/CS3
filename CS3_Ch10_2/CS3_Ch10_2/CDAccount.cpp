#include "CDAccount.h"

double CDAccount::getBalanceInitial() {
	double balance = dollars;
	balance += cents / 100.0;
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
	double balance = dollars;
	balance += cents / 100.0;
	interest = balance * interestRate * (term / 12.0);
	balance += interest;
	return balance;
}

CDAccount::CDAccount() {
	this->dollars = 0;
	this->cents = 0;
	this->interestRate = 0;
	this->term = 0;
}

CDAccount::CDAccount(int dollars, int cents, double interestRate, int term) {
	this->dollars = dollars;
	this->cents = cents;
	this->interestRate = interestRate;
	this->term = term;
}

CDAccount::CDAccount(int dollars, double interestRate, int term) {
	this->dollars = dollars;
	this->cents = 0;
	this->interestRate = interestRate;
	this->term = term;
}