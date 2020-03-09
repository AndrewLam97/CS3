/*
    CS3
    Resize Array
*/
#include <iostream>
using namespace std;

int* resize(int* arr, int size);
void printArr(int* arr, int size);

int main()
{
    const int size = 5;
    int* p = new int[size]; //initialize base array

    for (int i = 0; i < size; i++) { //fill array with values
        *(p+i) = i;
    }

    cout << "Printing original array: " << endl;
    printArr(p, size);

    p = resize(p, size); //resize array

    cout << "Printing resized array: " << endl;
    printArr(p, size*size);

    delete[] p;

    return 0;
}
/*
PURPOSE: Resizes an array to it's original size squared, copies its values and fills the rest with zeros
PARAMETERS: integer array pointer and integer of array size
RETURN VALUES: integer array pointer to resized array
*/
int* resize(int* arr, int size) {
    int* p = new int[size * size];
    for (int i = 0; i < size; i++) { //copy original array's contents
        *(p + i) = arr[i];
    }
    for (int j = size; j < size * size; j++) { //fill rest of array with 0
        *(p + j) = 0;
    }
    delete[]arr;
    return p;
}

/*
PURPOSE: Prints array
PARAMETERS: integer array pointer and integer of array size
RETURN VALUES: none, outputs to console
*/
void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}