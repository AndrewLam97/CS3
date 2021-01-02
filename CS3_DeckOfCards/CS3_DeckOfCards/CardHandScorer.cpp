//#include "CardHandScorer.h"
//template<typename KeyType, typename ValueType>pair<KeyType, ValueType> get_max(const unordered_map<KeyType, ValueType>& x) {
//	using pairtype = std::pair<KeyType, ValueType>;
//	return *std::max_element(x.begin(), x.end(), [](const pairtype& p1, const pairtype& p2) {
//		return p1.second < p2.second;
//		});
//}
//
//void CardHandScorer::scoreHand(CardHand ch){
//	//string suits[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };
//	//string values[13] = { "King", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen" };
//	//int suitArr[4] = { 0 };
//	//int rankArr[13] = { 0 };
//
//	unordered_map<string, int> suitsMap = {
//		{"Spades", 0},
//		{"Hearts", 0},
//		{"Diamonds", 0},
//		{"Clubs", 0}
//	};
//
//	unordered_map<string, int> valuesMap = {
//		{"Two", 0},
//		{"Three", 0},
//		{"Four", 0},
//		{"Five", 0},
//		{"Six", 0},
//		{"Seven", 0},
//		{"Eight", 0},
//		{"Nine", 0},
//		{"Ten", 0},
//		{"Jack", 0},
//		{"Queen", 0},
//		{"King", 0},
//		{"Ace", 0} 
//	};
//
//	for (int i = 0; i < ch.getSize(); i++) {
//		suitsMap[ch.getCard(i).getSuit()]++;
//		valuesMap[ch.getCard(i).getValue()]++;
//	}
//
//	this->scoreMap["HIGH_CARD"]++;
//
//	auto maxVal = get_max(valuesMap);
//
//
//	if (maxVal.second >= 2) {
//		this->scoreMap["ONE_PAIR"]++;
//	}
//	bool hasThree = false;
//	if (maxVal.second >= 3) {
//		this->scoreMap["THREE_OF_A_KIND"]++;
//		hasThree = true;
//	}
//	if (maxVal.second >= 4) {
//		this->scoreMap["FOUR_OF_A_KIND"]++;
//	}
//
//	if (hasThree == true) {
//		bool fullHouse = false;
//		for (auto it : valuesMap) {
//			if (it.second == 2) {
//				fullHouse = true;
//			}
//		}
//		if (fullHouse == true) {
//			this->scoreMap["FULL_HOUSE"]++;
//		}
//	}
//
//	auto maxSuit = get_max(suitsMap);
//	if (maxSuit.second >= 5) {
//		this->scoreMap["FLUSH"]++;
//	}
//
//	//2 pair
//	int countPairs = 0;
//	int continuous = 0;
//	for (auto it : valuesMap) {
//		if (valuesMap[it.first] >= 2) {
//			countPairs++;
//		}
//		if (valuesMap[it.first] != 0) {
//			continuous++;
//		}
//		else {
//			continuous = 0;
//		}
//	}
//	if (continuous == 5) {
//		this->scoreMap["STRAIGHT"]++;
//		if (maxVal.second >= 5) {
//			this->scoreMap["STRAIGHT_FLUSH"]++;
//		}
//	}
//	if (countPairs >= 2) {
//		this->scoreMap["TWO_PAIR"]++;
//	}
//}

#include "CardHandScorer.h"

template<typename KeyType, typename ValueType>
std::pair<KeyType, ValueType> get_max(const std::map<KeyType, ValueType>& x) {
	using pairtype = std::pair<KeyType, ValueType>;
	return *std::max_element(x.begin(), x.end(), [](const pairtype& p1, const pairtype& p2) {
		return p1.second < p2.second;
		});
}

template<typename KeyType, typename ValueType>pair<KeyType, ValueType> get_maxS(const unordered_map<KeyType, ValueType>& x) {
	using pairtype = std::pair<KeyType, ValueType>;
	return *std::max_element(x.begin(), x.end(), [](const pairtype& p1, const pairtype& p2) {
		return p1.second < p2.second;
		});
}

void CardHandScorer::scoreHand(CardHand ch) {
	//string suits[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };
	vector <string> straightComp = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
	vector <string> rFlushComp = { "Ten", "Jack", "Queen", "King", "Ace" };
	//int suitArr[4] = { 0 };
	//int rankArr[13] = { 0 };

	unordered_map<string, int> suitsMap = {
		{"Spades", 0},
		{"Hearts", 0},
		{"Diamonds", 0},
		{"Clubs", 0}
	};

	map<string, int> valuesMap = {
		{"Two", 0},
		{"Three", 0},
		{"Four", 0},
		{"Five", 0},
		{"Six", 0},
		{"Seven", 0},
		{"Eight", 0},
		{"Nine", 0},
		{"Ten", 0},
		{"Jack", 0},
		{"Queen", 0},
		{"King", 0},
		{"Ace", 0}
	};

	for (int i = 0; i < ch.getSize(); i++) {
		suitsMap[ch.getCard(i).getSuit()]++;
		valuesMap[ch.getCard(i).getValue()]++;
	}

	this->scoreMap["HIGH_CARD"]++;

	//auto maxVal = max_element(valuesMap.begin(), valuesMap.end());
	auto maxVal = get_max(valuesMap);
	//cout << "MaxVal: " << maxVal.first << " :: " << maxVal.second;

	if (maxVal.second >= 2) {
		this->scoreMap["ONE_PAIR"]++;
	}
	bool hasThree = false;
	if (maxVal.second >= 3) {
		this->scoreMap["THREE_OF_A_KIND"]++;
		hasThree = true;
	}
	if (maxVal.second >= 4) {
		this->scoreMap["FOUR_OF_A_KIND"]++;
	}

	if (hasThree == true) {
		bool fullHouse = false;
		for (auto it : valuesMap) {
			if (it.second == 2) {
				fullHouse = true;
			}
		}
		if (fullHouse == true) {
			this->scoreMap["FULL_HOUSE"]++;
		}
	}

	int rFlush = 0;
	auto maxSuit = get_maxS(suitsMap);
	if (maxSuit.second >= 5) {
		this->scoreMap["FLUSH"]++;
		for (int i = 0; i < rFlushComp.size(); i++) {
			if (valuesMap[rFlushComp[i]] != 0) {
				rFlush++;
			}
			if (valuesMap[rFlushComp[i]] == 0) {
				rFlush = -5;
			}
		}
	}
	if (rFlush == 5) {
		this->scoreMap["ROYAL_FLUSH"]++;
	}

	int countPairs = 0;
	int continuous = 0;
	bool straight = false;
	for (auto it : valuesMap) {
		if (valuesMap[it.first] >= 2) {
			countPairs++;
		}
	}
	for (int i = 0; i < straightComp.size(); i++) {
		if (valuesMap[straightComp[i]] != 0) {
			continuous += 1;
			if (continuous == 5) {
				straight = true;
			}
		}
		else {
			continuous = 0;
		}
	}
	if (countPairs >= 2) {
		this->scoreMap["TWO_PAIR"]++;
	}
	if (straight == true) {
		this->scoreMap["STRAIGHT"]++;
		if (maxSuit.second >= 5) {
			this->scoreMap["STRAIGHT_FLUSH"]++;
		}
	}
}