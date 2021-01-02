
/*
    Chapter 9 Self-Test Exercises
*/

#include <iostream>
using namespace std;

int main()
{

    int arraySize = 10;
    int* a;
    a = new int[arraySize];
    int i;
    for (i = 0; i < arraySize; i++)
        a[i] = i;
    while (*a < 9)
    {
        a++;
        cout << *a << " ";
    }
    cout << endl;
}

/*
    1. A pointer is a variable's memory address
    2. intPtr1 is an int pointer while intPtr2 is just an int
    3. int *p declares an int pointer while *p dereferences the p pointer
    4. 10 20
       20 20
       30 30
    5. 10 20
       20 20
       30 20
    6. delete p;
    7. typedef int * NumberPtr;
       NumberPtr my_point;
    8. new returns a pointer to the newly allocated space in the freestore for the argument variable type
    9. typedef char * CharArray
    10. cout << "Enter 10 integers: \n";
        for(int i = 0; i < 10; i++){ cin >> entry[i];}
    11. delete [] entry;
    12. 0 1 2 3 4 5 6 7 8 9
    13. 10 1 2 3 4 5 6 7 8 9
    14. 0 1 2 3 4 5 6 7 8 9
    15. 1 2 3 4 5 6 7 8 9
*/
=======
    int* p1, * p2;
    p1 = new int;
    p2 = new int;
    *p1 = 10;
    *p2 = 20;
    cout << *p1 << " " << *p2 << endl;
    p1 = p2;
    cout << *p1 << " " << *p2 << endl;
    *p1 = 30;
    cout << *p1 << " " << *p2 << endl;

    delete p1;
    delete p2;
}

/*
    1. A pointer is a memory address of a variable
    2. intPtr1 is an int pointer and intPtr2 is an int variable
    3. * declares a pointer. After pointer declaration, * is the dereference pointer
    4. 10 20
       20 20
       30 30

*/
