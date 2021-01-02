#include "BookInfo.h"

void BookInfo::getInfo() { //prints book title and author
	cout << "Title: " << title << ", Author: " << author << endl;
}

BookInfo::BookInfo(string title, string author) {
	this->title = title;
	this->author = author;
}

BookInfo::BookInfo(string title) {
	this->title = title;
	this->author = "Unknown";
}



