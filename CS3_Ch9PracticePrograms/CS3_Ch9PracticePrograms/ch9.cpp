#include "ch9.h"
#include <iostream>
#include <cstring>

/*
PURPOSE: increments the referenced integer by one
PARAMETERS: integer pointer
RETURN VALUES: none
*/
void addOne(int* ptrNum) {
    *ptrNum += 1;
}

/*
PURPOSE: Create a dynamic array that can store numDoubles doubles and a loop that allows the user to fill
the dynamic array with values. Loops through the array and calculates then outputs the average.
Deletes the dynamic array before exiting.
PARAMETERS: none, takes value from console during runtime
RETURN VALUES: none, outputs result to console
*/
void arrayAvg() {
    double numDoubles;
    std::cout << "Enter size of dynamic array: " << std::endl;
    std::cin >> numDoubles;

    double* doubleArr = new double[numDoubles];
    for (int i = 0; i < numDoubles; i++) {
        std::cout << "Enter a double: ";
        std::cin >> doubleArr[i];
        std::cout << std::endl;
    }

    std::cout << "Calculating average..." << std::endl;
    double total = 0;
    for (int i = 0; i < numDoubles; i++) {
        total += doubleArr[i];
    }
    std::cout << "Average of dynamic array: " << total / numDoubles << std::endl;
    delete[] doubleArr;
}

/*
PURPOSE: Checks if cstr is a palindrome
PARAMETERS: char pointer to cstring
RETURN VALUES: boolean of palindrome status
*/
bool isPalindrome(char* cstr) {
    char* front = cstr;
    char* back = cstr + strlen(cstr) - 1;
    while (front < back)
    {
        if (*front != *back) {
            return false;
        }
        front++;
        back--;
    }
    return true;
}