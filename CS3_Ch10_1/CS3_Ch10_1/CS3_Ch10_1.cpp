/*
    CS3
    Ch 10.1
*/
#include "CDAccount.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Testing default constructor..." << endl;
    CDAccount testAcc; 
    cout << "Initial balance: "<< testAcc.getBalanceInitial() << endl;
    cout << "Interest rate: " << testAcc.getInterestRate() << endl;
    cout << "Term: " << testAcc.getTerm() << endl;
    cout << "Final balance: " << testAcc.getBalanceFinal() << endl;

    cout << "Testing initializer list constructor..." << endl;
    CDAccount newAcc = { 1200, 0.6, 24 };
    cout << "Initial balance: " << newAcc.getBalanceInitial() << endl;
    cout << "Interest rate: " << newAcc.getInterestRate() << endl;
    cout << "Term: " << newAcc.getTerm() << endl;
    cout << "Final balance: " << newAcc.getBalanceFinal() << endl;
}

