#pragma once
#include <string>
#include <map>
#include <vector>
#include "booking.h"
#include "Date.h"
#include <iostream>
#include "colors.h"
using namespace std;
// PadelCourt.h
class padelCourt
{
private:
	int courtID;
	string location;
	bool isAvailable[7][24]{}; // 7 days a week, 24 hours a day

public:
	// Constructors and Destructor
	padelCourt(int id, string loc);
	padelCourt();
	~padelCourt();
	// Functions
	void bookCourt(int memberID, vector<booking>& books, map<int, padelCourt>& courts);
	static void cancelBook(int memberID, vector<booking>& books, map<int, padelCourt>& courts);
	void printDetails();
	void displayCourtAvailability();
	static void displayCourts(map<int, padelCourt>& courts);
	bool isCourtAvailable(padelCourt court, int day, int hour);

	// Getters and Setters
	bool getAvailability(int y, int j);
	int getCourtID();
	string getLocation();
	void setAvailability(bool availability[7][24]);
	void setCourtID(int id);
	void setLocation(const string& loc);
};

