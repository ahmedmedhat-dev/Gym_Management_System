#include "Receptionist.h"

receptionist::receptionist() {
	// Default constructor implementation
}
receptionist::receptionist(int id, string name, string DOB, string password, string phoneNumber)
	: staff(id, name, DOB, password, phoneNumber) {
	// Parameterized constructor implementation
}
receptionist::~receptionist() {
	// Destructor implementation
}
void receptionist::managePersonalInfo()
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
		case 1: printDetails(); break;
		case 2: EditPersonalInfo(); break;
		case 3:
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
	} while (choice != 0);
}
void receptionist::EditPersonalInfo() {
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