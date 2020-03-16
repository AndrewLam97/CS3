#include "Date.h"
#include <chrono>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

int Date::getYear() {
	return year;
}

void Date::setMonth(int month) {
	this->month = month;
}

void Date::setDay(int day) {
	this->day = day;
}

void Date::setYear(int year) {
	this->year = year;
}

void Date::ReplaceStringInPlace(string& subject, string& search, string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	//cout << endl << "Replaced string: " << subject << endl;
}

std::string Date::getDate(std::string format) {
	string output;
	string formatArr[4] = { "YY", "MM", "T", "F" };

	//convert YY to T and MM to F
	ReplaceStringInPlace(format, formatArr[0], formatArr[2]);
	ReplaceStringInPlace(format, formatArr[1], formatArr[3]);
	
	//concat desired date format
	for (int i = 0; i < format.length(); i++) {
		switch (format[i]) {
		case 'T':
			output += to_string(year);
			break;
		case 'Y':
			output += to_string(shortYear);
			break;
		case 'M':
			output += shortMonth;
			break;
		case 'F':
			output += longMonth;
			break;
		case 'm':
			output += to_string(month);
			break;
		case 'd':
			output += to_string(day);
			break;
		default:
			output += format[i];
		}
	}
	return output;
}

void Date::testDate() {
	cout << "Month: " << month << endl;
	cout << "Day: " << day << endl;
	cout << "Year: " << year << endl;
	cout << "Short Year: " << shortYear << endl;
	cout << "Long Month: " << longMonth << endl;
	cout << "Short Month: " << shortMonth << endl;
}

void Date::altFormats() {
	this->shortYear = year % 1000; //convert 4 digit year to 2 digit
	switch (month) {
	case 1:
		longMonth = "January";
		break;
	case 2:
		longMonth = "February";
		break;
	case 3:
		longMonth = "March";
		break;
	case 4:
		longMonth = "April";
		break;
	case 5:
		longMonth = "May";
		break;
	case 6:
		longMonth = "June";
		break;
	case 7:
		longMonth = "July";
		break;
	case 8:
		longMonth = "August";
		break;
	case 9:
		longMonth = "September";
		break;
	case 10:
		longMonth = "October";
		break;
	case 11:
		longMonth = "November";
		break;
	case 12:
		longMonth = "December";
		break;
	}

	shortMonth = longMonth.substr(0, 3);
}

Date::Date() {
	time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now()); //get current time

	//create strings for month, day, and year
	char monthStr[20] = { 0 };
	std::strftime(monthStr, sizeof(monthStr), "%m", localtime(&now));
	char dayStr[20] = { 0 };
	std::strftime(dayStr, sizeof(dayStr), "%d", localtime(&now));
	char yearStr[20] = { 0 };
	std::strftime(yearStr, sizeof(yearStr), "%Y", localtime(&now));

	setMonth(stoi(monthStr));
	setDay(stoi(dayStr));
	setYear(stoi(yearStr));

	this->shortYear = year % 1000;
	char longMonthStr[50] = { 0 };
	strftime(longMonthStr, sizeof(longMonthStr), "%B", localtime(&now));
	this->longMonth = longMonthStr;
	char shortMonthStr[50] = { 0 };
	strftime(shortMonthStr, sizeof(shortMonthStr), "%b", localtime(&now));
	this->shortMonth = shortMonthStr;

}

Date::Date(int month, int day, int year) {
	setMonth(month);
	setDay(day);
	setYear(year);

	altFormats();
}