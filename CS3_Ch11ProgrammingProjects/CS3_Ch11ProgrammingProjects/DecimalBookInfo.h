#pragma once
#include <string>
using namespace std;

class DecimalBookInfo
{
	int areaCode;
	int subCode;

	string title;

public:
	DecimalBookInfo(string title, double code);

	friend bool operator < (DecimalBookInfo const& book1, DecimalBookInfo const& book2);
	friend bool operator > (DecimalBookInfo const& book1, DecimalBookInfo const& book2);
};

