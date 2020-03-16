#pragma once
class Record
{
private:
    double quiz1;
    double quiz2;
    double midterm;
    double final;

    double avg;
    char letterGrade;
    //mutators
    void setQuiz1(double quiz1);
    void setQuiz2(double quiz2);
    void setMidterm(double midterm);
    void setFinal(double final);
    void setAvg(double avg);
    void setLetter(char letterGrade);

    //accessors
    double getQuiz1();
    double getQui2();
    double getMidterm();
    double getFinal();
    double getAvg();
    char getLetter();
public:
    void enterScores(); //takes user input for scores
    void calculateAvg(); //calculates numerical weighted average
    void calculateLetter(); //derives letter grade from weighted average
    void printRecord(); //prints student record
};

