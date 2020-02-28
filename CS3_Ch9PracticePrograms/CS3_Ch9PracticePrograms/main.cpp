#include <iostream>
#include <cstring>
#include "ch9.h"

int main()
{
    //Problem1
    std::cout << "Problem #1" << std::endl;
    int problem1 = 5;
    int* ptr1 = &problem1;
    std::cout << "Initial value: " << problem1 << std::endl;
    addOne(ptr1);
    std::cout << "Added value: " << problem1 << std::endl;

    //Problem 2
    std::cout << std::endl << "Problem #2" << std::endl;
    arrayAvg();

    //Problem 3
    std::cout << std::endl << "Problem #3" << std::endl;
    char s1[50] = "neveroddoreven";
    char s2[50] = "not a palindrome";
    std::cout << isPalindrome(s1) << std::endl; // true
    std::cout << isPalindrome(s2) << std::endl; // false
}

