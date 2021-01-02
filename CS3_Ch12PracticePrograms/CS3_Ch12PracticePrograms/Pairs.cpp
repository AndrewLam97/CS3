#include "Pairs.h"

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