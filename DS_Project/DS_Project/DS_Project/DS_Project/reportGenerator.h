#pragma once
#include <iostream>
#include <vector>
#include "member.h"
#include "receptionist.h"
#include "coach.h"
#include "classSession.h"
#include "PadelCourt.h"
#include <unordered_map>
#include "colors.h"
using namespace std;

class reportGenerator
{
public:
	reportGenerator();
	~reportGenerator();
	static string Counts(map<int, coach>& coaches, map<int, receptionist>& receptionists, map<int, member>& members);
	static string classReport(vector<vector<classSession>>& classSessions);
	static string getTopPadelCourtBooker(vector<booking>& bookings);
};

