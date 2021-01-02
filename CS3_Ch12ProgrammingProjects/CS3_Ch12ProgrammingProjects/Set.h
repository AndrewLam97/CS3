#pragma once
#include <vector>
using namespace std;
class Set
{
	vector<int> set;
public:
	void addElement(int element);
	Set setUnion(Set set1, Set set2);
	Set setIntersect(Set set1, Set set2);
};

