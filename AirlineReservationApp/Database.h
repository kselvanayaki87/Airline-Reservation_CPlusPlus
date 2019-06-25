#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Flight.h"
#include "PassengerInfo.h"
#include "TicketInfo.h"
using namespace std;

class Database
{
	public:
		 Database();
		 vector<Flight> flights;
		 vector<PassengerInfo> passengers;
		 vector<TicketInfo> tickets;	

		 void displayFlightSchedule(const int& flightno, const string& date);
		 void displayFlightDetails(const int& flightno, const string& date);
		 Flight getFlight(const int& flightno, const string& date);
		 PassengerInfo getPassengerInfo(const string& firstname, const string& lastname);
		 PassengerInfo getPassengerInfo(const int& passengerId);
		 TicketInfo getTicketInfo(const int& ticketId);

};


