#include "PokerScore.h"

void PokerScore::operator+=(const unordered_map<string, int>& importMap) {
	for (auto it : importMap) {
		this->scoreMap[it.first] += it.second;
	}
}

void PokerScore::printScores() {
	for (auto ite : this->scoreMap) {
		cout << ite.first << " :: " << ite.second << endl;
	}
}
