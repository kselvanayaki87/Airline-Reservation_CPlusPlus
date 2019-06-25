
#include <iostream>
#include <string>
#include <vector>
#include "Database.h"
#include "PassengerInfo.h"
#include "TicketInfo.h"
#include "AirlineReservationApp.h"

using namespace std;

int displayMenu();
void flightSchedule();
void flightDetails();
void seatReserve();
void displayTicketInfo();
void displayPassengerInfo();
Database database;


int main()
{

	while (true)
	{
		int selection = displayMenu();
		switch (selection)
		{
		case 0:
			return 0;
		case 1:
			 seatReserve();
			break;
		case 2:
			 flightSchedule();
			break;
		case 3:
			displayPassengerInfo();
			break;
		case 4:
			 flightDetails();
			break;
		case 5:
			displayTicketInfo();
			break;
		default:
			cerr << "Invalid selection. Try again" << endl;
			break;
		}
	}

	return 0;
}
//The below method is used to display the ticket information to user
void displayTicketInfo() {

	int ticketId;
	cout << "Enter the ticket no: " << endl;
	cin >> ticketId;

	TicketInfo ticketInfo = database.getTicketInfo(ticketId);
	ticketInfo.display();

	PassengerInfo passengerInfo = database.getPassengerInfo(ticketInfo.passengerId);
	passengerInfo.displayPassengerSummary();

	database.displayFlightSchedule(ticketInfo.mflightNo, ticketInfo.mdate);
}

//The below method is used to display the passenger information to user

void displayPassengerInfo() {
	string firstname, lastname;
	cout << "Enter the first name: " << endl;
	cin >> firstname;

	cout << "Enter the last name: " << endl;
	cin >> lastname;

	PassengerInfo passengerInfo = database.getPassengerInfo(firstname, lastname);
	passengerInfo.displayPassengerDetails();
}

//The below method is used to display the flight details to user

void flightDetails() {
	int flightno;
	cout << "Enter the flight no: " << endl;
	cin >> flightno;

	string date;
	cout << "Enter the date: " << endl;
	cin >> date;

	database.displayFlightDetails(flightno, date);
}

//The below method is used to display the flight schedule information to user

void flightSchedule() {
	int flightno;
	cout << "Enter the flight no: " << endl;
	cin >> flightno;

	string date;
	cout << "Enter the date: " << endl;
	cin >> date;
	database.displayFlightSchedule(flightno, date);
}

int displayMenu()
{
	int selection;
	cout << endl;
	cout << "*******************\n";
	cout << "Airline Reservation\n";
	cout << "*******************\n";
	cout << "1. Reserve a Seat" << endl;
	cout << "2. Flight Schedule" << endl;
	cout << "3. Display passenger info" << endl;
	cout << "4. Flight Details" << endl;
	cout << "5. User ticket information" << endl;
	cout << "0. Exit" << endl;
	cin >> selection;
	return selection;
}

//The below method handles the reservation of a seat

void seatReserve()
{
	int flightno;
	cout << "Enter the flight no: " << endl;
	cin >> flightno;

	string date;
	cout << "Enter the date: " << endl;
	cin >> date;

	Flight flight = database.getFlight(flightno, date);

	if (flight.mDate == "") {
		cout << "No flights available" << endl;
		return;
	}

	if (flight.unreservedSeats.size() == 0) {
		cout << "No seats available" << endl;
		return;
	}

	string firstName, lastName, gender;
	int age;
	cout << "Enter Passenger FirstName" << endl;
	cin >> firstName;
	cout << "Enter Passenger LastName" << endl;
	cin >> lastName;
	cout << "Enter Passenger age" << endl;
	cin >> age;
	cout << "Enter Passenger gender" << endl;
	cin >> gender;

	//Create ticket info
	TicketInfo ticketInfo;
	ticketInfo.mdate = flight.mDate;
	ticketInfo.mflightNo = flight.mFlightno;
	ticketInfo.mseat = flight.getSeat();
	database.tickets.push_back(ticketInfo);

	//create passenger info
	PassengerInfo passengerInfo;
	passengerInfo.mAge = age;
	passengerInfo.mGender = gender;
	passengerInfo.mFirstname = firstName;
	passengerInfo.mLastname = lastName;
	passengerInfo.mTicketinfo = ticketInfo.mticketId;
	ticketInfo.passengerId = passengerInfo.mPassengerId;
	database.passengers.push_back(passengerInfo);

	//display;
	ticketInfo.display();
	passengerInfo.displayPassengerSummary();
	flight.displayFlightSummary();

}

