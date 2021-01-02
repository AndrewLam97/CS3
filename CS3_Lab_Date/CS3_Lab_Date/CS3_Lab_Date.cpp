/*
    CS3
    Lab Date

    YY - the four digit year i.e. 2019

    Y - the 2 digit year i.e. 19

    M - The first 3 letters of the month i.e Jan

    MM - the full name of the month i.e. January

    m - the 2 digit month

    d- the 2 digit day
*/
#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
    Date current;
    //current.testDate();
    cout << current.getDate("MM-d-YY") << endl;
    cout << current.getDate("YY M d") << endl;
    cout << current.getDate("m/d") << endl;


    Date notCurrent(10, 2, 2010);
    //notCurrent.testDate();
    cout << notCurrent.getDate("MM d, YY");
    
}


