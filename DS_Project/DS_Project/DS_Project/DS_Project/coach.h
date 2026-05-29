#pragma once
#include "staff.h"
#include "colors.h"
class coach : public staff
{
public:

	coach();
	coach(int ID, string name, string DOB, string pass, string phone);
	~coach();
	void classes_quick_lookup(vector<vector<classSession>>& classSessions);
	void managePersonalInfo();
	void EditPersonalInfo();
};

