#pragma once
#include <string>
#include "Shape.h"

class Rectangle : public Shape
{
public:
	double length;
	double width;

	virtual double getArea();
	double getLength();
	double getWidth();
	
	Rectangle(int l, int w);
};

