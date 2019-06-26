#include "PassengerInfo.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

PassengerInfo::PassengerInfo()
{
	mPassengerId = kPassengerId++;
}

void PassengerInfo::displayPassengerSummary()
{
	// Display Passenger First name and last name;
	cout << "Passenger First Name:" << mFirstname << endl;
	cout << "Passenger Last Name:" << mLastname << endl;
}

void PassengerInfo::displayPassengerDetails()
{
	cout << "Passenger Ticket id:" << mTicketinfo << endl;
	cout << "Passenger First Name:" << mFirstname << endl;
	cout << "Passenger Last Name:" << mLastname << endl;
	cout << "Passenger Age:" << mAge << endl;
	cout << "Passenger Gender:" << mGender << endl;
}
