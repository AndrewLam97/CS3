#pragma once
#include <string>
class Date
{
private:
	int month;
	int day;
	int year;
public:
	int getMonth();
	void setMonth(int month);
	int getDay();
	void setDay(int day);
	int getYear();
	void setYear(int year);

	std::string getDate(std::string format);

	void testDate();

	Date(); //set the date to today's date
	Date(int month, int day, int year);

};

