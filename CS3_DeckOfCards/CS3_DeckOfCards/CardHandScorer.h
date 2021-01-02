#pragma once
#include "CardHand.h"
#include "PokerScore.h"
#include <map>


class CardHandScorer
{
public:
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

	void scoreHand(CardHand ch);
};

