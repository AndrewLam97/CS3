#pragma once
#include <iostream>
struct Node {
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node *head, *tail;
public:
	void insertBefore(int val); //inserts item at the beginning of the list
	void insertAfter(int val); //inserts item at the end of the list
	void print(); //prints list to console

	void operator += (const LinkedList & ll); //overloaded assignment operator for another list
	void operator += (const int val); //overloaded assignment operator for a data value (int)

	friend std::ostream& operator << (std::ostream& out, const LinkedList& ll); //overloaded insertion operator

	LinkedList(); //default constructor
};

