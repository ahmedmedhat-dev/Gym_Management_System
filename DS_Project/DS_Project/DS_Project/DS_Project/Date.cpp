#include "Date.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdio>
using namespace std;
// ChatGPT made all the class :)
// Thanks to ChatGPT for the help with the Date class
// Edited by Ahmed Sharafeldin in 24/4/2025 Change functions to static functions
void Date::printDate(const string& dateStr) {
	cout << "Date: " << dateStr << endl;
}
string Date::getCurrentDate() {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);  // Safe version

	ostringstream oss;
	oss << setfill('0') << setw(2) << ltm.tm_mday << "/"
		<< setfill('0') << setw(2) << ltm.tm_mon + 1 << "/"
		<< 1900 + ltm.tm_year;
	return oss.str();
}
bool Date::isToday(const string& dateStr) {
	return dateStr == getCurrentDate();
}
string Date::addDays(int daysToAdd) {
	time_t now = time(0);
	now += daysToAdd * 24 * 60 * 60;

	tm ltm;
	localtime_s(&ltm, &now);

	ostringstream oss;
	oss << setfill('0') << setw(2) << ltm.tm_mday << "/"
		<< setfill('0') << setw(2) << ltm.tm_mon + 1 << "/"
		<< 1900 + ltm.tm_year;
	return oss.str();
}
string Date::getCurrentTime24() {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	ostringstream oss;
	oss << setfill('0') << setw(2) << ltm.tm_hour << ":"
		<< setfill('0') << setw(2) << ltm.tm_min;
	return oss.str();
}
void Date::printTime12(const string& time24) {
	int hour, minute;
	sscanf_s(time24.c_str(), "%d:%d", &hour, &minute);  // safer version of sscanf

	string period = (hour >= 12) ? "PM" : "AM";
	hour = (hour % 12 == 0) ? 12 : hour % 12;

	cout << "Time: "
		<< setfill('0') << setw(2) << hour << ":"
		<< setfill('0') << setw(2) << minute << " " << period << endl;
}
string Date::getDateOfWeekday(int dayIndex) {
	if (dayIndex < 1 || dayIndex > 7) return "Invalid day index (1-7)";

	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	// Convert Sunday=0,...,Saturday=6 to Saturday=1,...Friday=7
	int currentDay = (ltm.tm_wday == 0) ? 7 : ltm.tm_wday; // Sunday -> 7

	// Difference between target day and current day
	int diff = dayIndex - currentDay;
	now += diff * 24 * 60 * 60;

	localtime_s(&ltm, &now);
	ostringstream oss;
	oss << setfill('0') << setw(2) << ltm.tm_mday << "/"
		<< setfill('0') << setw(2) << ltm.tm_mon + 1 << "/"
		<< 1900 + ltm.tm_year;
	return oss.str();
}
string Date::hourTo24Format(int hour) {
	if (hour < 0 || hour > 23) return "Invalid hour (0-23)";

	ostringstream oss;
	oss << setfill('0') << setw(2) << hour << ":00";
	return oss.str();
}
bool Date::isMoreThanThreeHoursLeft(const string& dateStr, const string& timeStr) {
	int day, month, year, hour, minute;

	if (sscanf_s(dateStr.c_str(), "%d/%d/%d", &day, &month, &year) != 3) return false;
	if (sscanf_s(timeStr.c_str(), "%d:%d", &hour, &minute) != 2) return false;

	tm target = {};
	target.tm_mday = day;
	target.tm_mon = month - 1;
	target.tm_year = year - 1900;
	target.tm_hour = hour;
	target.tm_min = minute;
	target.tm_sec = 0;

	time_t targetTime = mktime(&target);
	if (targetTime == -1) return false;

	time_t now = time(0);
	double diffInSeconds = difftime(targetTime, now);

	return diffInSeconds > 3 * 60 * 60;
}
int Date::getWeekdayIndex(const string& dateStr) {
	int day, month, year;
	if (sscanf_s(dateStr.c_str(), "%d/%d/%d", &day, &month, &year) != 3) return -1;

	tm timeStruct = {};
	timeStruct.tm_mday = day;
	timeStruct.tm_mon = month - 1;
	timeStruct.tm_year = year - 1900;

	mktime(&timeStruct); // fill tm_wday
	int wday = timeStruct.tm_wday; // 0 = Sunday, 6 = Saturday

	return (wday == 0) ? 7 : wday;
}
int Date::time24ToHour(const string& timeStr) {
	int hour, minute;
	if (sscanf_s(timeStr.c_str(), "%d:%d", &hour, &minute) != 2) return -1;
	if (hour < 0 || hour > 23) return -1;

	return hour;
}
bool Date::isPastDate(const string& dateStr) {
	int day, month, year;
	if (sscanf_s(dateStr.c_str(), "%d/%d/%d", &day, &month, &year) != 3) return false;

	tm inputDate = {};
	inputDate.tm_mday = day;
	inputDate.tm_mon = month - 1;
	inputDate.tm_year = year - 1900;
	inputDate.tm_hour = 0;
	inputDate.tm_min = 0;
	inputDate.tm_sec = 0;

	time_t inputTime = mktime(&inputDate);

	// Get today's date at 00:00
	time_t now = time(0);
	tm today = {};
	localtime_s(&today, &now);
	today.tm_hour = 0;
	today.tm_min = 0;
	today.tm_sec = 0;
	time_t todayTime = mktime(&today);

	return difftime(inputTime, todayTime) < 0;
}
bool Date::isDateWithinAWeek(const string& dateStr) {
	int day, month, year;
	if (sscanf_s(dateStr.c_str(), "%d/%d/%d", &day, &month, &year) != 3) return false;

	// Parse input date
	tm inputDate = {};
	inputDate.tm_mday = day;
	inputDate.tm_mon = month - 1;
	inputDate.tm_year = year - 1900;
	inputDate.tm_hour = 0;
	inputDate.tm_min = 0;
	inputDate.tm_sec = 0;

	time_t inputTime = mktime(&inputDate);

	// Get today's date at 00:00
	time_t now = time(0);
	tm today = {};
	localtime_s(&today, &now);
	today.tm_hour = 0;
	today.tm_min = 0;
	today.tm_sec = 0;
	time_t todayTime = mktime(&today);

	const int SECONDS_IN_A_DAY = 24 * 60 * 60;

	// Range: from tomorrow to 7 days from today
	time_t minTime = todayTime + 1 * SECONDS_IN_A_DAY;
	time_t maxTime = todayTime + 7 * SECONDS_IN_A_DAY;

	return inputTime >= minTime && inputTime <= maxTime;
}





