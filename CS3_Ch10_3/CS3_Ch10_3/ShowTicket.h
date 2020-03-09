#pragma once
class ShowTicket
{
private:
	char row;
	int seat;
	bool sold;
public:
	bool getSold();
	void setSold();
	void getTicket();

	ShowTicket(char row, int seat);
};

