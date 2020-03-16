#include "Record.h"
#include <iostream>
using namespace std;

void Record::setQuiz1(double quiz1) {
	this->quiz1 = quiz1;
}
void Record::setQuiz2(double quiz2) {
	this->quiz2 = quiz2;
}
void Record::setMidterm(double midterm) {
	this->midterm = midterm;
}
void Record::setFinal(double final) {
	this->final = final;
}

void Record::setAvg(double avg) {
	this->avg = avg;
}

void Record::setLetter(char letterGrade) {
	this->letterGrade = letterGrade;
}

double Record::getQuiz1() {
	return quiz1;
}
double Record::getQui2() {
	return quiz2;
}
double Record::getMidterm() {
	return midterm;
}
double Record::getFinal() {
	return final;
}

double Record::getAvg() {
	return avg;
}

char Record::getLetter() {
	return letterGrade;
}

void Record::enterScores() {
	cout << "Enter quiz 1: ";
	cin >> quiz1;
	cout << endl << "Enter quiz 2: ";
	cin >> quiz2;
	cout << endl << "Enter midterm: ";
	cin >> midterm;
	cout << endl << "Enter final: ";
	cin >> final;
}

void Record::calculateAvg() {
	double quizAvg = ((((quiz1 / 10.0) + (quiz2 / 10.0))) / 2.0) * 100;

	setAvg(double(quizAvg * 0.25) + (midterm * 0.25) + (final * 0.5));
}

void Record::calculateLetter() {
	if (avg >= 90) {
		letterGrade = 'A';
	}
	else if (avg >= 80) {
		letterGrade = 'B';
	}
	else if (avg >= 70) {
		letterGrade = 'C';
	}
	else if (avg >= 60) {
		letterGrade = 'D';
	}
	else {
		letterGrade = 'F';
	}
}

void Record::printRecord() {
	cout << endl << "Quiz 1: " << quiz1 << endl;
	cout << "Quiz 2: " << quiz2 << endl;
	cout << "Midterm: " << midterm << endl;
	cout << "Final: " << final << endl;
	cout << endl << "Numerical Average: " << avg << endl;
	cout << "Letter grade: " << letterGrade;
}