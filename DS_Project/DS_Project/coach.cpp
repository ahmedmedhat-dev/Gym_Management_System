#include "Coach.h"

coach::coach() : staff() {
	// Default constructor
}
coach::coach(int ID, string name, string DOB, string pass, string phone) : staff(ID, name, DOB, pass, phone) {
	// Parameterized constructor
}
coach::~coach() {
	// Destructor
}
void coach::managePersonalInfo()
{
	int choice;
	do {
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╔══════════════════════════════════════╗" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t║         Manage Personal Info         ║" << RESET << endl;
		cout << FG_YELLOW << BG_CYAN << u8"\t\t╚══════════════════════════════════════╝" << RESET << endl;
		cout << "   Please choose an option:" << endl;
		cout << "1. View Personal Data: " << endl;
		cout << "2. Edit Personal Data: " << endl;
		cout << "0. Exit: " << endl << endl;
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
		case 3:
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╔══════════════════════╗" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t║       Exiting...     ║" << RESET << endl;
			cout << FG_YELLOW << BG_MAGENTA << u8"\t\t╚══════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			return;
		default:
			cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════════════════════════╗" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t║ Please enter a correct option (num 0-3) ║" << RESET << endl;
			cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════════════════════════╝" << RESET << endl << endl;
			Sleep(500);
			break;
		}
	} while (choice != 0);
}
void coach::EditPersonalInfo() {
	int input;
	do {  // Loop until explicitly exited
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
void coach::classes_quick_lookup(vector<vector<classSession>>& classSessions) {
	cout << "your Class Sessions:" << endl;
	for (int i = 0; i < classSessions.size(); i++) {
		cout << "===========================================\n";
		cout << "Day " << i + 1 << ":" << endl;
		for (int j = 0; j < classSessions[i].size(); j++) {
			if (classSessions[i][j].getCoachID() == ID) {
				classSessions[i][j].printDetails();
				cout << endl;
			}
		}
	}for (int i = 0; i < classSessions.size(); i++) {
		cout << "Class " << i + 1 << ": " << classSessions[i].size() << " sessions." << endl;
	}
}