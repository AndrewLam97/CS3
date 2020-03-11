/*
    CS3
    Lab Date
*/
#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
    //Date test(2,24,2020);
    //test.testDate();

    Date current;
    current.testDate();
    cout << current.getDate("MM-DD-YY");
    
}

