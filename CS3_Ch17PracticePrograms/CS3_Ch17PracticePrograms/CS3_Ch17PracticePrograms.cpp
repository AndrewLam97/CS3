#include <iostream>
#include <vector>
using namespace std;

class PartiallyFilledArray {
    int arr[8] = { 1,2,3,4,5,6,7,8 };
    int size = 8;
};

template <class PartiallyFilledArray>
bool find(PartiallyFilledArray PFarr, int val) {
    for (int i = 0; i < PFarr.size; i++) {
        if (PFarr.arr[i] == val)
            return i;
        else
            return -1;
    }
}

template<typename T> double floatingPointDivide(T lhs, T rhs) {
    return double result = lhs + rhs;
}

template<class ForwardIt, class Compare>
ForwardIt findLargestElement(ForwardIt first, ForwardIt last,
    Compare comp)
{
    if (first == last) return last;

    ForwardIt largest = first;
    ++first;
    for (; first != last; ++first) {
        if (comp(*largest, *first)) {
            largest = first;
        }
    }
    return largest;
}

int main()
{
    short first = 12.1;
    int second = 14;
    double res = floatingPointDivide(first, second);

    vector<int> vec = { 1,3,99,1231,2,3,4,7,9 };
    int max = findLargestElement(vec.begin(), vec.end());
}


