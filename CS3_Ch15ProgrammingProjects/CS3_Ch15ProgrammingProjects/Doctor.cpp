#include "Doctor.h"
/* string Doctor::getName() {
	return name;
} */

string Doctor::getSpecialty() {
	return specialty;
}

double Doctor::getFee() {
	return fee;
}

Doctor::Doctor(string name, string specialty, double fee) {
	//this->name = name;
	this->specialty = specialty;
	this->fee = fee;
}