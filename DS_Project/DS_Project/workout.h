#pragma once
#include <iostream>
#include <vector>
#include "colors.h"
using namespace std;
class workout
{
	string workoutName;
	string workoutType;
	int duration;
	string date;
	string description;
public:
	// Constructors and Destructor
	workout();
	workout(string workoutName, string workoutType, int duration, string date, string description);
	workout(string workoutName, string workoutType, int duration, string description);
	~workout();
	// functions
	void printDetails();
	void pWorkoutWithoutDate();
	void pWorkoutVectorWithoutDate(vector<workout>& workouts);
	void pWorkoutVector(vector<workout>& workouts);
	void addWorkoutToMember(vector<workout>& workouts, vector<workout>& hestory);

	// Getters and Setters
	string getWorkoutName();
	string getWorkoutType();
	int getDuration();
	string getDate();
	string getDescription();
	void setWorkoutName(string workoutName);
	void setWorkoutType(string workoutType);
	void setDuration(int duration);
	void setDate(string date);
	void setDescription(string description);
};

