/*
    Andrew Lam
    CS3
    Programming Project 6
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int> arr, int pos) {
    if (pos >= arr.size() - 1) {
        return arr[arr.size() - 1];
    }
    else {
        return min(jump(arr, pos + 1), jump(arr, pos + 2)) + arr[pos];
    }
    
}

int main()
{
    vector<int> arr = { 0, 3, 80, 6, 57, 10 };
    cout << jump(arr, 0);
}

