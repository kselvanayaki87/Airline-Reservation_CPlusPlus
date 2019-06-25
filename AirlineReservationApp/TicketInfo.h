#pragma once
#include <string>
#include <iostream>
using namespace std;

static int kticketId = 1001;

class TicketInfo
{
public:
	TicketInfo();
	int mticketId;
	int mflightNo;
	string mdate;
	string mseat;
	int passengerId;
	//ticket id, date, flight no, seat

	void display();
};

