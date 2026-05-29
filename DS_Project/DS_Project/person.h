#pragma once
#include <iostream>
#include "colors.h"
using namespace std;
class person
{
protected:
	int ID;
	string name;
	string DOB;
	string password;
	string phoneNumber;
public:
	person();
	person(int ID, string name, string DOB, string pass, string phone);
	~person();
	virtual void printDetails() = 0;
	void changePassword();
	void changePhoneNumber();
	void changeName();
	// Getters and Setters
	string getName();
	string getDOB();
	int getID();
	string getPassword();
	string getPhoneNumber();
	void setName(string name);
	void setDOB(string DOB);
	void setID(int ID);
	void setPassword(string pass);
	void setPhoneNumber(string phone);
};

