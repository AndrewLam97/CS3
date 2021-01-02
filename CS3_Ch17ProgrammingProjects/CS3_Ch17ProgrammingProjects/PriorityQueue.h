#pragma once
template <typename ValueType>
class PriorityQueue {
public:

    PriorityQueue();


    PriorityQueue(std::initializer_list<std::pair<double, ValueType> > list);


    virtual ~PriorityQueue();


    void add(ValueType value, double priority);
};
