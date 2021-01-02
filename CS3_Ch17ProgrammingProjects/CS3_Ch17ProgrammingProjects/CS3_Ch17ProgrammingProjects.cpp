#include <iostream>
#include <vector>
#include "GenericList.h"
using namespace std;

template <class T>
int countItemFrequency(vector<T>vec, T item) {

    int count = 0;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == item) {
            count++;
        }
    }

    return count;
}

int main()
{

}