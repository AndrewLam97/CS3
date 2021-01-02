#include "Map.h"
template<class Key, class T> void Map<Key, T>::add(Key addKey, T addT) {
	keyVec.push_back(addKey);
	tVec.push_back(addT);
}