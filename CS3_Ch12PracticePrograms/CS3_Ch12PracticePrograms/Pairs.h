#pragma once
#include <iostream>
using namespace std;

class Pairs
{
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

