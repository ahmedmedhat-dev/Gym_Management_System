#pragma once
#include <iostream>
#include <vector>
#include "person.h"
#include "member.h"
#include "padelCourt.h"
#include "subscription.h"
#include "classSession.h"
#include "booking.h"
#include "colors.h"
using namespace std;

class staff : public person
{
public:
	staff();
	staff(int ID, string name, string DOB, string pass, string phone);
	~staff();
	void printDetails() override;
	// manage members
	static void manageMembers(map<int, member>& members, vector<vector<classSession>>& classSessions, map<int, padelCourt>& courts, vector<booking>& books);
	static void searchMember(map<int, member>& members);
	static void addMember(map<int, member>& members);
	static void viewAllMembers(map<int, member>& members);
	// manage class sessions
	static void manageClassSessions(vector<vector<classSession>>& classSessions);
	static void sheduleClass(vector<vector<classSession>>& classSessions);
	static void cancelClass(vector<vector<classSession>>& classSessions);
	// manage bookings
	static void manageBookings(vector<booking>& bookings, map<int, padelCourt>& courts);
	static void viewBookingHistory(vector<booking>& bookings);
	static void viewBookingDetails(vector<booking>& bookings);
	// manage training programs
	static void manageTrainingPrograms(vector<string>& T);
};

