#include "Polynomial.h"

Polynomial::Polynomial() {
	head = nullptr;
	tail = nullptr;
}

Polynomial::Polynomial(double x) {
	head = tail;
	head->coeff = x;
}

Polynomial::Polynomial(double coeff, double exp) {
	head = tail;
	head->coeff = coeff;
	head->exp = exp;
}

void Polynomial::insertAfter(double coeff, double exp) {
	pNode* temp = new pNode;
	temp->coeff = coeff;
	temp->exp = exp;
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

void Polynomial::insertBefore(double coeff, double exp) {
	pNode* temp = new pNode;
	temp->coeff = coeff;
	temp->exp = exp;
	temp->next = head;

	if (head == nullptr) { //check if first node already exists
		head = temp;
		tail = temp;
	}
	else {
		head = temp;
	}
}

void Polynomial::print() {
	pNode* current = head;
	do {
		std::cout << current->coeff << "^" << current->exp << " ";
		current = current->next;
	} while (current != nullptr);
}

std::ostream& operator << (std::ostream& out, const Polynomial& ll) {
	pNode* current = ll.head;
	do {
		std::cout << current->coeff << "^" << current->exp << " ";
		current = current->next;
	} while (current != nullptr);

	return out;
}

void Polynomial::operator += (const Polynomial& pp) { //reassign list tail
	this->tail->next = pp.head;
	this->tail = pp.tail;
}