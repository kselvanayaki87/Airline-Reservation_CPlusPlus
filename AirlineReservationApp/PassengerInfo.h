#pragma once
#include <string>
#include <iostream>
using namespace std;
static int kPassengerId = 1;
class PassengerInfo
{
public:
	PassengerInfo();

	string mFirstname;
	string mLastname;
	int mAge;
	string mGender;
	int mTicketinfo;
	int mPassengerId;

	void displayPassengerSummary();
	void displayPassengerDetails();
};

