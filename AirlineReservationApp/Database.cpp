#include "Database.h"
#include <string>
#include <iostream>
using namespace std;

Database::Database()
{
	//Initialize 5 flights;
	//#1
	Flight flight1;
	flight1.mDepature = "Seattle";
	flight1.mDestination = "Las Vegas";
	flight1.mDate = "07072019";
	flight1.mdeptime = "10:00 AM";
	flight1.marrtime = "1:00 PM";

	flights.push_back(flight1);

	//#2
	Flight flight2;
	flight2.mDepature = "Seattle";
	flight2.mDestination = "New York";
	flight2.mDate = "07082019";
	flight2.mdeptime = "11:00 AM";
	flight2.marrtime = "7:00 PM";
	flights.push_back(flight2);

	//#3
	Flight flight3;
	flight3.mDepature = "Seattle";
	flight3.mDestination = "Portland";
	flight3.mDate = "07082019";
	flight3.mdeptime = "1:00 PM";
	flight3.marrtime = "5:00 PM";
	flights.push_back(flight3);

	//#4
	Flight flight4;
	flight4.mDepature = "Seattle";
	flight4.mDestination = "Las Vegas";
	flight4.mDate = "07092019";
	flight4.mdeptime = "7:00 PM";
	flight4.marrtime = "12:00 AM";
	flights.push_back(flight4);

	//#5
	Flight flight5;
	flight5.mDepature = "Seattle";
	flight5.mDestination = "Las Vegas";
	flight5.mDate = "07102019";
	flight5.mdeptime = "10:00 PM";
	flight5.marrtime = "1:00 AM";

	flights.push_back(flight5);
}

void Database::displayFlightSchedule(const int& flightno, const string& date)
{
	for (Flight flight : flights) {
		if ((flight.mDate == date) && (flight.mFlightno == flightno)) {
			cout << endl << "Depature City: " << flight.mDepature << endl;
			cout << "Arrival City: " << flight.mDestination << endl;
			cout << "Departure Time: " << flight.mdeptime << endl;
			cout << "Arrival Time: " << flight.marrtime << endl;
			return;
		}
	}
	cout << endl << "No flights available" << endl;
}

void Database::displayFlightDetails(const int& flightno, const string& date)
{
	for (Flight flight : flights) {
		if ((flight.mDate == date) && (flight.mFlightno == flightno)) {			cout << "Total No. of seats available: " << flight.unreservedSeats.size() << endl;
		}
	}
}

Flight Database::getFlight(const int& flightno, const string& date)
{
	for (Flight flight : flights) {
		if ((flight.mDate == date) && (flight.mFlightno == flightno)) {
			return flight;
		}
	}
	return Flight();
}

PassengerInfo Database::getPassengerInfo(const string& firstname, const string& lastname)
{
	for (PassengerInfo passengerInfo : passengers) {
		if ((passengerInfo.mFirstname == firstname) && (passengerInfo.mLastname == lastname)) {
			return passengerInfo;
		}
	}
	return PassengerInfo();
}

PassengerInfo Database::getPassengerInfo(const int& passengerId)
{
	for (PassengerInfo passengerInfo : passengers) {
		if (passengerInfo.mPassengerId = passengerId) {
			return passengerInfo;
		}
	}
	return PassengerInfo();
}

TicketInfo Database::getTicketInfo(const int& ticketId)
{
	for (TicketInfo ticketInfo : tickets) {
		if (ticketInfo.mticketId == ticketId) {
			return ticketInfo;
		}
	}
	return TicketInfo();
}
