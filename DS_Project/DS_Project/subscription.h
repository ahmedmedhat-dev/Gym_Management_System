#pragma once
#include <iostream>
#include "colors.h"
using namespace std;
class subscription
{
	int subID;
	int userID;
	string subType;
	string subStartDate;
	string subEndDate;
	int subDuration; // in days
	bool isValid;
	bool isVIP;

public:
	static int costOfmonthlySub;
	static int costOfyearlySub;
	static int costOfThreeMonthsSub;
	static int costOfSixMonthsSub;
	static int costOfVIPSub;

	// Constructor & Destructor
	subscription(int Id, int userId, string type, string startDate, string endDate, int duration, bool valid, bool VIP);
	subscription();
	~subscription();
	// functions
	void displaySubDetails();
	void changeSub(int id, string type, string startDate, string endDate, int duration, bool valid, bool VIP);
	static void displayCost();

	// Getters and Setters
	int getSubID();
	int getUserID();
	string getSubType();
	string getSubStartDate();
	string getSubEndDate();
	int getSubDuration();
	bool getIsValid();
	bool getIsVIP();
	void setSubID(int id);
	void setUserID(int id);
	void setSubType(string type);
	void setSubStartDate(string startDate);
	void setSubEndDate(string endDate);
	void setSubDuration(int duration);
	void setIsValid(bool valid);
	void setIsVIP(bool VIP);
};