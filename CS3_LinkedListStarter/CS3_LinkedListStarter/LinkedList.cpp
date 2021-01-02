#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

void LinkedList::insertAfter(int val) {
	Node* temp = new Node;
	temp->data = val;
	temp->next = nullptr;

	if (head == nullptr) { //check if first node already exists
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;
	}
}

void LinkedList::insertBefore(int val) {
	Node* temp = new Node;
	temp->data = val;
	temp->next = head;

	if (head == nullptr) { //check if first node already exists
		head = temp;
		tail = temp;
	}
	else {
		head = temp;
	}
}

void LinkedList::print() {
	Node* current = head;
	do {
		std::cout << current->data << " ";
		current = current->next;
	} while (current != nullptr);
}

std::ostream& operator << (std::ostream& out, const LinkedList& ll) {
	Node* current = ll.head;
	do {
		std::cout << current->data << " ";
		current = current->next;
	} while (current != nullptr);

	return out;
}

void LinkedList::operator += (const LinkedList& ll) { //reassign list tail
	this->tail->next = ll.head;
	this->tail = ll.tail;
}

void LinkedList::operator += (const int val) {
	Node* temp = new Node;
	temp->data = val;
	temp->next = nullptr;

	if (head == nullptr) { //check if first node already exists
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;
	}
}
