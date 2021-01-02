#include "ResizeableIntArray.h"
#include <iostream>
using namespace std;

ResizeableIntArray::ResizeableIntArray(int size) {
    arr = new int[size];
    capacity = size;
    current = 0;
}

ResizeableIntArray::ResizeableIntArray(const ResizeableIntArray& arr1) {
    arr = arr1.arr;
    capacity = arr1.capacity;
    current = arr1.current;
}

void ResizeableIntArray::resize(int size) {
    int* temp = new int[size];
    if (size > capacity) {
        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }
    }
}

void ResizeableIntArray::setElement(int index, int val) {
    arr[index] = val;
}

int ResizeableIntArray::getSize() {
    return capacity;
}

void ResizeableIntArray::print() {
    cout << "[";
    for (int i = 0; i < current; i++) {
        cout << arr[i] << " ";
    }

    cout << "]" << endl;
}

ostream& operator << (ostream& out, ResizeableIntArray const arr2P){
    out << "[";
    for (int i = 0; i < arr2P.capacity; i++) {
        out << arr2P.arr[i];
    }
    return out;
}