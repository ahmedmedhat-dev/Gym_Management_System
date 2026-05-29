#pragma once
#include "common_include.h"
#include "colors.h"
class gymSystemManager
{
	map<int, member> members;
	map<int, coach> coaches;
	map<int, receptionist> receptionists;
	vector<vector<classSession>> classSessions = vector<vector<classSession>>(7);
	map<int, padelCourt> courts;
	vector<workout> workouts;
	vector<booking> bookings;
	vector<string> reports;
	vector<string> trainingProgram;
public:
	gymSystemManager();
	~gymSystemManager();
	void startSystem();
	void login();
	void signUp();
	void memberMenu(int mIndex);
	void adminMenu();
	void coachMenu(int cIndex);
	void receptionistMenu(int rIndex);
	void memberSubCheck();
	// == Files ===================================
	void loadData();
	void saveData();
	// == Save ====================================
	void saveCounters();
	void saveMembersFile();
	void saveCoachesFile();
	void saveReceptionistsFile();
	void saveClassSessionsFile();
	void saveCcourtsFile();
	void saveWorkoutsFile();
	void saveBookingsFile();
	void saveReportsFile();
	void saveCost();
	void saveTrainingFile();
	// == Load ====================================
	void loadCounters(int& membersCount, int& coachesCount, int& receptionistsCount, int& courtsCount, int& workoutsCount, int& bookingsCount, int& reportsCount);
	void loadMembersFile(int membersCount);
	void loadCoachesFile(int coachesCount);
	void loadReceptionistsFile(int receptionistsCount);
	void loadClassSessionsFile();
	void loadCcourtsFile(int courtsCount);
	void loadWorkoutsFile(int workoutsCount);
	void loadBookingsFile(int bookingsCount);
	void loadReportsFile(int& reportsCount);
	void loadCost();
	void loadTrainingFile();
};