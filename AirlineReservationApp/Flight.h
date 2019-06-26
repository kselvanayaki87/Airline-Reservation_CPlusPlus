#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;
static int kFlightId = 1;

class Flight {
public:
	Flight();

	int mFlightno;
	string mDestination;
	string mDepature;
	string mDate;
	string mdeptime;
	string marrtime;
	vector<string> unreservedSeats;

	string getSeat();
	void displayFlightSummary();

};