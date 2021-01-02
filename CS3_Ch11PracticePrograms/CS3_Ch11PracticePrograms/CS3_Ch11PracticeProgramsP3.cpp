#include <iostream>
using namespace std;
class Percent {
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

bool operator ==(const Percent& first, const Percent& second) {

	return first.val == second.val;
}

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

int main() {

	Percent p1;
	Percent p2;
	bool again = true;

	while (again) {

		int multiplier = 0;

		cout << endl << "Enter the first percent: ";
		cin >> p1;

		cout << endl <<"Enter the the second percent: ";
		cin >> p2;

		cout << endl << "Sum: " << p1 + p2;


		cout << endl << "Subtraction: " << p1 - p2;

		cout << endl << "Enter a multiplier: ";
		cin >> multiplier;

		cout << endl << "Multiplied: " << multiplier * p1;


		cout << endl << "Enter 1 to repeat, 0 otherwise";
		cin >> again;
	};

	return 0;
};