/*
    CS3
    Ch10 Project 1
*/

#include <iostream>
using namespace std;

struct Record {
    double quiz1;
    double quiz2;
    double midterm;
    double final;

    double avg;
    char letterGrade;
};

void enterScores(Record &student);
void calculateAvg(Record &student);
void printRecord(Record student);

int main()
{
    Record student;
    enterScores(student);
    calculateAvg(student);
    printRecord(student);
}

void enterScores(Record &student) { //Takes user input for grades
    cout << "Enter quiz 1: ";
    cin >> student.quiz1;
    cout << endl << "Enter quiz 2: ";
    cin >> student.quiz2;
    cout << endl << "Enter midterm: ";
    cin >> student.midterm;
    cout << endl << "Enter final: ";
    cin >> student.final;
}

void calculateAvg(Record& student) { //Calculates overall student average and letter grade
    double quizAvg = ((((student.quiz1 / 10.0) + (student.quiz2 / 10.0))) / 2.0) * 100;
    //double midtermAvg = student.midterm / 100.0;
    //double finalAvg = student.final / 100.0;

    student.avg = (quizAvg * 0.25) + (student.midterm * 0.25) + (student.final * 0.5);
    if (student.avg >= 90) {
        student.letterGrade = 'A';
    }
    else if (student.avg >= 80) {
        student.letterGrade = 'B';
    }
    else if (student.avg >= 70) {
        student.letterGrade = 'C';
    }
    else if (student.avg >= 60) {
        student.letterGrade = 'D';
    }
    else {
        student.letterGrade = 'F';
    }
}

void printRecord(Record student) { //Prints student's record to console
    cout << endl << "Quiz 1: " << student.quiz1 << endl;
    cout << "Quiz 2: " << student.quiz2 << endl;
    cout << "Midterm: " << student.midterm << endl;
    cout << "Final: " << student.final << endl;
    cout << endl << "Numerical Average: " << student.avg << endl;
    cout << "Letter grade: " << student.letterGrade;
}