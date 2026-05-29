#include "gymSystemManager.h"

gymSystemManager::gymSystemManager() {
	// Constructor implementation
}
gymSystemManager::~gymSystemManager() {
	// Destructor implementation
}
void gymSystemManager::startSystem() {
	int choice;
	memberSubCheck();
	do {
		system("cls");
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔════════════════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║   👋 Welcome to the Gym 🏋️ and Padel System!   ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚════════════════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl
			<< "1. Login" << endl
			<< "2. Sign Up" << endl
			<< "0. Exit" << endl;
		cin >> choice;
		if (choice == 1) { login(); }
		else if (choice == 2) { signUp(); }
		else if (choice == 0) {
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║      Exiting the system...      ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
			Sleep(1000);
		}
		else {
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║        Invalid choice!!         ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║       Please try again.         ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
			Sleep(3000);
		}
	} while (choice != 0);
}
void gymSystemManager::login() {
	cout << "Please enter your ID: ";
	int ID;
	cin >> ID;
	cout << "Please enter your password: ";
	string password;
	cin >> password;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║          Logging in...          ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
	Sleep(1000);
	if (ID == 123 && password == "admin") { adminMenu(); }
	else if (members.count(ID)) {
		cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t║         Login successful!       ║" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		memberMenu(ID);
		return;
	}
	else if (coaches.count(ID)) {
		cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t║         Login successful!       ║" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		coachMenu(ID);
		return;
	}
	else if (receptionists.count(ID)) {
		cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t║         Login successful!       ║" << RESET << endl;
		cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		receptionistMenu(ID);
		return;
	}
	else {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║          Login failed!!         ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║        Please try again         ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
		Sleep(2000);
		startSystem();
	}

}
void gymSystemManager::signUp() {
	staff::addMember(members);
	startSystem();
	Sleep(2000);
}
void gymSystemManager::memberMenu(int mID) {
	int choice;
	do {
		if (members[mID].getAddedToClass()) {
			system("cls");
			cout << FG_BLACK << BG_YELLOW << u8"\t\t╔════════════════════════════════════════════╗" << RESET << endl;
			cout << FG_BLACK << BG_YELLOW << u8"\t\t║  You have been added to the class session  ║" << RESET << endl;
			cout << FG_BLACK << BG_YELLOW << u8"\t\t║      and removed from waiting list :)      ║" << RESET << endl;
			cout << FG_BLACK << BG_YELLOW << u8"\t\t╚════════════════════════════════════════════╝" << RESET << endl << endl;
			members[mID].setAddedToClass(false);
			string a;
			cout << "Press any key to continue....\n";
			cin >> a;
		}
		if (!members[mID].getSub().getIsValid()) {
			system("cls");
			cout << FG_BLACK << BG_YELLOW << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
			cout << FG_BLACK << BG_YELLOW << u8"\t\t║   Your subscription is not valid :(  ║" << RESET << endl;
			cout << FG_BLACK << BG_YELLOW << u8"\t\t║           Please renew it!!!         ║" << RESET << endl;
			cout << FG_BLACK << BG_YELLOW << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl << endl;
			string a;
			cout << "Press any key to continue....\n";
			cin >> a;
		}
		if (Date::isDateWithinAWeek(members[mID].getSub().getSubEndDate())) {
			system("cls");
			cout << FG_BLACK << BG_YELLOW << u8"\t\t╔════════════════════════════════════════╗" << RESET << endl;
			cout << FG_BLACK << BG_YELLOW << u8"\t\t║    Your subscription about to end :(   ║" << RESET << endl;
			cout << FG_BLACK << BG_YELLOW << u8"\t\t║     remember to renew it nearly !!!    ║" << RESET << endl;
			cout << FG_BLACK << BG_YELLOW << u8"\t\t╚════════════════════════════════════════╝" << RESET << endl << endl;
			string a;
			cout << "Press any key to continue....\n";
			cin >> a;
		}
		system("cls");
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║      👋 Welcome to Member Menu       ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl
			<< "1. Subscription" << endl
			<< "2. Workouts" << endl
			<< "3. Training program" << endl
			<< "4. Padel court booking" << endl
			<< "5. Class sessions" << endl
			<< "6. Manage personal information" << endl
			<< "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1) { members[mID].Subsribtion(); }
		else if (choice == 2) { members[mID].workouts(workouts); }
		else if (choice == 3) { members[mID].TrainingProgram(trainingProgram); }
		else if (choice == 4) { members[mID].PadelCourt(courts, bookings); }
		else if (choice == 5) { members[mID].Class_Sessions(classSessions, members); }
		else if (choice == 6) { members[mID].managePersonalInfo(); }
		else if (choice == 0) {
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║      Exiting member menu...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
			Sleep(1000);
		}
		else {
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-3) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(2000);
		}
	} while (choice != 0);
}
void gymSystemManager::adminMenu() {
	int choice;
	do {
		system("cls");
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║      👋 Welcome to Admin Menu        ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl
			<< "1. Manage members" << endl
			<< "2. Manage coaches" << endl
			<< "3. Manage receptionists" << endl
			<< "4. Manage padel courts" << endl
			<< "5. Manage workouts" << endl
			<< "6. Manage subscription cost" << endl
			<< "7. Manage training programs" << endl
			<< "8. Manage bookings" << endl
			<< "9. Manage class sessions" << endl
			<< "10.Manage reports" << endl
			<< "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: staff::manageMembers(members, classSessions, courts, bookings); break;
		case 2: admin::manageCoaches(coaches); break;
		case 3: admin::manageReceptionists(receptionists); break;
		case 4: admin::managePadelCourts(courts); break;
		case 5: admin::manageWorkouts(workouts); break;
		case 6: admin::manageSubscriptionCost(); break;
		case 7: staff::manageTrainingPrograms(trainingProgram); break;
		case 8: staff::manageBookings(bookings, courts); break;
		case 9: staff::manageClassSessions(classSessions); break;
		case 10:admin::manageReports(reports, coaches, receptionists, members, classSessions, bookings); break;
		case 0:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting admin menu...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
			Sleep(1000);
			break;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔══════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-10) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚══════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(2000);
			break;
		}
	} while (choice != 0);
}
void gymSystemManager::coachMenu(int cIndex) {
	int choice;
	do {
		system("cls");
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║      👋 Welcome to Coach Menu        ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl
			<< "1. Manage members" << endl
			<< "2. Manage class sessions" << endl
			<< "3. Manage personal information" << endl
			<< "4. classes quick lookup" << endl
			<< "0. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1: staff::manageMembers(members, classSessions, courts, bookings); break;
		case 2: staff::manageClassSessions(classSessions); break;
		case 3: coaches[cIndex].managePersonalInfo(); break;
		case 4: coaches[cIndex].classes_quick_lookup(classSessions);
		case 0:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting coach menu...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
			Sleep(1000);
			break;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-4) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(2000);
			break;
		}
	} while (choice != 0);
}
void gymSystemManager::receptionistMenu(int rIndex) {
	int choice;
	do {
		system("cls");
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║   👋 Welcome to Receptionist Menu    ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl
			<< "1. Manage bookings" << endl
			<< "2. Manage class sessions" << endl
			<< "3. Manage personal information" << endl
			<< "0. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1: staff::manageBookings(bookings, courts); break;
		case 2: staff::manageClassSessions(classSessions); break;
		case 3: receptionists[rIndex].managePersonalInfo(); break;
		case 0:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║   Exiting receptionist menu...  ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
			Sleep(1000);
			break;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-3) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(2000);
			break;
		}
	} while (choice != 0);
}
void gymSystemManager::memberSubCheck() {
	for (auto& it : members) {
		if (Date::isPastDate(it.second.getSub().getSubEndDate())) {
			subscription s = it.second.getSub();
			s.setIsValid(false);
			it.second.setSub(s);
		}
	}
}
// == Files ===================================
void gymSystemManager::saveData() {
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║     Saving data...   ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
	Sleep(1000);
	saveCounters();
	saveMembersFile();
	saveCoachesFile();
	saveReceptionistsFile();
	saveClassSessionsFile();
	saveCcourtsFile();
	saveWorkoutsFile();
	saveBookingsFile();
	saveReportsFile();
	saveCost();
	saveTrainingFile();
}
void gymSystemManager::loadData() {
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║    loading data...   ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
	Sleep(1000);
	int membersCount, coachesCount, receptionistsCount, courtsCount, workoutsCount, bookingsCount, reportsCount;
	membersCount = coachesCount = receptionistsCount = courtsCount = workoutsCount = bookingsCount = reportsCount = 0;
	loadCounters(membersCount, coachesCount, receptionistsCount, courtsCount, workoutsCount, bookingsCount, reportsCount);
	loadMembersFile(membersCount);
	loadCoachesFile(coachesCount);
	loadReceptionistsFile(receptionistsCount);
	loadClassSessionsFile();
	loadCcourtsFile(courtsCount);
	loadWorkoutsFile(workoutsCount);
	loadBookingsFile(bookingsCount);
	loadReportsFile(reportsCount);
	loadCost();
	loadTrainingFile();
}
// == Save ====================================
void gymSystemManager::saveCounters() {
	fstream counters("database/counters.txt", ios::out);
	if (counters.is_open()) {
		counters << members.size() << endl
			<< coaches.size() << endl
			<< receptionists.size() << endl
			<< courts.size() << endl
			<< workouts.size() << endl
			<< bookings.size() << endl
			<< reports.size() << endl;
		counters.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "     Error opening counters file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::saveMembersFile() {
	fstream membersFile("database/members.txt", ios::out);
	if (membersFile.is_open()) {
		for (auto& it : members) {
			membersFile << it.second.getID() << endl
				<< it.second.getName() << endl
				<< it.second.getDOB() << endl
				<< it.second.getPassword() << endl
				<< it.second.getPhoneNumber() << endl
				<< it.second.getSub().getSubID() << endl
				<< it.second.getSub().getUserID() << endl
				<< it.second.getSub().getSubType() << endl
				<< it.second.getSub().getSubStartDate() << endl
				<< it.second.getSub().getSubEndDate() << endl
				<< it.second.getSub().getSubDuration() << endl
				<< it.second.getSub().getIsValid() << endl
				<< it.second.getSub().getIsVIP() << endl
				<< it.second.getTrainingIndex() << endl
				<< it.second.getAddedToClass() << endl
				<< it.second.getWorkoutHistory().size() << endl;
			for (int y = 0; y < it.second.getWorkoutHistory().size(); y++) {
				membersFile << it.second.getWorkoutHistory()[y].getWorkoutType() << endl
					<< it.second.getWorkoutHistory()[y].getWorkoutName() << endl
					<< it.second.getWorkoutHistory()[y].getDescription() << endl
					<< it.second.getWorkoutHistory()[y].getDuration() << endl
					<< it.second.getWorkoutHistory()[y].getDate() << endl;
			}
		}
		membersFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "      Error opening members file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::saveCoachesFile() {
	fstream coachesFile("database/coaches.txt", ios::out);
	if (coachesFile.is_open()) {
		for (auto& it : coaches) {
			coachesFile << it.second.getID() << endl
				<< it.second.getName() << endl
				<< it.second.getDOB() << endl
				<< it.second.getPassword() << endl
				<< it.second.getPhoneNumber() << endl;
		}
		coachesFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "      Error opening coaches file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::saveReceptionistsFile() {
	fstream receptionistsFile("database/receptionists.txt", ios::out);
	if (receptionistsFile.is_open()) {
		for (auto& it : receptionists) {
			receptionistsFile << it.second.getID() << endl
				<< it.second.getName() << endl
				<< it.second.getDOB() << endl
				<< it.second.getPassword() << endl
				<< it.second.getPhoneNumber() << endl;
		}
		receptionistsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "   Error opening receptionists file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::saveClassSessionsFile() {
	fstream classSessionsFile("database/classSessions.txt", ios::out);
	if (classSessionsFile.is_open()) {
		for (int i = 0; i < 7; i++) {
			classSessionsFile << classSessions[i].size() << endl;
			for (int j = 0; j < classSessions[i].size(); j++) {
				classSessionsFile << classSessions[i][j].getID() << endl
					<< classSessions[i][j].getDuration() << endl
					<< classSessions[i][j].getType() << endl
					<< classSessions[i][j].getLocation() << endl
					<< classSessions[i][j].getCoachID() << endl
					<< classSessions[i][j].getCapacity() << endl
					<< classSessions[i][j].getDate() << endl
					<< classSessions[i][j].getTime() << endl
					<< classSessions[i][j].getRegisteredMembers().size() << endl;
				for (int k = 0; k < classSessions[i][j].getRegisteredMembers().size(); k++) {
					classSessionsFile << classSessions[i][j].getRegisteredMembers()[k] << endl;
				}
				classSessionsFile << classSessions[i][j].getWaitingList().size() << endl;
				queue<int> tempQueue1 = classSessions[i][j].getWaitingList();
				while (!tempQueue1.empty()) {
					classSessionsFile << tempQueue1.front() << endl;
					tempQueue1.pop();
				}
				classSessionsFile << classSessions[i][j].getVIPWaitingList().size() << endl;
				queue<int> tempQueue2 = classSessions[i][j].getVIPWaitingList();
				while (!tempQueue2.empty()) {
					classSessionsFile << tempQueue2.front() << endl;
					tempQueue2.pop();
				}
			}
		}
		classSessionsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "  Error opening class sessions file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::saveCcourtsFile() {
	fstream courtsFile("database/courts.txt", ios::out);
	if (courtsFile.is_open()) {
		for (auto& it : courts) {
			courtsFile << it.second.getCourtID() << endl
				<< it.second.getLocation() << endl;
			for (int y = 0; y < 7; y++) {
				for (int j = 0; j < 24; j++) {
					courtsFile << it.second.getAvailability(y, j) << endl;
				}
			}
		}
		courtsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "     Error opening courts file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::saveWorkoutsFile() {
	fstream workoutsFile("database/workouts.txt", ios::out);
	if (workoutsFile.is_open()) {
		for (int i = 0; i < workouts.size(); i++) {
			workoutsFile << workouts[i].getWorkoutName() << endl
				<< workouts[i].getWorkoutType() << endl
				<< workouts[i].getDuration() << endl
				<< workouts[i].getDate() << endl
				<< workouts[i].getDescription() << endl;
		}
		workoutsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "     Error opening workouts file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::saveBookingsFile() {
	fstream bookingsFile("database/bookings.txt", ios::out);
	if (bookingsFile.is_open()) {
		for (int i = 0; i < bookings.size(); i++) {
			bookingsFile << bookings[i].getBookingID() << endl
				<< bookings[i].getMemberID() << endl
				<< bookings[i].getCourtID() << endl
				<< bookings[i].getDate() << endl
				<< bookings[i].getTime() << endl;
		}
		bookingsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "    Error opening bookings file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::saveReportsFile() {
	fstream reportsFile("database/reports.txt", ios::out);
	if (reportsFile.is_open()) {
		for (int i = 0; i < reports.size(); i++) {
			reportsFile << "Y" << endl;
			reportsFile << reports[i];
		}
		reportsFile << "N" << endl;
		reportsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "      Error opening reports file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::saveCost() {
	fstream cost("database/cost.txt", ios::out);
	if (cost.is_open()) {
		cost << subscription::costOfmonthlySub << endl
			<< subscription::costOfThreeMonthsSub << endl
			<< subscription::costOfSixMonthsSub << endl
			<< subscription::costOfyearlySub << endl
			<< subscription::costOfVIPSub << endl;
		cost.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "      Error opening cost file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::saveTrainingFile() {
	fstream trainingFile("database/trainigFile.txt", ios::out);
	if (trainingFile.is_open()) {
		trainingFile << trainingProgram.size() << endl;
		for (int i = 0; i < trainingProgram.size(); i++) {
			trainingFile << "Y" << endl;
			trainingFile << trainingProgram[i];
		}
		trainingFile << "N" << endl;
		trainingFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "    Error opening training file!!!" << endl;
		cout << "*****************************************\n";
	}
}
// == Load ====================================
void gymSystemManager::loadCounters(int& membersCount, int& coachesCount, int& receptionistsCount, int& courtsCount, int& workoutsCount, int& bookingsCount, int& reportsCount) {
	fstream counters("database/counters.txt", ios::in);
	if (counters.is_open()) {
		counters >> membersCount >> coachesCount >> receptionistsCount >> courtsCount >> workoutsCount >> bookingsCount >> reportsCount;
		counters.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "     Error opening counters file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::loadMembersFile(int membersCount) {
	fstream membersFile("database/members.txt", ios::in);
	if (membersFile.is_open()) {
		while (membersCount != 0) {
			int subID, userID, subDuration, isValid, isVIP, workoutHistorySize, t;
			string name, dob, password, phoneNumber, subType, subStartDate, subEndDate;
			bool a;
			membersFile >> userID;
			membersFile.ignore(1, '\n');
			getline(membersFile, name);
			membersFile >> dob >> password >> phoneNumber >> subID >> userID;
			membersFile.ignore(1, '\n');
			getline(membersFile, subType);
			membersFile >> subStartDate >> subEndDate >> subDuration >> isValid >> isVIP >> t >> a >> workoutHistorySize;
			subscription sub(subID, userID, subType, subStartDate, subEndDate, subDuration, isValid, isVIP);
			member m = member(userID, name, dob, password, phoneNumber, sub, t, a);
			vector<workout> workoutHistory;
			for (int i = 0; i < workoutHistorySize; i++) {
				string workoutType, workoutName, description, date;
				int duration;
				membersFile.ignore(1, '\n');
				getline(membersFile, workoutType);
				getline(membersFile, workoutName);
				getline(membersFile, description);
				membersFile >> duration >> date;
				workout w;
				w.setWorkoutType(workoutType);
				w.setWorkoutName(workoutName);
				w.setDescription(description);
				w.setDuration(duration);
				w.setDate(date);
				workoutHistory.push_back(w);
			}
			m.setWorkoutHistory(workoutHistory);
			members[userID] = m;
			membersCount--;
		}
		membersFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "      Error opening members file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::loadCoachesFile(int coachesCount) {
	fstream coachesFile("database/coaches.txt", ios::in);
	if (coachesFile.is_open()) {
		while (coachesCount != 0) {
			int ID;
			string name, dob, password, phoneNumber;
			coachesFile >> ID;
			coachesFile.ignore(1, '\n');
			getline(coachesFile, name);
			coachesFile >> dob >> password >> phoneNumber;
			coaches[ID] = coach(ID, name, dob, password, phoneNumber);
			coachesCount--;
		}
		coachesFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "      Error opening coaches file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::loadReceptionistsFile(int receptionistsCount) {
	fstream receptionistsFile("database/receptionists.txt", ios::in);
	if (receptionistsFile.is_open()) {
		while (receptionistsCount != 0) {
			int ID;
			string name, dob, password, phoneNumber;
			receptionistsFile >> ID;
			receptionistsFile.ignore(1, '\n');
			getline(receptionistsFile, name);
			receptionistsFile >> dob >> password >> phoneNumber;
			receptionists[ID] = receptionist(ID, name, dob, password, phoneNumber);
			receptionistsCount--;
		}
		receptionistsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "   Error opening receptionists file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::loadClassSessionsFile() {
	fstream classSessionsFile("database/classSessions.txt", ios::in);
	if (classSessionsFile.is_open()) {
		for (int i = 0; i < 7; i++) {
			int size;
			classSessionsFile >> size;
			for (int j = 0; j < size; j++) {
				int id, capacity, registeredSize, waitingSize, vipWaitingSize, coachID;
				string date, time, duration, type, location;
				classSessionsFile >> id >> duration;
				classSessionsFile.ignore(1, '\n');
				getline(classSessionsFile, type);
				getline(classSessionsFile, location);
				classSessionsFile >> coachID >> capacity >> date >> time >> registeredSize;
				classSession cs = classSession(id, date, time, duration, type, location, coachID, capacity);
				vector<int> registeredMembers(registeredSize);
				for (int j = 0; j < registeredSize; j++) {
					classSessionsFile >> registeredMembers[j];
				}
				cs.setRegisteredMembers(registeredMembers);
				classSessionsFile >> waitingSize;
				queue<int> waitingList;
				for (int j = 0; j < waitingSize; j++) {
					int memberID;
					classSessionsFile >> memberID;
					waitingList.push(memberID);
				}
				cs.setWaitingList(waitingList);
				classSessionsFile >> vipWaitingSize;
				queue<int> vipWaitingList;
				for (int j = 0; j < vipWaitingSize; j++) {
					int memberID;
					classSessionsFile >> memberID;
					vipWaitingList.push(memberID);
				}
				cs.setVIPWaitingList(vipWaitingList);
				classSessions[i].push_back(cs);
			}
		}
		classSessionsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "  Error opening class sessions file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::loadCcourtsFile(int courtsCount) {
	fstream courtsFile("database/courts.txt", ios::in);
	if (courtsFile.is_open()) {
		while (courtsCount != 0) {
			padelCourt court;
			int courtID;
			string location;
			courtsFile >> courtID;
			courtsFile.ignore(1, '\n');
			getline(courtsFile, location);
			court.setCourtID(courtID);
			court.setLocation(location);
			bool isAvailable[7][24]{};
			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 24; j++) {
					courtsFile >> isAvailable[i][j];
				}
			}
			court.setAvailability(isAvailable);
			courts[courtID] = court;
			courtsCount--;
		}
		courtsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "     Error opening courts file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::loadWorkoutsFile(int workoutsCount) {
	fstream workoutsFile("database/workouts.txt", ios::in);
	if (workoutsFile.is_open()) {
		while (workoutsCount != 0) {
			workout w;
			string workoutName, workoutType, description, date;
			int duration;
			getline(workoutsFile, workoutName);
			getline(workoutsFile, workoutType);
			workoutsFile >> duration >> date;
			workoutsFile.ignore(1, '\n');
			getline(workoutsFile, description);
			w.setWorkoutName(workoutName);
			w.setWorkoutType(workoutType);
			w.setDuration(duration);
			w.setDate(date);
			w.setDescription(description);
			workouts.push_back(w);
			workoutsCount--;
		}
		workoutsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "     Error opening workouts file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::loadBookingsFile(int bookingsCount) {
	fstream bookingsFile("database/bookings.txt", ios::in);
	if (bookingsFile.is_open()) {
		while (bookingsCount != 0) {
			booking b;
			int bookingID, courtID, memberID;
			string date, time;
			bookingsFile >> bookingID >> memberID >> courtID >> date >> time;
			b.setBookingID(bookingID);
			b.setMemberID(memberID);
			b.setCourtID(courtID);
			b.setDate(date);
			b.setTime(time);
			bookings.push_back(b);
			bookingsCount--;
		}
		bookingsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "    Error opening bookings file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::loadReportsFile(int& reportsCount) {
	fstream reportsFile("database/reports.txt", ios::in);
	if (reportsFile.is_open()) {
		string line, data;
		reportsFile.ignore(1, '\n');
		getline(reportsFile, data);
		for (int i = 0; i < reportsCount; i++) {
			data = "";
			while (true) {
				getline(reportsFile, line);
				if (line == "N" || line == "Y") { break; }
				else {
					data += line + '\n';
				}
			}
			reports.push_back(data);
		}
		reportsFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "      Error opening reports file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::loadCost() {
	fstream cost("database/cost.txt", ios::in);
	if (cost.is_open()) {
		if (!cost.eof()) {
			cost >> subscription::costOfmonthlySub >> subscription::costOfThreeMonthsSub >> subscription::costOfSixMonthsSub
				>> subscription::costOfyearlySub >> subscription::costOfVIPSub;
		}
		cost.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "      Error opening cost file!!!" << endl;
		cout << "*****************************************\n";
	}
}
void gymSystemManager::loadTrainingFile() {
	fstream trainingFile("database/trainigFile.txt", ios::in);
	string line, data;
	int count = 0;
	if (trainingFile.is_open()) {
		trainingFile >> count;
		trainingFile.ignore(1, '\n');
		getline(trainingFile, data);
		for (int i = 0; i < count; i++) {
			data = "";
			while (true) {
				getline(trainingFile, line);
				if (line == "N" || line == "Y") { break; }
				else {
					data += line + '\n';
				}
			}
			trainingProgram.push_back(data);
		}
		trainingFile.close();
	}
	else {
		cout << "*****************************************\n";
		cout << "    Error opening training file!!!" << endl;
		cout << "*****************************************\n";
	}
}
