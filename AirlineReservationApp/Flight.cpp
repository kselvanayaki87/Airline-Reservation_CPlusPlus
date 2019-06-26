#include "Flight.h"

Flight::Flight()
{
	mFlightno = kFlightId++;

	// Initialize seats;
	for (int i = 1; i <= 10; i++) {

		unreservedSeats.push_back("A" + to_string(i));
		unreservedSeats.push_back("B" + to_string(i));
		unreservedSeats.push_back("C" + to_string(i));
		unreservedSeats.push_back("D" + to_string(i));
	}
}

string Flight::getSeat()
{
	string seat = unreservedSeats.back();
	unreservedSeats.pop_back();
	//string seat = unreservedSeats.front();
	//unreservedSeats.erase(unreservedSeats.begin());
	//return seat;
	return seat;
}

void Flight::displayFlightSummary()
{
	// Display Flight source and destination;
	cout << "Source City:" << mDepature << endl;
	cout << "Desitination City:" << mDestination << endl;
}
