/*
    CS3
    Ch9_2
*/
#include <iostream>
using namespace std;

void deleteRepeats(char*& arr, int& size);

int main()
{
    int size = 6;
    char *arr = new char[size];
    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'a';
    arr[3] = 'c';
    arr[4] = 'a';
    arr[5] = 'd';

    deleteRepeats(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
}

/*
PURPOSE: Creates and returns a new dynamic array where all repeated letters are deleted
PARAMETERS: character array pointer by reference and integer representing array size by reference
RETURN VALUES: none
*/
void deleteRepeats(char*& arr, int& size) {
    int i = 0,x, length = 0;
    int counter[26] = {};
    while (i < size) {
        x = arr[i] - 97;
        if (counter[x] == 0) {
            arr[length] = 'a' + x;
            counter[x] = 1;
            length++;
        }
        i++;
    }
    char* temp = new char[length];
    for (int j = 0; j < length; j++) {
        temp[j] = arr[j];
    }
    size = length;
    delete[] arr;
    arr = temp;
}