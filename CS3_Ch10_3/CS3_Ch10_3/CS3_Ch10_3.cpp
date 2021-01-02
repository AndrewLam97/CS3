/*
    CS3
    Ch 10.3
*/
#include "ShowTicket.h"
#include <iostream>
using namespace std;

int main()
{
    ShowTicket first = { 'A', 1 };
    ShowTicket second = { 'B', 5 };
    ShowTicket third = { 'C', 12 };
    ShowTicket fourth = { 'H', 18 };

    first.getTicket();
    first.setSold();
    first.getTicket();

    cout << "Second status: " << second.getSold() << endl;
    second.getTicket();
    third.setSold();
    third.getTicket();

}

