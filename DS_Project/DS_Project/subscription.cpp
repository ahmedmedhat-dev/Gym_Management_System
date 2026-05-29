#include "subscription.h"
#include <Windows.h>
// constructor & destructor
subscription::subscription(int Id, int userId, string type, string startDate, string endDate, int duration, bool valid, bool VIP) {
	subID = Id;
	userID = userId;
	subType = type;
	subStartDate = startDate;
	subEndDate = endDate;
	subDuration = duration;
	isValid = valid;
	isVIP = VIP;
}
subscription::subscription() {
	subID = 0;
	userID = 0;
	subType = "";
	subStartDate = "";
	subEndDate = "";
	subDuration = 0;
	isValid = false;
	isVIP = false;
}
subscription::~subscription() {
	// Destructor code here
}

// Static variables initialization
int subscription::costOfmonthlySub = 400;
int subscription::costOfyearlySub = 750;
int subscription::costOfThreeMonthsSub = 1450;
int subscription::costOfSixMonthsSub = 2800;
int subscription::costOfVIPSub = 5000;
// functions
void subscription::displaySubDetails() {
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║ Viewing Subscription Details... ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
	cout << "Subscription ID:         " << subID << endl;
	cout << "Subscription Type:       " << subType << endl;
	cout << "Subscription Start Date: " << subStartDate << endl;
	cout << "Subscription End Date:   " << subEndDate << endl;
	cout << "Subscription Duration:   " << subDuration << endl;
	cout << "Is Valid:                " << (isValid ? "Yes" : "No") << endl;
	cout << "Is VIP:                  " << (isVIP ? "Yes" : "No") << endl;
}
void subscription::changeSub(int id, string type, string startDate, string endDate, int duration, bool valid, bool VIP)
{
	subID = id + 5000;
	userID = id;
	subType = type;
	subStartDate = startDate;
	subEndDate = endDate;
	subDuration = duration;
	isValid = valid;
	isVIP = VIP;
	cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║   Operation done successfully   ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
}
void subscription::displayCost()
{
	cout << "1. Cost of Monthly      Subscription: " << costOfmonthlySub << endl;
	cout << "2. Cost of Three Months Subscription: " << costOfThreeMonthsSub << endl;
	cout << "3. Cost of Six Months   Subscription: " << costOfSixMonthsSub << endl;
	cout << "4. Cost of Yearly       Subscription: " << costOfyearlySub << endl;
	cout << "5. Cost of VIP          Subscription: " << costOfVIPSub << endl;
}

// Getters and Setters
int subscription::getSubID() { return subID; }
int subscription::getUserID() { return userID; }
string subscription::getSubType() { return subType; }
string subscription::getSubStartDate() { return subStartDate; }
string subscription::getSubEndDate() { return subEndDate; }
int subscription::getSubDuration() { return subDuration; }
bool subscription::getIsValid() { return isValid; }
bool subscription::getIsVIP() { return isVIP; }
void subscription::setSubID(int id) { subID = id; }
void subscription::setUserID(int id) { userID = id; }
void subscription::setSubType(string type) { subType = type; }
void subscription::setSubStartDate(string startDate) { subStartDate = startDate; }
void subscription::setSubEndDate(string endDate) { subEndDate = endDate; }
void subscription::setSubDuration(int duration) { subDuration = duration; }
void subscription::setIsValid(bool valid) { isValid = valid; }
void subscription::setIsVIP(bool VIP) { isVIP = VIP; }
