#pragma once
#include <string>
//#include "SalariedEmployee.h"
using namespace std;
class Doctor /*: public SalariedEmployee */
{
public:
	string specialty;
	double fee;

	string getName();
	string getSpecialty();
	double getFee();
	

	Doctor(string name,  string specialty, double fee);
};

