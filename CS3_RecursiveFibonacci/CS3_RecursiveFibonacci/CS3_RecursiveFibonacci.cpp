#include <iostream>
using namespace std;

int fibonacci(int x) {
    if (x == 0 || x == 1) {
        //cout << " " << x;
        return x;
    }
    else {
        //cout << " " << fibonacci(x - 1) + fibonacci(x - 2);
        return (fibonacci(x - 1) + fibonacci(x - 2));
    }
}

int main()
{
    int x;
    cout << "Enter number of terms desired: " << endl;
    cin >> x;
    for (int i = 0; i < x; i++) {
        cout << fibonacci(i) << " ";
    }
}

