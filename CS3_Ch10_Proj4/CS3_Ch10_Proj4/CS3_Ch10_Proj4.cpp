/*
    CS3
    Ch10 Project 4
*/
#include <iostream>
#include "BookInfo.h"
#include "UpdatedBook.h"
using namespace std;

int main()
{
    //base class test
    BookInfo book1("TestTitle", "TestAuthor");
    book1.getInfo();
    BookInfo book2("asdf");
    book2.getInfo();

    cout << endl;

    //derived class test
    UpdatedBook book3("title3", "author3", 3);
    book3.getInfo();
    cout << "Edition: " << book3.getEdition() << endl;

    UpdatedBook book4("title 4", 4);
    book4.getInfo();
    cout << "Edition: " << book4.getEdition();

}