#pragma once
class VectorDouble {
    int* arr;

    int capacity;

    int current;

public:
    VectorDouble();
    VectorDouble(int num);
    VectorDouble(const VectorDouble& vec);

    void push(int data);

    void push(int data, int index);

    int get(int index);

    void pop();

    int size();

    int getcapacity();

    void print();
};