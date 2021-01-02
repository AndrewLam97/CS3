#include "VectorDouble.h"
#include <iostream>
using namespace std;

VectorDouble::VectorDouble(){
    arr = new int[50];
    capacity = 50;
    current = 0;
}

VectorDouble::VectorDouble(int num) {
    arr = new int[num];
    capacity = num;
    current = 0;
}

VectorDouble::VectorDouble(const VectorDouble& vec) {
    arr = vec.arr;
    capacity = vec.capacity;
    current = vec.current;
}

void VectorDouble::push(int data)
{
    if (current == capacity) {
        int* temp = new int[2 * capacity];

        // copy old array elements to new array 
        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }

        // deleting previous array 
        delete[] arr;
        capacity *= 2;
        arr = temp;
    }

    // Insert data 
    arr[current] = data;
    current++;
}

// add element at index 
void VectorDouble::push(int data, int index)
{
    if (index == capacity)
        push(data);
    else
        arr[index] = data;
}

// extract element at index 
int VectorDouble::get(int index)
{
    if (index < current)
        return arr[index];
}

// delete last element 
void VectorDouble::pop()
{
    current--;
}

// get size of the vector 
int VectorDouble::size()
{
    return current;
}

// get capacity of the vector 
int VectorDouble::getcapacity()
{
    return capacity;
}

// print array elements 
void VectorDouble::print()
{
    for (int i = 0; i < current; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}