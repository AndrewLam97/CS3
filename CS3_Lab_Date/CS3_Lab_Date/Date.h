#pragma once
#include <string>
#include <chrono>
#include <ctime>
using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;
	int shortYear;
	string longMonth;
	string shortMonth;

	/*
	PURPOSE: Converts standard integer date formats to strings and variations of
	PARAMETERS: none
	RETURNS: none
	*/
	void altFormats();

	/*
	PURPOSE: Finds and replaces substrings in place
	PARAMETERS: References to original string, search string, and replace string
	RETURNS: none, original string modified in place
	*/
	void ReplaceStringInPlace(string& subject, string& search, string& replace);
public:
	int getMonth();
	void setMonth(int month);
	int getDay();
	void setDay(int day);
	int getYear();
	void setYear(int year);

	/*
	PURPOSE: 
	PARAMETERS:
	RETURNS:
	*/
	string getDate(string format);

	void testDate();

	Date(); //set the date to today's date
	Date(int month, int day, int year);

};

