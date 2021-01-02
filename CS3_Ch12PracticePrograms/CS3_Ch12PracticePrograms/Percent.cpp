#include "Percent.h"

bool operator <(const Percent& first, const Percent& second) {

	return first.val < second.val;
}

Percent operator +(const Percent& p1, const Percent& p2) {

	return Percent(p1.val + p2.val);
}

Percent operator -(const Percent& p1, const Percent& p2) {

	return Percent(p1.val - p2.val);
}

Percent operator *(int multiplier, const Percent& p) {

	return Percent(multiplier * p.val);
}

istream& operator >>(istream& ins, Percent& the_object) {
	char ignored;
	ins >> the_object.val;
	ins >> ignored;
	return ins;
}

ostream& operator <<(ostream& outs, const Percent& the_object) {

	return outs << the_object.val << "%";
}

Percent::Percent() :val(0) {};
Percent::Percent(int percent_val) :val(percent_val) {};