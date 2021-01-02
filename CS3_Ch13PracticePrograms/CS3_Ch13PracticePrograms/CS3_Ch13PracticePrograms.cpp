#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string name;
	Node* link;
};
typedef Node* NodePtr;


int main()
{
	NodePtr listPtr = new Node;
	NodePtr tempPtr = new Node;
	listPtr->name = "Emily";
	tempPtr = new Node;
	tempPtr->name = "James";
	listPtr->link = tempPtr;
	tempPtr->link = new Node;
	tempPtr = tempPtr->link;
	tempPtr->name = "Joshua";
	tempPtr->link = new Node;
	tempPtr = tempPtr->link;
	tempPtr->name = "Joules";
	tempPtr->link = nullptr;

	NodePtr top = listPtr;
	NodePtr current = listPtr;
	do {
		std::cout << current->name << " ";
		current = current->link;
	} while (current != nullptr);

	NodePtr temp = listPtr;
	while (temp != nullptr) {
		temp = listPtr->link;
		delete listPtr;
		listPtr = temp;
	}

	return 0;
}

/*
Node::~Node()
{
	Node* ptr;

	for (ptr = top; top->link != nullptr; ptr = top)
	{
		top = top->link
			delete ptr;
	}
}
*/