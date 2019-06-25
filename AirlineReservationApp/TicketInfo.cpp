#include "TicketInfo.h"
#include <vector>
#include "Database.h"
#include <string>

using namespace std;

TicketInfo::TicketInfo()
{
	mticketId = kticketId++;
}

void TicketInfo::display()
{
	cout << endl << "Ticket ID: " << mticketId << endl;
	cout << "Flight No: " << mflightNo << endl;
	cout << "Travel Date: " << mdate << endl;
	cout << "Seat No:" << mseat << endl;
}

