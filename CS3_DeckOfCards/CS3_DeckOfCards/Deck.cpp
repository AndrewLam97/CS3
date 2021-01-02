#include "Deck.h"
#include "Card.h"


bool Deck::inDeck(int row, int col)
{
	return arr[row][col] == 'X' ? false : true;
}

bool Deck::deckFull()
{
	return uniqueCards == DECK_SIZE ? 1 : 0;
}

void Deck::setDeck(int row, int col)
{
	arr[row][col] = 'Y';
	uniqueCards++;
}

Card Deck::getCardAt(int index)
{
	return deck[index];
}

Card Deck::nextCard()
{
	return deck[currentCard++];
}

void Deck::dealCards()
{
	for (int i = 0; i < 52; i++) //iterate through cards in deck
	{
		cout << "Card " << i << ": " << deck[i].getValue() << " of " << deck[i].getSuit() << endl; //outputs current card value and suit
	}
}

void Deck::shuffleDeck()
{
	//srand(time(0));
	//random_shuffle(deck.begin(), deck.end()); //uses random_shuffle to shuffle deck array of card objects
	random_device rd;
	mt19937 g(rd());
	shuffle(deck.begin(), deck.end(), g);
}

Deck::Deck()
{
	srand(time(nullptr));
	//for (int i = 0; i < 4; i++) //iterates through suits
	//{
	//	for (int j = 0; j < 13; j++) //iterates through values
	//	{
	//		arr[i][j] = 'X'; //ultimately sets every element in 2d array arr to 'X'
	//	}
	//}

	//while (deckFull() == false) //iterates until deck is full
	//{
	//	int row = rand() % 4; //generates random number for card suit
	//	int col = rand() % 13; //generates random number for card value
	//	if (inDeck(row, col) == false) //if not present in arr[][]
	//	{
	//		Card card(suits[row], values[col]);
	//		deck.push_back(card);
	//		//deck[uniqueCards].setSuit(deck[uniqueCards].toSuit(row)); //set card's suit in current deck position to string returned by toSuit
	//		//deck[uniqueCards].setValue(deck[uniqueCards].toValue(col)); //set card's value in current deck position to string returned by toValue
	//		setDeck(row, col); //set arr[row][col] to remove card's suit and value from generatable options
	//	}
	//}

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 13; i++) {
			Card card(suits[j], values[i]);
			deck.push_back(card);
		}
	}
}