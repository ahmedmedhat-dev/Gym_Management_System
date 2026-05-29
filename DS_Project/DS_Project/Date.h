#pragma once
#include <string>
using namespace std;
// ChatGPT made all the class :) 
// Thanks to ChatGPT for the help with the Date class
// Edited by Ahmed Sharafeldin in 24/4/2025 Change functions to static functions
class Date {
public:
	static void printDate(const string& dateStr);
	static string getCurrentDate();
	static bool isToday(const string& dateStr);
	static string addDays(int daysToAdd);
	static string getCurrentTime24();
	static void printTime12(const string& time24);
	// added by Ahmed Sharafeldin in 7/5/2025
	static string getDateOfWeekday(int dayIndex); // 1 = Saturday, 7 = Friday
	static string hourTo24Format(int hour);       // 0 - 23
	static bool isMoreThanThreeHoursLeft(const string& dateStr, const string& timeStr);
	static int getWeekdayIndex(const string& dateStr);
	static int time24ToHour(const string& timeStr);
	static bool isPastDate(const string& dateStr);
	static bool isDateWithinAWeek(const string& dateStr);
};
