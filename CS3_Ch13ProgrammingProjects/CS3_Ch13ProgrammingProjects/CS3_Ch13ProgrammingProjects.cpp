#include <iostream>
#include "LinkedList.h"
#include "Polynomial.h"
#include "Suitor.h"
using namespace std;

Node* mergeLists(LinkedList& ll, LinkedList& ll2);

int main(){
	LinkedList ll;
	ll.insertAfter(1);
	ll.insertAfter(3);
	ll.insertAfter(5);
	ll.insertAfter(10);

	LinkedList ll2;
	ll2.insertAfter(2);
	ll2.insertAfter(4);
	ll2.insertAfter(5);
	ll2.insertAfter(8);
	ll2.insertAfter(12);
	ll2.insertAfter(14);


	std::cout << ll << endl;

	ll.reverse();
	ll.print();

	Node* merged = mergeLists(ll, ll2);

	
	Suitor suitor;
	int size, k = 3;
	cout << endl << "Enter number of suitors" << endl;
	cin >> size >> k;
	cout << suitor.solve(size, k);
}

Node* mergeLists(LinkedList& ll, LinkedList& ll2) {
	Node* pSort = nullptr;
	Node* p1 = ll.head;
	Node* p2 = ll2.head;
	Node* res = nullptr;

	if (p1 && p2) {
		if (p1->data <= p2->data) {
			pSort = p1;
			p1 = p1->next;
		}
		else {
			pSort = p2;
			p2 = p2->next;
		}
		res = pSort;
	}

	while (p1 != nullptr && p2 != nullptr) {
		if (p1->next == nullptr) {
			p1->next = p2;
			break;
		}
		if (p2->next == nullptr) {
			p2->next = p1;
			break;
		}
		if (p1->data <= p2->data) {
			pSort = p1;
			p1 = p1->next;
		}
		else {
			pSort = p2;
			p2 = p2->next;
		}
		
		
	}
	return res;
}