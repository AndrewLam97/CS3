#pragma once
#include <iostream>

namespace Chapter12 {
    class ResizeableIntArray
    {
    public:
        int* arr;
        int current;
        int capacity;

        ResizeableIntArray(int size);
        ResizeableIntArray(const ResizeableIntArray& arr1);

        void resize(int size);

        void setElement(int index, int val);

        void print();

        int getSize();

        friend std::ostream& operator << (std::ostream& out, ResizeableIntArray const arr2P);
    };
}

