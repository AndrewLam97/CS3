#pragma once
#include "CardHand.h"
#include <unordered_map>
using namespace std;
class PokerScore
{
public:
	//enum Scores {

	//	ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

	//	STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

	//	FOUR_OF_A_KIND, //four cards of the same ranking

	//	FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

	//	FLUSH, //five cards of the same suit

	//	STRAIGHT, //five cards in consecutive ranking

	//	THREE_OK_A_KIND, //three cards of the same rank

	//	TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

	//	ONE_PAIR, //two cards of the same rank

	//	HIGH_CARD //highest card in the player’s hand

	//};

	unordered_map<string, int> scoreMap = {
		{"ROYAL_FLUSH", 0},
		{"STRAIGHT_FLUSH", 0},
		{"FOUR_OF_A_KIND", 0},
		{"FULL_HOUSE", 0},
		{"FLUSH", 0},
		{"STRAIGHT", 0},
		{"THREE_OF_A_KIND", 0},
		{"TWO_PAIR", 0},
		{"ONE_PAIR", 0},
		{"HIGH_CARD", 0},
	};

	//vector<Scores> scores;

	void operator += (const unordered_map<string, int>& importMap);

	void printScores();

	//friend bool operator==(const PokerScore& p, Scores score);
};

