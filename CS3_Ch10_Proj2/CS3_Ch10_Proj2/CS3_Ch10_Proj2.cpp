/*
    CS3
    Ch10 Proj 2
*/
#include "Record.h"
#include <iostream>
using namespace std;

int main()
{
    Record student;
    student.enterScores();
    student.calculateAvg();
    student.calculateLetter();
    student.printRecord();
}
