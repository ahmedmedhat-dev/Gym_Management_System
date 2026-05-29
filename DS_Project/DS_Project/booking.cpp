#include "booking.h"
#include <Windows.h>
// Constructors and Destructor
booking::booking() : bookingID(0), courtID(0), memberID(0), date(""), time("") {
	// Default constructor
}
booking::booking(int bID, int cID, int mID, string d, string t) {
	bookingID = bID;
	courtID = cID;
	memberID = mID;
	date = d;
	time = t;
}
booking::~booking() {
	// Destructor implementation (if needed)
}
void booking::printDetails() {
	cout << "-----------------------------------\n";
	cout << "Booking ID: " << bookingID << endl;
	cout << "Court ID:   " << courtID << endl;
	cout << "Member ID:  " << memberID << endl;
	Date::printDate(date);
	Date::printTime12(time);
	cout << "-----------------------------------\n";

}
void booking::addBooking(vector<booking>& bookings, int bID, int cID, int mID, int day, int hour) {
	bookings.push_back(booking(bID, cID, mID, Date::getDateOfWeekday(day), Date::hourTo24Format(hour)));
}
void booking::pBookByID(vector<booking>& bookings, int userID) {
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║     Viewing your bookings...    ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
	for (int i = 0; i < bookings.size(); i++) {
		if (bookings[i].getMemberID() == userID) {
			bookings[i].printDetails();
		}
	}
}
// Getters and Setters
int booking::getBookingID() { return bookingID; }
int booking::getCourtID() { return courtID; }
int booking::getMemberID() { return memberID; }
string booking::getDate() { return date; }
string booking::getTime() { return time; }
void booking::setBookingID(int bID) { bookingID = bID; }
void booking::setCourtID(int cID) { courtID = cID; }
void booking::setMemberID(int mID) { memberID = mID; }
void booking::setDate(string d) { date = d; }
void booking::setTime(string t) { time = t; }

