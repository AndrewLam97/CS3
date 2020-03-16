/*
    CS3
    Ch10 Project 3
*/
#include <iostream>
#include "BookInfo.h"
using namespace std;

int main()
{
    BookInfo book1("TestTitle", "TestAuthor") ; //constructor test
    book1.getInfo();
    BookInfo book2("asdf"); //unknown author constructor test
    book2.getInfo();
}