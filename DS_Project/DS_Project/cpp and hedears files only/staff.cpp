#include "staff.h"
#include <algorithm>

staff::staff() :person() {};
staff::staff(int ID, string name, string DOB, string pass, string phone) : person(ID, name, DOB, pass, phone) {};
staff::~staff() {};
// == Functions =============================
void staff::printDetails() {
	std::cout << "ID:           " << getID() << endl;
	std::cout << "Name:         " << getName() << endl;
	std::cout << "DOB:          " << getDOB() << endl;
	std::cout << "Password:     " << getPassword() << endl;
	std::cout << "Phone Number: " << getPhoneNumber() << endl;
}
// == Manage members ========================
void staff::manageMembers(map<int, member>& members, vector<vector<classSession>>& classSessions, map<int, padelCourt>& courts, vector<booking>& books)
{
	int option;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║            Manage members            ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl;
		cout << "1. Search for member\n";
		cout << "2. Manage member subscription\n";
		cout << "3. Add member to a class\n";
		cout << "4. padel court\n";
		cout << "5. Add new members\n";
		cout << "6. View all members\n";
		cout << "0. Exit\n";
		cin >> option;
		if (option == 1) { searchMember(members); }
		else if (option == 2) {
			cout << "Enter the member ID: ";
			int memberID;
			cin >> memberID;
			if (members.count(memberID)) {
				members[memberID].Subsribtion();
			}
			else {
				cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════╗" << RESET << endl;
				cout << FG_WHITE << BG_RED << u8"\t\t║   Invalid member ID!!   ║" << RESET << endl;
				cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════╝" << RESET << endl << endl;
				Sleep(500);
			}
		}
		else if (option == 3) {
			cout << "Enter the member ID: ";
			int memberID;
			cin >> memberID;
			if (members.count(memberID)) {
				classSession::addMember(memberID, classSessions, members);
			}
			else {
				cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════╗" << RESET << endl;
				cout << FG_WHITE << BG_RED << u8"\t\t║   Invalid member ID!!   ║" << RESET << endl;
				cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════╝" << RESET << endl << endl;
			}

		}
		else if (option == 4) {
			cout << "Enter the member ID: ";
			int memberID;
			cin >> memberID;
			if (members.count(memberID)) {
				members[memberID].PadelCourt(courts, books);
			}
			else {
				cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════╗" << RESET << endl;
				cout << FG_WHITE << BG_RED << u8"\t\t║   Invalid member ID!!   ║" << RESET << endl;
				cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════╝" << RESET << endl << endl;
				Sleep(500);
			}
		}
		else if (option == 5) { addMember(members); }
		else if (option == 6) { viewAllMembers(members); }
		else if (option == 0) {
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
		else {
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-5) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
	} while (option != 0);
}
void staff::searchMember(map<int, member>& members)
{
	string searchName;
	int id;
	bool found = false;
	int option;
	cout << "   Please chose an option :\n";
	cout << "1. Search with name\n";
	cout << "2. Search with ID\n";
	cin >> option;
	if (option == 1) {
		cout << "Enter name to search: ";
		cin.ignore(1, '\n');
		getline(cin, searchName);
		for (auto& member : members) {
			if (member.second.getName() == searchName) {
				member.second.printDetails();
				found = true;
			}
		}
		if (!found) {
			cout << FG_WHITE << BG_RED << u8"\t\t═════════════════════════════════" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t No member found with name: " << searchName << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t═════════════════════════════════" << RESET << endl << endl;
			Sleep(500);
		}
	}
	else if (option == 2) {
		cout << "Enter the id: ";
		cin >> id;
		for (auto& member : members)
		{
			if (member.second.getID() == id)
			{
				member.second.printDetails();
				found = true;
			}
		}
		if (!found) {
			cout << FG_WHITE << BG_RED << u8"\t\t══════════════════════════════════" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t    No member found with ID: " << id << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t══════════════════════════════════" << RESET << endl << endl;
			Sleep(500);
		}
	}
	else {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 1-2) ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return;
	}
}
void staff::addMember(map<int, member>& members)
{
	string name, DOB, password, phoneNumber;
	cout << "Enter member name: ";
	cin.ignore(1, '\n');
	getline(cin, name);
	cout << "-----------------------------------\n";
	cout << "Enter Date of birth: ";
	cin >> DOB;
	cout << "-----------------------------------\n";
	cout << "Enter password: ";
	cin >> password;
	cout << "-----------------------------------\n";
	cout << "Enter phone number: ";
	cin >> phoneNumber;
	cout << "-----------------------------------\n";
	int ID = members.size() + 1000;
	members[ID] = member(ID, name, DOB, password, phoneNumber);
	members[ID].Change_Sub();
	cout << FG_WHITE << BG_GREEN << u8"\t\t╔════════════════════════════════╗" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║    Member added successfully   ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║    Member ID is : " << ID << u8"         ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t╚════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
}
void staff::viewAllMembers(map<int, member>& members) {
	if (members.size() == 0) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║   There is no members   ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════╝" << RESET << endl << endl;
		return;
	}
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║    Viewing all members...   ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
	cout << "===================================================\n";
	for (auto& it : members) {
		it.second.printDetails();
		cout << "===================================================\n";
	}
}
// == Manage class session ===================
void staff::manageClassSessions(vector<vector<classSession>>& classSessions)
{
	int option;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║        Manage class sessions         ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please chose an option:\n";
		cout << "1. Schedule a class\n";
		cout << "2. Cancel a class\n";
		cout << "3. View class schedule\n";
		cout << "0. Exit\n";
		cin >> option;
		switch (option) {
		case 1: sheduleClass(classSessions); break;
		case 2: cancelClass(classSessions); break;
		case 3: classSession::printClassVector(classSessions); break;
		case 0:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-3) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		}
	} while (option != 0);
}
void staff::cancelClass(vector<vector<classSession>>& classSessions)
{
	cout << "Enter the ID of the class you want to cancel:\n";
	int id;
	cin >> id;
	bool found = false;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < classSessions[i].size(); j++) {
			if (classSessions[i][j].getID() == id) {
				classSessions[i].erase(classSessions[i].begin() + j);
				cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════╗" << RESET << endl;
				cout << FG_WHITE << BG_GREEN << u8"\t\t║    Class canceled   ║" << RESET << endl;
				cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════╝" << RESET << endl << endl;
				Sleep(500);
				found = true;
				break;
			}
		}
		if (found) { break; }
	}
	if (!found) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═══════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║   Class was not found!!   ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═══════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
	}
}
void staff::sheduleClass(vector<vector<classSession>>& classSessions) {
	int ID, capacity, day, hour, coachID;
	string date, time, duration, type, Location;
	cout << "Enter class date: ";
	cin >> date;
	cout << "-----------------------------------\n";
	cout << "Enter class time: ";
	cin >> time;
	cout << "-----------------------------------\n";
	cout << "Enter class type: ";
	cin.ignore(1, '\n');
	getline(cin, type);
	cout << "-----------------------------------\n";
	cout << "Enter class duration: ";
	cin >> duration;
	cout << "-----------------------------------\n";
	cout << "Enter class location: ";
	cin.ignore(1, '\n');
	getline(cin, Location);
	cout << "-----------------------------------\n";
	cout << "Enter class coach ID: ";
	cin >> coachID;
	cout << "-----------------------------------\n";
	cout << "Enter class capacity: ";
	cin >> capacity;
	cout << "-----------------------------------\n";
	cout << "Enter class week day: ";
	cin >> day;
	cout << "-----------------------------------\n";
	cout << "Enter class day hour: ";
	cin >> hour;
	cout << "-----------------------------------\n";
	ID = 600000 + (day + 1000) + (hour + 100);
	classSessions[day - 1].push_back(classSession(ID, date, time, duration, type, Location, coachID, capacity));
}
// == Manage bookings ========================
void staff::manageBookings(vector<booking>& bookings, map<int, padelCourt>& courts)
{
	int option;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║           Manage bookings            ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please chose an option:\n";
		cout << "1. View booking history\n";
		cout << "2. Cancel a booking\n";
		cout << "3. View booking details\n";
		cout << "0. Exit\n";
		cin >> option;
		switch (option)
		{
		case 1: viewBookingHistory(bookings); break;
		case 2:
			cout << "Enter member ID:\n";
			int ID;
			cin >> ID;
			padelCourt::cancelBook(ID, bookings, courts); break;
		case 3: viewBookingDetails(bookings); break;
		case 0:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-3) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
	} while (option != 0);
}
void staff::viewBookingHistory(vector<booking>& bookings)
{
	if (bookings.empty()) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔══════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║   There is no bookings   ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚══════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return;
	}
	cout << "===================================================\n";
	for (int i = 0; i < bookings.size(); i++) {
		bookings[i].printDetails();
		cout << "===================================================\n";
	}
}
void staff::viewBookingDetails(vector<booking>& bookings)
{
	cout << "Enter the book ID to see detalis:\n";
	int ID;
	cin >> ID;
	for (int i = 0; i < bookings.size(); i++) {
		if (bookings[i].getBookingID() == ID) {
			cout << "------------------------------------------\n";
			bookings[i].printDetails();
			cout << "------------------------------------------\n";
			return;
		}
	}
	cout << FG_WHITE << BG_RED << u8"\t\t╔═══════════════════════════════════════╗" << RESET << endl;
	cout << FG_WHITE << BG_RED << u8"\t\t║   There is no booking with this ID!!  ║" << RESET << endl;
	cout << FG_WHITE << BG_RED << u8"\t\t╚═══════════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
}
// == Manage training programs ===============
void staff::manageTrainingPrograms(vector<string>& T) {
	int option;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║       Manage training program        ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   PLease chose an option:" << endl;
		cout << "1. Add training program\n";
		cout << "2. View training programs\n";
		cout << "0. Exit\n";
		cin >> option;
		if (option == 1) {
			cout << "Enter the training:\n";
			string line;
			string fullInput;
			cin.ignore(1, '\n');
			while (true) {
				getline(std::cin, line);
				if (line.empty()) break;
				fullInput += line + "\n";
			}
			T.push_back(fullInput);
		}
		else if (option == 2) {
			cout << "______________________________________\n";
			for (int i = 0; i < T.size(); i++) {
				cout << "Training program number: " << i << endl;
				cout << "______________________________________\n";
				cout << T[i] << endl;
				cout << "______________________________________\n";
			}
		}
		else if (option == 0) {
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║     Exiting ...    ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			return;
		}
		else {
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-2) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
	} while (option != 0);
}