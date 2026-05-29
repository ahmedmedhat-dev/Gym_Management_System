#include "member.h"
// == Constructors and Destructor ========================
member::member() : person() {
	sub = subscription();
}
member::member(int ID, string name, string DOB, string pass, string phone, subscription sub, int T, bool addedToClass) : person(ID, name, DOB, pass, phone) {
	this->sub = sub;
	TrainingIndex = T;
	this->addedToClass = addedToClass;
}
member::member(int Id, string name, string DOB, string pass, string phone) : person(Id, name, DOB, pass, phone) {
	sub = subscription();
}
member::~member() {
	// Destructor implementation
}
// == Functions ==========================================
void member::printDetails() {
	cout << "ID:                " << ID << endl;
	cout << "Name:              " << name << endl;
	cout << "Date of birth:     " << DOB << endl;
	cout << "Phone Number:      " << phoneNumber << endl;
	cout << "Subscription type: " << sub.getSubType() << endl;
	cout << "Valid:             " << (sub.getIsValid() ? "Yes" : "No") << endl;
	cout << "VIP Status:        " << (sub.getIsVIP() ? "Yes" : "No") << endl;
}
// == num1 manage subscription ===========================
void member::Subsribtion()
{
	int choice;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║          Manage Subscription         ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "Please choose an option:" << endl
			<< "1. Renew  your  subscription" << endl
			<< "2. Change your  subscription" << endl
			<< "3. Show   your  subscription" << endl
			<< "0. Exit" << endl;
		cin >> choice;
		if (choice == 1) { Renew_Sub(); }
		else if (choice == 2) { Change_Sub(); }
		else if (choice == 3) { sub.displaySubDetails(); }
		else if (choice == 0) {
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
		else {
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-3) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
	} while (choice != 0);
}
void member::Renew_Sub()
{
	string answer = "y";
	if (sub.getIsValid()) {
		cout << "your subscription is still valid" << endl;
		cout << "do you want to renew it any way [Y/N] ?" << endl;
		cin >> answer;
	}
	if (answer == "y" || answer == "Y") { Change_Sub(); }
	else {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═══════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║   Invalid input   ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═══════════════════╝" << RESET << endl << endl;
		Sleep(500);
	}
}
void member::Change_Sub() {
	subscription::displayCost();
	int newtype;
	cout << "choose the subscription type : " << endl;
	cout << "[1] Monthly      subscription" << endl;
	cout << "[2] There months subscription" << endl;
	cout << "[3] Six months   subscription" << endl;
	cout << "[4] Yearly       subscription" << endl;
	cout << "[5] VIP          subscription" << endl;
	cin >> newtype;
	switch (newtype) {
	case 1:
		sub.changeSub(ID, "Monthly subscription", Date::getCurrentDate(), Date::addDays(30), 30, true, false);
		break;
	case 2:
		sub.changeSub(ID, "Three months subscription", Date::getCurrentDate(), Date::addDays(90), 90, true, false);
		break;
	case 3:
		sub.changeSub(ID, "Six months subscription", Date::getCurrentDate(), Date::addDays(180), 180, true, false);
		break;
	case 4:
		sub.changeSub(ID, "Yearly subscription", Date::getCurrentDate(), Date::addDays(360), 360, true, false);
		break;
	case 5:
		sub.changeSub(ID, "VIP subscription", Date::getCurrentDate(), Date::addDays(360), 360, true, true);
		break;
	default:
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 1-5) ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		break;
	}
}
// == num2 workouts ======================================
void member::workouts(vector<workout>& workouts) {
	cout << "*****************************************\n";
	cout << "        Please chose an option:" << endl;
	cout << "1. Add workout to your history" << endl;
	cout << "2. View your workout history" << endl;
	cout << "3. View all workouts" << endl;
	cout << "0. Exit" << endl;
	int choice;
	cin >> choice;
	workout W;
	switch (choice) {
	case 1: W.addWorkoutToMember(workouts, WorkoutHistory); break;
	case 2:
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║  Viewing your workout history... ║" << RESET << endl;
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		W.pWorkoutVector(WorkoutHistory);
		break;
	case 3:
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║   Viewing all workouts...  ║" << RESET << endl;
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		W.pWorkoutVector(workouts);
		break;
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
}
// == num3 training program ==============================
void member::TrainingProgram(vector<string>& T) {
	cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_CYAN << u8"\t\t║        Manage training program       ║" << RESET << endl;
	cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
	cout << "Please chose an option:" << endl;
	cout << "1. Subscribe to training program\n";
	cout << "2. View training programs\n";
	cout << "3. View my training program\n";
	cout << "0. Exit\n";
	int option;
	cin >> option;
	if (option == 1) {
		for (int i = 0; i < T.size(); i++) {
			cout << "Training program number: " << i;
			cout << "______________________________________\n";
			cout << T[i] << endl;
			cout << "______________________________________\n";
		}
	}
	else if (option == 2) {
		for (int i = 0; i < T.size(); i++) {
			cout << "Training program number: " << i;
			cout << "______________________________________\n";
			cout << T[i] << endl;
			cout << "______________________________________\n";
		}
	}
	else if (option == 3) {
		if (TrainingIndex != -1) {
			cout << "Your training program: " << endl;
			cout << "______________________________________\n";
			cout << T[TrainingIndex] << endl;
			cout << "______________________________________\n";
		}
		else {
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║  You do not have any training program   ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
	}
	else if (option == 0) {
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return;
	}
	else {
		cout << FG_WHITE << BG_RED << u8"\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t║ Please enter a correct option (num 0-3) ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
	}
}
// == num4 padel court booking ===========================
void member::PadelCourt(map<int, padelCourt>& courts, vector<booking>& books)
{
	cout << "*****************************************\n";
	cout << "        Please chose an option:" << endl;
	cout << "1. Book a court" << endl;
	cout << "2. Cancel a booking" << endl;
	cout << "3. View your bookings" << endl;
	cout << "4. View all courts" << endl;
	cout << "0. Exit" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1: courts[1].bookCourt(ID, books, courts); break;
	case 2: courts[1].cancelBook(ID, books, courts); break;
	case 3: booking::pBookByID(books, ID); break;
	case 4: padelCourt::displayCourts(courts); break;
	case 0:
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
		cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		break;
	default:
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-4) ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		break;
	}
}
// == num5 class sessions ================================
void member::Class_Sessions(vector<vector<classSession>>& classSessions, map<int, member>members)
{
	if (sub.getIsValid()) {
		int choice;
		cout << "*****************************************\n";
		cout << "   Please chose an option:" << endl;
		cout << "1. Join class " << endl;
		cout << "2. Cancel class" << endl;
		cout << "0. Exit " << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			classSession::addMember(ID, classSessions, members);
			break;
		case 2:
			classSession::removeMember(ID, classSessions, members);
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
	}
	else {
		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║     Your subscription is not valid!!    ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║       renew your subscription first     ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
		Sleep(500);
	}

}
// == num6 manage personal information ===================
void member::managePersonalInfo()
{
	int choice;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║          Manage Personal Info        ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl;
		cout << "1. View Personal Data " << endl;
		cout << "2. Edit Personal Data " << endl;
		cout << "0. Exit " << endl << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║     Viewing Personal Info...    ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			printDetails();
			break;
		case 2: EditPersonalInfo(); break;
		case 0:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			return;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-2) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
		}
	} while (choice != 0);
}
void member::EditPersonalInfo() {
	int input;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║          Edit Personal Info          ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl;
		cout << "1. Edit Name" << endl;
		cout << "2. Edit Date of Birth" << endl;
		cout << "3. Edit Password" << endl;
		cout << "4. Edit Phone Number" << endl;
		cout << "0. Exit" << endl;
		cin >> input;
		string newName, newDOB, newPassword, newPhone;
		switch (input) {
		case 1:
			cout << "Enter new name: ";
			cin.ignore(1, '\n');
			getline(cin, newName);
			setName(newName);
			cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t║    Name updated successfully    ║" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		case 2:
			cout << "Enter new Date of Birth: ";
			cin >> newDOB;
			setDOB(newDOB);
			cout << FG_WHITE << BG_GREEN << u8"\t\t╔════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t║ Date of Birth updated successfully ║" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t╚════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		case 3:
			cout << "Enter new password: ";
			cin >> newPassword;
			setPassword(newPassword);
			cout << FG_WHITE << BG_GREEN << u8"\t\t╔═════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t║  Password updated successfully  ║" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t╚═════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		case 4:
			cout << "Enter new phone number: ";
			cin >> newPhone;
			setPhoneNumber(newPhone);
			cout << FG_WHITE << BG_GREEN << u8"\t\t╔═══════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t║ Phone number updated successfully ║" << RESET << endl;
			cout << FG_WHITE << BG_GREEN << u8"\t\t╚═══════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		case 0:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-4) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		}
	} while (input != 0);
}
// == Getters and Setters ================================
subscription member::getSub() { return sub; }
vector<workout> member::getWorkoutHistory() { return WorkoutHistory; }
int member::getTrainingIndex() { return TrainingIndex; }
bool member::getAddedToClass() { return addedToClass; }
void member::setWorkoutHistory(vector<workout> workoutHistory) { WorkoutHistory = workoutHistory; }
void member::setSub(subscription subscriptionID) { sub = subscriptionID; }
void member::setTrainingIndex(int t) { TrainingIndex = t; }
void member::setAddedToClass(bool a) { addedToClass = a; }