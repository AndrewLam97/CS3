#pragma once
#include "Card.h"
#include "Deck.h"

class CardHand
{
private:
	vector<Card> hand;

public:
	void addCard(Card card);
	void popCard();

	Card getCard(int pos);
	void setCard(int pos, Card card);

	int getSize();

	vector<Card> getHand();

	void printHand();
};

