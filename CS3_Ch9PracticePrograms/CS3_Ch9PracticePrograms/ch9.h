#pragma once

/*
PURPOSE: increments the referenced integer by one
PARAMETERS: integer pointer
RETURN VALUES: none
*/
void addOne(int* ptrNum);

/*
PURPOSE: Create a dynamic array that can store numDoubles doubles and a loop that allows the user to fill
the dynamic array with values. Loops through the array and calculates then outputs the average.
Deletes the dynamic array before exiting.
PARAMETERS: none, takes value from console during runtime
RETURN VALUES: none, outputs result to console
*/
void arrayAvg();

/*
PURPOSE: Checks if cstr is a palindrome
PARAMETERS: char pointer to cstring
RETURN VALUES: boolean of palindrome status
*/
bool isPalindrome(char* cstr);