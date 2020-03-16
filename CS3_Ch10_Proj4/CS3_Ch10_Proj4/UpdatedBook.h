#pragma once
#include "BookInfo.h"
class UpdatedBook :  public BookInfo
{
protected:
	int edition;
public:
	int getEdition(); //gets book edition
	UpdatedBook(string title, string author, int edition);
	UpdatedBook(string title, int edition);
};

