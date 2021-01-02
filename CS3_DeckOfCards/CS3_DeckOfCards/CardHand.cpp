#include "CardHand.h"

void CardHand::addCard(Card card) {
	hand.push_back(card);
}
void CardHand::popCard() {
	hand.pop_back();
}

Card CardHand::getCard(int pos) {
	if (pos < hand.size()) {
		return hand[pos];
	}
	else return hand[0];
}

void CardHand::setCard(int pos, Card card) {
	hand[pos] = card;
}

int CardHand::getSize() {
	return hand.size();
}

vector<Card> CardHand::getHand() {
	return hand;
}

void CardHand::printHand() {
	cout << endl << "Printing hand..." << endl;
	for (auto it : hand) {
		cout << it.getValue() << " of " << it.getSuit() << endl;
	}
	cout << endl;
}