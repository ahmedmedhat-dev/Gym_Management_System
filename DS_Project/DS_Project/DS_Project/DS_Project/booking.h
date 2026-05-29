#pragma once
#include <iostream>
#include "Date.h"
#include <vector>
#include "colors.h"
using namespace std;

class booking
{
	int bookingID;
	int courtID;
	int memberID;
	string date;
	string time;
public:
	// Constructors and Destructor
	booking(); // Default constructor
	booking(int bID, int cID, int mID, string d, string t);
	~booking();
	// Functions
	void printDetails();
	static void addBooking(vector<booking>& bookings, int bID, int cID, int mID, int d, int t);
	static void pBookByID(vector<booking>& bookings, int userID);
	// Getters and Setters
	int getBookingID();
	int getCourtID();
	int getMemberID();
	string getDate();
	string getTime();
	void setBookingID(int bID);
	void setCourtID(int cID);
	void setMemberID(int mID);
	void setDate(string d);
	void setTime(string t);
};

