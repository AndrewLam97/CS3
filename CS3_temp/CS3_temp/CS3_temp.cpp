#include <iostream>
using namespace std;

int main() {
    int x = 15;
    int y = 9;

    int* p = &x;
    int* p1 = &y;

    cout << p << endl;
    cout << p1 << endl;
    cout << *p++ << endl;
    cout << p << endl;
    cout << *p << endl;
}