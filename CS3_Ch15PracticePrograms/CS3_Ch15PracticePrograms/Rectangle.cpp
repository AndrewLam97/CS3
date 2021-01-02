#include "Rectangle.h"
double Rectangle::getArea() {
	return length * width;
}

double Rectangle::getLength() {
	return length;
}

double Rectangle::getWidth() {
	return width;
}

Rectangle::Rectangle(int l, int w) {
	this->length = l;
	this->width = w;
}