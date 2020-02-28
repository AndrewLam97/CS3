#include <iostream>
#include <cstring>

void addOne(int* ptrNum);
void arrayAvg();
bool isPalindrome(char* cstr);

int main()
{
    int problem1 = 5;
    int* ptr1 = &problem1;
    std::cout << "Problem 1 initial value: " << problem1 << std::endl;
    addOne(ptr1);
    std::cout << "Problem 1 added value: " << problem1 << std::endl;

    arrayAvg();

    char s1[50] = "neveroddoreven";
    char s2[50] = "not a palindrome";
    std::cout << isPalindrome(s1) << std::endl; // true
    std::cout << isPalindrome(s2) << std::endl; // false
}

void addOne(int* ptrNum) {
    *ptrNum += 1;
}

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

bool isPalindrome(char* cstr){
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
