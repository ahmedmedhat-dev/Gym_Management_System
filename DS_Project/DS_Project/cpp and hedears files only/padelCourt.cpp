#include "PadelCourt.h"
#include "member.h"
// Constructors and Destructor
padelCourt::padelCourt(int id, string loc)
	: courtID(id), location(loc) {
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 24; j++) {
			isAvailable[i][j] = true;
		}
	}
}
padelCourt::padelCourt() : courtID(0), location("") {
	// Default constructor
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 24; j++) {
			isAvailable[i][j] = true;
		}
	}
}
padelCourt::~padelCourt() {
	// Destructor implementation (if needed)
}
// Functions
void padelCourt::bookCourt(int memberID, vector<booking>& books, map<int, padelCourt>& courts)
{
	displayCourts(courts);
	cout << "Enter court ID to book: ";
	int courtID;
	cin >> courtID;
	if (!courts.count(courtID)) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║    Invalid court ID!!   ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║     Please try again    ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return;
	}
	cout << "Enter booking date in the week (1/7): ";
	int day;
	cin >> day;
	cout << "Enter booking time (1-24): ";
	int hour;
	cin >> hour;
	if (isCourtAvailable(courts[courtID], day, hour)) {
		courts[courtID].isAvailable[day - 1][hour - 1] = false; // Mark the court as booked
		booking::addBooking(books, books.size() + 30000, courtID, memberID, day, hour);
		cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t║      Booking done successful    ║" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
		cout << "\t\t  for member " << memberID << " on " << day << "/" << hour << endl << endl;;
		Sleep(1000);
	}
	else {
		cout << FG_WHITE << BG_RED << u8"\t\t╔════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║           Booking failed!!         ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(1000);
	}

}
void padelCourt::cancelBook(int memberID, vector<booking>& books, map<int, padelCourt>& courts) {
	cout << "Enter booking ID to cancel: ";
	int bookingID;
	cin >> bookingID;
	bool found = false;
	// Find the booking in the vector
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getBookingID() == bookingID) {
			found = true;
			if (!Date::isMoreThanThreeHoursLeft(books[i].getDate(), books[i].getTime())) {
				cout << FG_WHITE << BG_RED << u8"\t\t╔════════════════════════════════════════════╗" << RESET << endl;
				cout << FG_WHITE << BG_RED << u8"\t\t║ Booking cannot be cancelled within 3 hours ║" << RESET << endl;
				cout << FG_WHITE << BG_RED << u8"\t\t╚════════════════════════════════════════════╝" << RESET << endl << endl;
				Sleep(500);
				return;
			}
			int day = Date::getWeekdayIndex(books[i].getDate());
			int hour = Date::time24ToHour(books[i].getTime());
			courts[books[i].getCourtID()].isAvailable[day - 1][hour] = true; // Mark the court as available
			cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t║  Booking cancelled successfully ║" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		}
	}
}
void padelCourt::printDetails()
{
	cout << "Court ID: " << courtID << endl;
	cout << "Location: " << location << endl;
	displayCourtAvailability();
}
void padelCourt::displayCourtAvailability()
{
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 24; ++j) {
			cout << "Day " << i << ", Hour " << j << ": "
				<< (isAvailable[i][j] ? "Available" : "Not Available") << endl;
		}
	}
}
void padelCourt::displayCourts(map<int, padelCourt>& courts) {
	if (courts.empty()) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔══════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║  There is no courts  ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
	}
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Viewing all courts...     ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
	int i = 0;
	for (auto& it : courts) {
		cout << "============================================\n";
		cout << "Court name: Court " << i + 1 << endl;
		cout << "Court ID: " << it.second.getCourtID() << endl;
		cout << "Location: " << it.second.getLocation() << endl;
		cout << "============================================\n";
		i++;
	}
}
bool padelCourt::isCourtAvailable(padelCourt court, int day, int hour)
{
	if (day < 1 || day > 7 || hour < 1 || hour > 24) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║  Invalid day or time!!  ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║     Please try again    ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return false;
	}
	else {
		if (court.isAvailable[day - 1][hour - 1] == true) {
			cout << FG_WHITE << BG_GREEN << u8"\t\t╔════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t║    court is available...   ║" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t╚════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			return true;
		}
		else {
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║  court is not available...  ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			return false;
		}
	}
}
// Getters and Setters
bool padelCourt::getAvailability(int y, int j) { return isAvailable[y][j]; }
int padelCourt::getCourtID() { return courtID; }
string padelCourt::getLocation() { return location; }
void padelCourt::setAvailability(bool availability[7][24]) {
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 24; ++j) {
			isAvailable[i][j] = availability[i][j];
		}
	}
}
void padelCourt::setCourtID(int id) { courtID = id; }
void padelCourt::setLocation(const string& loc) { location = loc; }
