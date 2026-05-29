#include "classSession.h"
#include "member.h";
// == Constructors and Destructor ===================
classSession::classSession(int id, string d, string t, string dur, string ty, string loc, int cId, int cap)
	: ID(id), date(d), time(t), duration(dur), type(ty), Location(loc), coachID(cId), capacity(cap) {
}
classSession::classSession() {
	ID = 0;
	date = "";
	time = "";
	duration = "";
	type = "";
	Location = "";
	coachID = 0;
	capacity = 0;
}
classSession::~classSession() {
	// Destructor
}
// == Functions =====================================
void classSession::printDetails() {
	cout << "Class Session ID:   " << ID << endl;
	cout << "Duration:           " << duration << endl;
	cout << "Type:               " << type << endl;
	cout << "Location:           " << Location << endl;
	cout << "Coach ID:           " << coachID << endl;
	cout << "Capacity:           " << capacity << endl;
	cout << "Members registered: " << registeredMembers.size() << endl;
	cout << "VIP Waiting list:   " << VIPwaitingList.size() << endl;
	cout << "Waiting list:       " << waitingList.size() << endl;
	Date::printDate(date);
	Date::printTime12(time);
}
void classSession::printWaitingList() {
	cout << "Please chose option:" << endl;
	cout << "1. View waiting list" << endl;
	cout << "2. View VIP waiting list" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		if (waitingList.empty()) {

			cout << FG_WHITE << BG_RED << u8"\t\t╔═══════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║   No members in the waiting list  ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═══════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
		else {
			cout << "Waiting List: ";
			queue<int> tempQueue = waitingList;
			while (!tempQueue.empty()) {
				cout << tempQueue.front() << " ";
				tempQueue.pop();
			}
			cout << endl;
		}
	}
	else if (choice == 2) {
		if (VIPwaitingList.empty()) {

			cout << FG_WHITE << BG_RED << u8"\t\t╔════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║   No VIP members in the waiting list   ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
		else {
			cout << "VIP Waiting List: ";
			queue<int> tempQueue = VIPwaitingList;
			while (!tempQueue.empty()) {
				cout << tempQueue.front() << " ";
				tempQueue.pop();
			}
			cout << endl;
		}
	}
	else {

		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 1-2) ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
	}
}
void classSession::printRegisteredMembers() {
	if (registeredMembers.empty()) {

		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║    No registered members    ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
	}
	else {
		cout << "Registered Members: ";
		for (int memberID : registeredMembers) {
			cout << memberID << " ";
		}
		cout << endl;
	}
}
void classSession::printClassVector(vector<vector<classSession>>& classSessions) {
	cout << "Class Sessions:" << endl;
	for (int i = 0; i < classSessions.size(); i++) {
		cout << "===========================================\n";
		cout << "Day " << i + 1 << ":" << endl;
		for (int j = 0; j < classSessions[i].size(); j++) {
			classSessions[i][j].printDetails();
			cout << endl;
		}
	}
}
void classSession::addMember(int memberID, vector<vector<classSession>>& classSessions, map<int, member>& members) {
	printClassVector(classSessions);
	bool found = false;
	cout << "Enter the day of the week (1-7): ";
	int day;
	cin >> day;
	cout << "Enter the session ID: ";
	int sessionID;
	cin >> sessionID;
	if (!members[memberID].getSub().getIsValid()) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║       Subscription is not valid!!       ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║       you can not attend a class        ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return;
	}
	if (day < 1 || day > 7) {

		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║              Invalid day!!              ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║  Please enter a number between 1 and 7  ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return;
	}
	for (int i = 0; i < classSessions[day - 1].size(); i++)
	{
		if (classSessions[day - 1][i].getID() == sessionID) {
			found = true;
			if (classSessions[day - 1][i].getRegisteredMembers().size() < classSessions[day - 1][i].getCapacity()) {
				classSessions[day - 1][i].registeredMembers.push_back(memberID);
				cout << FG_WHITE << BG_GREEN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
				cout << FG_WHITE << BG_GREEN << u8"\t\t║   Member " << memberID << u8" added to the session   ║" << RESET << endl;
				cout << FG_WHITE << BG_GREEN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl << endl;
				Sleep(500);
			}
			else {
				classSessions[day - 1][i].addToWaitingList(memberID, members);
				cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════════════════════════════════════════╗" << RESET << endl;
				cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║  Session is full. Member " << memberID << u8" added to the waiting list  ║" << RESET << endl;
				cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════════════════════════════════════════╝" << RESET << endl << endl;
				Sleep(500);
			}
			return;
		}
	}
	if (!found) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║    Session not found    ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
	}
}
void classSession::removeMember(int memberID, vector<vector<classSession>>& classSessions, map<int, member>& members) {
	int classID;
	cout << "Enter the class ID to remove member from: ";
	cin >> classID;
	bool found = false;
	for (int i = 0; i < classSessions.size(); i++) {
		for (int j = 0; j < classSessions[i].size(); j++) {
			if (classSessions[i][j].getID() == classID) {
				found = true;
				auto it = find(classSessions[i][j].registeredMembers.begin(), classSessions[i][j].registeredMembers.end(), memberID);
				if (it != classSessions[i][j].registeredMembers.end()) {
					classSessions[i][j].registeredMembers.erase(it);
					cout << FG_WHITE << BG_GREEN << u8"\t\t╔════════════════════════════════════════╗" << RESET << endl;
					cout << FG_WHITE << BG_GREEN << u8"\t\t║  Member " << memberID << u8" removed from the session  ║" << RESET << endl;
					cout << FG_WHITE << BG_GREEN << u8"\t\t╚════════════════════════════════════════╝" << RESET << endl << endl;
					Sleep(500);
					if (!classSessions[i][j].VIPwaitingList.empty()) {
						int nextMemberID = classSessions[i][j].VIPwaitingList.front();
						classSessions[i][j].VIPwaitingList.pop();
						classSessions[i][j].registeredMembers.push_back(nextMemberID);
						cout << FG_WHITE << BG_GREEN << u8"\t\t╔═══════════════════════════════════════════════════════════╗" << RESET << endl;
						cout << FG_WHITE << BG_GREEN << u8"\t\t║ Member " << nextMemberID << u8" moved from waiting list to registered members ║" << RESET << endl;
						cout << FG_WHITE << BG_GREEN << u8"\t\t╚═══════════════════════════════════════════════════════════╝" << RESET << endl << endl;
						Sleep(500);
					}
					else if (!classSessions[i][j].waitingList.empty()) {
						int nextMemberID = classSessions[i][j].waitingList.front();
						classSessions[i][j].waitingList.pop();
						classSessions[i][j].registeredMembers.push_back(nextMemberID);
						cout << FG_WHITE << BG_GREEN << u8"\t\t╔═══════════════════════════════════════════════════════════╗" << RESET << endl;
						cout << FG_WHITE << BG_GREEN << u8"\t\t║ Member " << nextMemberID << u8" moved from waiting list to registered members ║" << RESET << endl;
						cout << FG_WHITE << BG_GREEN << u8"\t\t╚═══════════════════════════════════════════════════════════╝" << RESET << endl << endl;
						Sleep(500);
					}
					else {
						cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
						cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║  No members in the waiting list ║" << RESET << endl;
						cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
						Sleep(500);
					}
					return;
				}
				else {
					cout << FG_WHITE << BG_RED << u8"\t\t╔═══════════════════════════════════╗" << RESET << endl;
					cout << FG_WHITE << BG_RED << u8"\t\t║  Member not found in the session  ║" << RESET << endl;
					cout << FG_WHITE << BG_RED << u8"\t\t╚═══════════════════════════════════╝" << RESET << endl << endl;
					Sleep(500);
					return;
				}
			}
		}
	}
}
void classSession::addToWaitingList(int memberID, map<int, member>& members) {
	if (members[memberID].getSub().getIsVIP()) {
		VIPwaitingList.push(memberID);
		members[memberID].setAddedToClass(true);
		cout << FG_WHITE << BG_GREEN << u8"\t\t╔═══════════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t║ VIP Member " << memberID << u8" added to the VIP waiting list ║" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t╚═══════════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return;
	}
	else {
		waitingList.push(memberID);
		members[memberID].setAddedToClass(true);
		cout << FG_WHITE << BG_GREEN << u8"\t\t╔═══════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t║ Member " << memberID << u8" added to the waiting list ║" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t╚═══════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
	}
}
void classSession::removeFromWaitingList(int memberID) {
	queue<int> tempQueue;
	bool found = false;
	while (!waitingList.empty()) {
		int currentID = waitingList.front();
		waitingList.pop();
		if (currentID == memberID) {
			found = true;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═══════════════════════════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║ Member " << memberID << u8" removed from the waiting list ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═══════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
		else {
			tempQueue.push(currentID);
		}
	}
	waitingList = tempQueue;
	if (!found) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═══════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║ Member " << memberID << u8" not found in the waiting list ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═══════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
	}
}
// == Getters and Setters ============================
int classSession::getID() { return ID; }
string classSession::getDate() { return date; }
string classSession::getTime() { return time; }
string classSession::getDuration() { return duration; }
string classSession::getType() { return type; }
string classSession::getLocation() { return Location; }
int classSession::getCoachID() { return coachID; }
int classSession::getCapacity() { return capacity; }
vector<int> classSession::getRegisteredMembers() { return registeredMembers; }
queue<int> classSession::getWaitingList() { return waitingList; }
queue<int> classSession::getVIPWaitingList() { return waitingList; }
void classSession::setID(int id) { ID = id; }
void classSession::setDate(string& d) { date = d; }
void classSession::setTime(string& t) { time = t; }
void classSession::setDuration(string& dur) { duration = dur; }
void classSession::setType(string& ty) { type = ty; }
void classSession::setLocation(string& loc) { Location = loc; }
void classSession::setCoachID(int& cn) { coachID = cn; }
void classSession::setCapacity(int cap) { capacity = cap; }
void classSession::setRegisteredMembers(vector<int>& members) { registeredMembers = members; }
void classSession::setWaitingList(queue<int>& waiting) { waitingList = waiting; }
void classSession::setVIPWaitingList(queue<int>& waiting) { waitingList = waiting; }