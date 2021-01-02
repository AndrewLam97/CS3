#include "Set.h"
#include <vector>
#include <algorithm>
using namespace std;

void Set::addElement(int element) {
	set.push_back(element);
}

Set Set::setUnion(Set set1, Set set2) {
	vector<int> unionVec(set1.set.size() + set2.set.size());
	vector<int>::iterator it;

	sort(set1.set.begin(), set1.set.end());
	sort(set2.set.begin(), set2.set.end());

	it = set_union(set1.set.begin(), set1.set.end(), set2.set.begin(), set2.set.end(), unionVec.begin());
	unionVec.resize(it - unionVec.begin());
}
Set Set::setIntersect(Set set1, Set set2) {
	vector<int> intersectVec(set1.set.size() + set2.set.size());
	vector<int>::iterator it;

	sort(set1.set.begin(), set1.set.end());
	sort(set2.set.begin(), set2.set.end());

	it = set_intersection(set1.set.begin(), set1.set.end(), set2.set.begin(), set2.set.end(), intersectVec.begin());
	intersectVec.resize(it - intersectVec.begin());

}