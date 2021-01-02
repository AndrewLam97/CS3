#pragma once
#include <iostream>
using namespace std;
class Percent
{
public:

	friend bool operator ==(const Percent& first, const Percent& second);
	friend bool operator <(const Percent& first, const Percent& second);
	Percent();
	Percent(int percent_val);
	friend istream& operator >>(istream& ins, Percent& the_object);
	friend ostream& operator <<(ostream& outs, const Percent& a_percent);

	friend Percent operator +(const Percent& p1, const Percent& p2);
	friend Percent operator -(const Percent& p1, const Percent& p2);
	friend Percent operator *(int mulitplier, const Percent& p);

private:
	int val;
};

