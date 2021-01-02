#pragma once
#include <string>
using namespace std;
class Shape
{
public:
	Shape();
	Shape(string name);
	string getName();
	void setName(string newName);
	virtual double getArea() = 0;
private:
	string name;
};

