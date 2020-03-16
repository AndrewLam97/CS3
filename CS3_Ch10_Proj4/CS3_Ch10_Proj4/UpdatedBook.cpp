#include "UpdatedBook.h"

int UpdatedBook::getEdition() {
	return edition;
}

UpdatedBook::UpdatedBook(string title, string author, int edition) : BookInfo(title, author){
	this->edition = edition;
}

UpdatedBook::UpdatedBook(string title, int edition) : BookInfo(title) {
	this->edition = edition;
}