/*
	CS3
	Ch9_3
*/
#include <iostream>
using namespace std;

/*
PURPOSE: Takes two pointers that point to dynamic arrays filled with ints. Returns a pointer to the combined array
PARAMETERS: two integer pointers and array size
RETURN VALUES: integer pointer to combined array
*/
int* arrayUnion(int* p1, int* p2, int size) {
	int(*p3) = new int[size*2];

	int i = 0;
	for (i; i < size; i++) {
		*(p3 + i) = *(p1 + i);
	}
	for (int j = 0; j < size; j++) {
		*(p3 + i) = *(p2 + j);
		i++;
	}
	return p3;
}

int main()
{
	const int size = 5;

	int arr1[size] = { 0,1,2,3,4 };
	int arr2[size] = { 9,7,90,3,2 };

	int(*p1)[size] = &arr1;
	int(*p2)[size] = &arr2;

	int* p3;
	p3 = arrayUnion(*p1, *p2, size);

	for (int i = 0; i < size * 2; i++)
	{
		std::cout << p3[i] << " ";
	}
	delete[] p3;
}

/*
TEST CASE
arr1 = { 0,1,2,3,4 }
arr2 = { 9,7,90,3,2 }

p3 = arrayUnion(*p1, *p2);
p3 = { 0 1 2 3 4 9 7 90 3 2 }
*/