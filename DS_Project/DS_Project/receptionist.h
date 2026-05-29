#pragma once
#include "staff.h"
#include <iostream>
#include "colors.h"
using namespace std;
class receptionist : public staff
{
public:
	receptionist();
	receptionist(int id, string name, string DOB, string password, string phoneNumber);
	~receptionist();
	void managePersonalInfo();
	void EditPersonalInfo();
};
