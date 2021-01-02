// CS3_Ch11PracticePrograms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
class Money
{
public:
    friend bool operator <(const Money& amount1, const Money& amount2);
    friend bool operator <=(const Money& amount1, const Money& amount2);
    friend bool operator >(const Money& amount1, const Money& amount2);
    friend bool operator >=(const Money& amount1, const Money& amount2);
    Money percent(int percent_figure)const;
};

bool operator <(const Money& amount1, const Money& amount2) {

    return amount1.allCents(const Money& amount1, const Money& amount2) {

        return amount1.allCents > amount2.allCents
    }

    bool operator >=(const Money & amount1, const Money & amount2) {

        return (amount1.allCents > amount2.allCents || amount1.allCents == amount2.allCents)
    }

    Money Money::percent(int percent_figure)const {

        double desired_ratio = (all_cents / percent_figure);
        Money temp(desired_ratio / 100, desired_ratio % 100);
        return temp;
    }
}

class Pairs {

public:
    Pairs();
    Pairs(int first);
    Pairs(int first, int second);

    friend istream& operator >>(istream& ins, Pairs& second);
    friend ostream& operator <<(ostream& outs, const Pairs& second);

    friend Pairs operator+(const Pairs& first, const Pairs& second);
    friend Pairs operator-(const Pairs& first, const Pairs& second);
    friend Pairs operator*(const Pairs& first, int scalar);

private:
    int firstNum;
    int secondNum;
};

Pairs::Pairs() :firstNum(0), secondNum(0) {}
Pairs::Pairs(int first, int second) : firstNum(first), secondNum(second) {}

Pairs operator+(const Pairs& first, const Pairs& second) {
    return Pairs((first.firstNum + second.firstNum), (first.secondNum + second.secondNum));
}

Pairs operator-(const Pairs& first, const Pairs& second) {
    return Pairs(first.firstNum - second.firstNum, first.secondNum - second.secondNum);
}

Pairs operator*(const Pairs& first, int scalar) {

    return Pairs(scalar * first.firstNum, scalar * first.secondNum);
}

istream& operator >>(istream& ins, Pairs& second) {
    char ignored;
    ins >> ignored;
    ins >> second.firstNum;
    ins >> ignored;
    ins >> second.secondNum;
    ins >> ignored;

    return ins;
}

ostream& operator <<(ostream& outs, const Pairs& second) {
    outs << "(" << second.firstNum << "," << second.secondNum << ")";
    return outs;
}

int main() {
    Pairs p1;
    Pairs p2;

    bool again = true;


    while (again) {
        int q = 0;
        cout << "\nEnter the first pair as (1,2): ";
        cin >> p1;
        cout << "\nThe inserted pair is " << p1;
        cout << "\nEnter the the second one: ";
        cin >> p2;
        cout << "\nThe inserted pair is " << p2;

        cout << "\nThe sum result is " << p1 + p2;

        cout << "\nThe subtraction result is " << p1 - p2;

        cout << "\nEnter a constant to multiply p1 by it: ";

        cin >> q;
        cout << "\nThe multiplication result is " << p1 * q;

        cout << "\nTo play again, enter 1 otherwise enter 0, then press Enter: ";

        cin >> again;
    };

    return 0;
};

