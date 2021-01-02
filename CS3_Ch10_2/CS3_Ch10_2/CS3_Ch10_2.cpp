/*
    CS3
    Ch 10.2
*/
#include "CDAccount.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Testing default constructor..." << endl;
    CDAccount testAcc;
    cout << "Initial balance: " << testAcc.getBalanceInitial() << endl;
    cout << "Interest rate: " << testAcc.getInterestRate() << endl;
    cout << "Term: " << testAcc.getTerm() << endl;
    cout << "Final balance: " << testAcc.getBalanceFinal() << endl;

    cout << endl << "Testing initializer list constructor..." << endl;
    CDAccount newAcc = { 1200, 34, 0.06, 24 };
    cout << "Initial balance: " << newAcc.getBalanceInitial() << endl;
    cout << "Interest rate: " << newAcc.getInterestRate() << endl;
    cout << "Term: " << newAcc.getTerm() << endl;
    cout << "Final balance: " << newAcc.getBalanceFinal() << endl;

    cout << endl << "Testing alternate initializer list constructor..." << endl;
    CDAccount altAcc = { 1200, 0.02, 12 };
    cout << "Initial balance: " << altAcc.getBalanceInitial() << endl;
    cout << "Interest rate: " << altAcc.getInterestRate() << endl;
    cout << "Term: " << altAcc.getTerm() << endl;
    cout << "Final balance: " << altAcc.getBalanceFinal() << endl;
}