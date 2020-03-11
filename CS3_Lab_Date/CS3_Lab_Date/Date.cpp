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

std::string Date::getDate(std::string format) {
	string output;
	string formatArr[6] = { "YY", "Y", "MM", "M", "m", "d" };
	
	for (int i = 0; i < format.length(); i++) {
		for (int j = 0; j < 6; j++) {
			size_t found = format.find(formatArr[j]);
		}
	}
}

void Date::testDate() {
	cout << "Month: " << month << endl;
	cout << "Day: " << day << endl;
	cout << "Year: " << year << endl;
}

Date::Date() {
	time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
	char monthStr[20] = { 0 };
	std::strftime(monthStr, sizeof(monthStr), "%m", localtime(&now));
	char dayStr[20] = { 0 };
	std::strftime(dayStr, sizeof(dayStr), "%d", localtime(&now));
	char yearStr[20] = { 0 };
	std::strftime(yearStr, sizeof(yearStr), "%Y", localtime(&now));

	setMonth(stoi(monthStr));
	setDay(stoi(dayStr));
	setYear(stoi(yearStr));
}

Date::Date(int month, int day, int year) {
	setMonth(month);
	setDay(day);
	setYear(year);
}