#pragma once
#include <vector>
using namespace std;

template < class Key, class T>
class Map {
public:
	vector<Key> keyVec;
	vector<T> tVec;

	void add(Key addKey, T addT);
};

