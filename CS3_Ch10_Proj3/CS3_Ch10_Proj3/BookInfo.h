#pragma once
#include <string>
#include <iostream>
using namespace std;

class BookInfo
{
private:
	string author;
	string title;
public:
	void getInfo(); //prints book title and author
	BookInfo(string title, string author);
	BookInfo(string title);

};

