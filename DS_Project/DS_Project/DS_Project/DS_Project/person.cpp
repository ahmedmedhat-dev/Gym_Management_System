#include "person.h"

person::person() {
	ID = 0;
	name = "";
	DOB = "";
	password = "";
	phoneNumber = "";
}
person::person(int ID, string name, string DOB, string pass, string phone) {
	this->ID = ID;
	this->name = name;
	this->DOB = DOB;
	this->password = pass;
	this->phoneNumber = phone;
}
person::~person() {
	// Destructor
}
void person::printDetails() {
	cout << "ID: " << ID << endl;
	// other details will be printed in derived classes
}
void person::changePassword() {
	cout << "Please enter your new password: ";
	string newPass;
	cin >> newPass;
	setPassword(newPass);
	cout << "Password changed successfully!" << endl;
}
void person::changePhoneNumber() {
	cout << "Please enter your new phone number: ";
	string newPhone;
	cin >> newPhone;
	setPhoneNumber(newPhone);
	cout << "Phone number changed successfully!" << endl;
}
void person::changeName() {
	cout << "Please enter your new name: ";
	string newName;
	cin >> newName;
	setName(newName);
	cout << "Name changed successfully!" << endl;
}
// Getters and Setters
string person::getName() {
	return name;
}
string person::getDOB() {
	return DOB;
}
int person::getID() {
	return ID;
}
string person::getPassword() {
	return password;
}
string person::getPhoneNumber() {
	return phoneNumber;
}
void person::setName(string name) {
	this->name = name;
}
void person::setDOB(string DOB) {
	this->DOB = DOB;
}
void person::setID(int ID) {
	this->ID = ID;
}
void person::setPassword(string pass) {
	this->password = pass;
}
void person::setPhoneNumber(string phone) {
	this->phoneNumber = phone;
}

