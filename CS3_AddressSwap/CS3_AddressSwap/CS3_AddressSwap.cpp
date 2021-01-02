/*
	CS3
	Address Swap
*/
#include <iostream>
using namespace std;

void swapNumbers(int** firstInt, int** secondInt);

int main() {
	int* firstPointer, * secondPointer;
	firstPointer = new int;
	secondPointer = new int;

	*firstPointer = 1;
	*secondPointer = 2;

	cout << "First address: " << firstPointer << endl;
	cout << "First value: " << *firstPointer << endl;

	cout << "Second address: " << secondPointer << endl;
	cout << "Second value: " << *secondPointer << endl;

	swapNumbers(&firstPointer, &secondPointer);

	cout << "First address: " << firstPointer << endl;
	cout << "First value: " << *firstPointer << endl;

	cout << "Second address: " << secondPointer << endl;
	cout << "Second value: " << *secondPointer << endl;

	delete firstPointer;
	delete secondPointer;
}

/*
PURPOSE: swaps two integer pointers
PARAMETERS: two integer pointers to pointers
RETURN VALUES: none
*/
void swapNumbers(int** firstPointer, int** secondPointer) {
	int* temp = *firstPointer; 
	*firstPointer = *secondPointer;
	*secondPointer = temp;
	cout << endl;
}
