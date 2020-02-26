
#include <iostream>
using namespace std;

int main() {
    int* pArr;
    pArr = new int[5];
    //for(int i = 0; i < 5; i++)
    //{
    //  pArr[i] = i;
    //}

    for (int i = 0; i < 5; i++)
    {
        *(pArr + i) = i;
    }

    for (int j = 0; j < 5; j++)
    {
        cout << pArr[j] << " ";
    }
}