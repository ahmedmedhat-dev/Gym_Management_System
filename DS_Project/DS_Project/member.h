#pragma once
#include <iostream>
#include <vector>
#include "person.h"
#include "workout.h"
#include "padelCourt.h"
#include "classSession.h"
#include "subscription.h"
#include "Date.h"
#include <Windows.h>
#include "colors.h"
using namespace std;

class member : public person
{
	subscription sub;
	vector<workout> WorkoutHistory;
	int TrainingIndex = -1;
	bool addedToClass = 0;
public:
	// == Constructors and Destructor ===================
	member();
	member(int ID, string name, string DOB, string pass, string phone, subscription sub, int T, bool addedToClass);
	member(int Id, string name, string DOB, string pass, string phone);
	~member();
	// == Functions =====================================
	void printDetails(); //overriding the abstract method from the base class
	// == num1 manage subscription ======================
	void Subsribtion();
	void Renew_Sub();
	void Change_Sub();
	// == num2 workouts =================================
	void workouts(vector<workout>& workouts);
	// == num3 training program =========================
	void TrainingProgram(vector<string>& T);
	// == num4 padel court booking ======================
	void PadelCourt(map<int, padelCourt>& courts, vector<booking>& books);
	// == num5 class sessions ===========================
	void Class_Sessions(vector<vector<classSession>>& classSessions, map<int, member> members);
	// == num6 manage personal information ==============
	void managePersonalInfo();
	void EditPersonalInfo();
	// == num7 manage workout history ===================
	vector<workout> getWorkoutHistory();
	subscription getSub();
	int getTrainingIndex();
	bool getAddedToClass();
	void setWorkoutHistory(vector<workout> workoutHistory);
	void setSub(subscription subscriptionID);
	void setTrainingIndex(int t);
	void setAddedToClass(bool a);
};