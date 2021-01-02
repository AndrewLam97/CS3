#pragma once
#include <iostream>
struct pNode {
	double coeff;
	double exp;
	pNode* next;
};

class Polynomial
{
public:
	pNode* head, * tail;
public:
	void insertBefore(double coeff, double exp); //inserts item at the beginning of the list
	void insertAfter(double coeff, double exp); //inserts item at the end of the list
	void print(); //prints list to console

	void operator += (const Polynomial& pp); //overloaded assignment operator for another list


	Polynomial(); //default constructor
	Polynomial(double x);
	Polynomial(double coeff, double exp);
};

