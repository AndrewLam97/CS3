#include <iostream>
using namespace std;

int* arrayUnion(int** arr1, int* arr2) {
    int arr3[10];
    int(*p3)[10] = &arr3;

    int i = 0;
    for (i; i < 5; i++){
        arr3[i] = *(*arr1 + i);
    }
    for (int j = 0; j < 5; j++){
        arr3[i] = *(arr2 + j);
        i++;
    }
    *arr1 = *p3;
    return *arr1;
}

int main()
{
    const int size = 5;

    int arr1[size] = { 1,5,6,88,9 };
    int arr2[size] = { 9,7,90,3,2 };

    int (*p1)[size] = &arr1;
    int (*p2)[size] = &arr2;
    
    int* p3 = new int[10];
    p3 = arrayUnion(p1, arr2);

    for (int i = 0; i < 10; i++)
    {
        cout << p3[i] << " ";
    }
}


