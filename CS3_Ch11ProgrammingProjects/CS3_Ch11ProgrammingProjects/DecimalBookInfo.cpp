#include "DecimalBookInfo.h"
#include <string>
using namespace std;

DecimalBookInfo::DecimalBookInfo(string title, double code) {
	this->title = title;
	areaCode = int(code);
	subCode = code - areaCode;
}

bool operator < (DecimalBookInfo const& book1, DecimalBookInfo const& book2)
{
	if (book1.areaCode == book2.areaCode) {
		if (book1.subCode < book2.subCode) {
			return true;
		}
	}
	else if (book1.areaCode < book2.areaCode)
	{
		return true;
	}
	else return false;
}

bool operator > (DecimalBookInfo const& book1, DecimalBookInfo const& book2)
{
	if (book1.areaCode == book2.areaCode) {
		if (book1.subCode > book2.subCode) {
			return true;
		}
	}
	else if (book1.areaCode > book2.areaCode)
	{
		return true;
	}
	else return false;
}

