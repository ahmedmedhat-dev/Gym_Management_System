#include "admin.h"

admin::admin() {};
admin::~admin() {};
// manage coaches
void admin::manageCoaches(map<int, coach>& coaches) {
	int option;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║             Manage coaches           ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl;
		cout << "1. Add new coach\n";
		cout << "2. Search for coach\n";
		cout << "3. View all coaches\n";
		cout << "0. Exit\n";
		cin >> option;
		switch (option) {
		case 1: addCoach(coaches); break;
		case 2: searchCoach(coaches); break;
		case 3: viewAllCoaches(coaches); break;
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
void admin::addCoach(map<int, coach>& coaches)
{
	string name, DOB, password, phoneNumber;
	cout << "Enter name: ";
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
	int ID = 5000 + coaches.size();
	coaches[ID] = coach(ID, name, DOB, password, phoneNumber);
	cout << FG_WHITE << BG_GREEN << u8"\t\t╔═══════════════════════════════╗" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║    Coach added successfully   ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║    Coach ID is : " << ID << u8"         ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t╚═══════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
}
void admin::searchCoach(map<int, coach>& coaches) {
	string searchName;
	int id;
	bool found = false;
	int option;
	cout << "   Please choose an option:\n";
	cout << "1. Search with name\n";
	cout << "2. Search with ID\n";
	cin >> option;
	switch (option) {
	case 1:
		cout << "Enter name to search: ";
		cin.ignore(1, '\n');
		getline(cin, searchName);
		for (auto& coach : coaches) {
			if (coach.second.getName() == searchName) {
				coach.second.printDetails();
				found = true;
			}
		}
		if (!found) {
			cout << FG_WHITE << BG_RED << u8"\t\t═════════════════════════════════" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t  No coach found with name: " << searchName << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t═════════════════════════════════" << RESET << endl << endl;
			Sleep(500);
		}
		break;
	case 2:
		cout << "Enter the id: ";
		cin >> id;
		if (coaches.count(id)) {
			coaches[id].printDetails();
			found = true;
		}
		else {
			cout << FG_WHITE << BG_RED << u8"\t\t══════════════════════════════════" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t      No coach found with ID: " << id << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t══════════════════════════════════" << RESET << endl << endl;
			Sleep(500);
		}
		break;
	default:
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 1-2) ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		break;
	}
}
void admin::viewAllCoaches(map<int, coach>& coaches) {
	if (coaches.size() == 0) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔══════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║    There is no coaches   ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚══════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return;
	}
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║      Viewing all coaches...     ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
	cout << "===================================================\n";
	for (auto& coach : coaches) {
		coach.second.printDetails();
		cout << "===================================================\n";
	}
}
// manage receptionists
void admin::manageReceptionists(map<int, receptionist>& receptionists)
{
	int option;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║         Manage receptionists         ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl;
		cout << "1. Add new receptionist\n";
		cout << "2. Search for receptionist\n";
		cout << "3. View all receptionists\n";
		cout << "0. Exit\n";
		cin >> option;
		switch (option)
		{
		case 1: addReceptionist(receptionists); break;
		case 2: searchReceptionist(receptionists); break;
		case 3: viewAllReceptionists(receptionists); break;
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
void admin::addReceptionist(map<int, receptionist>& receptionists)
{
	string name, DOB, password, phoneNumber;
	cout << "Enter name: ";
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
	int ID = 8000 + receptionists.size();
	receptionists[ID] = receptionist(ID, name, DOB, password, phoneNumber);
	cout << FG_WHITE << BG_GREEN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║    Receptionist added successfully   ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║    Receptionist ID is : " << ID << u8"         ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
}
void admin::searchReceptionist(map<int, receptionist>& receptionists)
{
	string searchName;
	int id;
	bool found = false;
	int option;
	cout << "   Please choose an option:\n";
	cout << "1. Search with name\n";
	cout << "2. Search with ID\n";
	cin >> option;
	switch (option)
	{
	case 1:
		cout << "Enter name to search: ";
		cin.ignore(1, '\n');
		getline(cin, searchName);
		for (auto& receptionist : receptionists) {
			if (receptionist.second.getName() == searchName) {
				receptionist.second.printDetails();
				found = true;
			}
		}
		if (!found) {
			cout << FG_WHITE << BG_RED << u8"\t\t═════════════════════════════════════" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t No receptionist found with name: " << searchName << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t═════════════════════════════════════" << RESET << endl << endl;
			Sleep(500);
		}
		break;
	case 2:
		cout << "Enter the id: ";
		cin >> id;
		if (receptionists.count(id)) {
			receptionists[id].printDetails();
			found = true;
		}
		else {
			cout << FG_WHITE << BG_RED << u8"\t\t═════════════════════════════════════" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t   No receptionist found with ID: " << id << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t═════════════════════════════════════" << RESET << endl << endl;
			Sleep(500);
		}
		break;
	default:
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 1-2) ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		break;
	}
}
void admin::viewAllReceptionists(map<int, receptionist>& receptionists) {
	if (receptionists.size() == 0) {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═══════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║     There is no receptionists     ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═══════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return;
	}
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║   Viewing all receptionists...  ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
	cout << "===================================================\n";
	for (auto& receptionist : receptionists) {
		receptionist.second.printDetails();
		cout << "===================================================\n";
	}
}
// padel courts
void admin::managePadelCourts(map<int, padelCourt>& courts) {
	int option;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║         Manage padel courts          ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl;
		cout << "1. Add new padel court\n";
		cout << "2. Search for padel court\n";
		cout << "3. View all padel courts\n";
		cout << "0. Exit\n";
		cin >> option;
		switch (option)
		{
		case 1: addPadelCourt(courts); break;
		case 2: searchPadelCourt(courts); break;
		case 3: padelCourt::displayCourts(courts); break;
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
void admin::addPadelCourt(map<int, padelCourt>& courts)
{
	string name, location;
	cout << "Enter name: ";
	cin.ignore(1, '\n');
	getline(cin, name);
	cout << "Enter location: ";
	getline(cin, location);
	int ID = 2000 + courts.size();
	courts[ID] = padelCourt(ID, location);
	cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════════════════════╗" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║    Padel court added successfully   ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║    Padel court ID is : " << ID << u8"         ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
}
void admin::searchPadelCourt(map<int, padelCourt>& courts)
{
	int id;
	bool found = false;
	cout << "Enter court  ID: ";
	cin >> id;
	if (courts.count(id)) {
		courts[id].printDetails();
		found = true;
	}
	else {
		cout << FG_WHITE << BG_RED << u8"\t\t══════════════════════════════════════" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t    No padel court found with ID: " << id << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t══════════════════════════════════════" << RESET << endl << endl;
		Sleep(500);
	}
}
// manage workouts
void admin::manageWorkouts(vector<workout>& workouts) {
	int option;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║            Manage workouts           ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   please chose an option:\n";
		cout << "1. Add new workout\n";
		cout << "2. View all workouts\n";
		cout << "0. Exit\n";
		cin >> option;
		switch (option) {
		case 1: addWorkout(workouts); break;
		case 2: viewAllWorkouts(workouts); break;
		case 0:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-2) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		}
	} while (option != 0);
}
void admin::addWorkout(vector<workout>& workouts)
{
	string workoutName, workoutType, description;
	int duration;
	cout << "Enter workout name: ";
	cin.ignore(1, '\n');
	getline(cin, workoutName);
	cout << "Enter workout type: ";
	getline(cin, workoutType);
	cout << "Enter duration (in minutes): ";
	cin >> duration;
	cout << "Enter description: ";
	cin.ignore(1, '\n');
	getline(cin, description);
	workouts.push_back(workout(workoutName, workoutType, duration, description));
	cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║    Workout added successfully   ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
}
void admin::viewAllWorkouts(vector<workout>& workouts) {
	cout << "===================================================\n";
	for (auto& workout : workouts) {
		workout.pWorkoutWithoutDate();
		cout << "===================================================\n";
	}
}
// manage subscription cost
void admin::manageSubscriptionCost() {
	int option;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║       Manage subscription cost       ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please chose an option:\n";
		cout << "1. Change subscription cost\n";
		cout << "2. View subscriptions costs\n";
		cout << "0. Exit\n";
		cin >> option;
		switch (option) {
		case 1: changeSubscriptionCost(); break;
		case 2: subscription::displayCost(); break;
		case 0:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-2) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		}
	} while (option != 0);
}
void admin::changeSubscriptionCost()
{
	subscription::displayCost();
	int option;
	cout << "Enter the subscription type to change cost (1-5): ";
	cin >> option;
	int newCost;
	cout << "Enter new cost: ";
	cin >> newCost;
	switch (option)
	{
	case 1: subscription::costOfmonthlySub = newCost; break;
	case 2: subscription::costOfThreeMonthsSub = newCost; break;
	case 3: subscription::costOfSixMonthsSub = newCost; break;
	case 4: subscription::costOfyearlySub = newCost; break;
	case 5: subscription::costOfVIPSub = newCost; break;
	default:
		cout << FG_WHITE << BG_RED << u8"\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t║ Please enter a correct option (num 1-5) ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		break;
	}
}
//********************* fun below need to be completed **************
void admin::manageReports(vector<string>& reports, map<int, coach>& coaches, map<int, receptionist>& receptionists, map<int, member>& members, vector<vector<classSession>>& classSessions, vector<booking>& bookings) {
	int option;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║            Manage Reports            ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   please chose an option:\n";
		cout << "1. Make new report\n";
		cout << "2. View report\n";
		cout << "0. Exit\n";
		cin >> option;
		string report = "";
		switch (option) {
		case 1:
			report += reportGenerator::Counts(coaches, receptionists, members);
			report += reportGenerator::classReport(classSessions);
			report += reportGenerator::getTopPadelCourtBooker(bookings);
			cout << report;
			reports.push_back(report);
			break;
		case 2:
			cout << "What report do you want to view: " << endl;
			for (int i = 0; i < reports.size(); i++) {
				cout << "Report Number " << i + 1 << endl;
			}
			int a;
			cin >> a;
			if (a < 0 || a >= reports.size()) {
				cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
				cout << FG_WHITE << BG_RED << u8"\t\t║      Please enter a correct option      ║" << RESET << endl;
				cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			}
			else {
				cout << reports[a - 1];
			}
			break;
		case 0:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-2) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		}
	} while (option != 0);
}
