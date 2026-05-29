#pragma once
#include "common_include.h"
#include "colors.h"
class admin
{
public:
	admin();
	~admin();
	// == manage coaches =====================
	static void manageCoaches(map<int, coach>& coaches);
	static void addCoach(map<int, coach>& coaches);
	static void searchCoach(map<int, coach>& coaches);
	static void viewAllCoaches(map<int, coach>& coaches);
	// == manage receptionists ===============
	static void manageReceptionists(map<int, receptionist>& receptionists);
	static void addReceptionist(map<int, receptionist>& receptionists);
	static void searchReceptionist(map<int, receptionist>& receptionists);
	static void viewAllReceptionists(map<int, receptionist>& receptionists);
	// == padel courts =======================
	static void managePadelCourts(map<int, padelCourt>& courts);
	static void addPadelCourt(map<int, padelCourt>& courts);
	static void searchPadelCourt(map<int, padelCourt>& courts);
	// == manage workouts ====================
	static void manageWorkouts(vector<workout>& workouts);
	static void addWorkout(vector<workout>& workouts);
	static void viewAllWorkouts(vector<workout>& workouts);
	// == manage subscription cost ===========
	static void manageSubscriptionCost();
	static void changeSubscriptionCost();
	//=====================
	static void manageReports(vector<string>& reports, map<int, coach>& coaches, map<int, receptionist>& receptionists, map<int, member>& members, vector<vector<classSession>>& classSessions, vector<booking>& bookings);
};

