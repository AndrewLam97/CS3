#include <iostream>
using namespace std;

int main()
{
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
