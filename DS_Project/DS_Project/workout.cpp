#include "workout.h"
#include <Windows.h>
// Constructors & Destructor
workout::workout() {
	workoutName = "";
	workoutType = "";
	duration = 0;
	date = "";
	description = "";
}
workout::workout(string workoutName, string workoutType, int duration, string date, string description) {
	this->workoutName = workoutName;
	this->workoutType = workoutType;
	this->duration = duration;
	this->date = date;
	this->description = description;
}
workout::workout(string workoutName, string workoutType, int duration, string description) {
	this->workoutName = workoutName;
	this->workoutType = workoutType;
	this->duration = duration;
	this->description = description;
	this->date = ""; // Default date if not provided
}
workout::~workout() {
	// Destructor
}
// Functions
void workout::printDetails() {
	cout << "Workout Name: " << workoutName << endl;
	cout << "Workout Type: " << workoutType << endl;
	cout << "Duration:     " << duration << " minutes" << endl;
	cout << "Date:         " << date << endl;
	cout << "Description:  " << description << endl;
}
void workout::pWorkoutWithoutDate() {
	cout << "Workout Name: " << workoutName << endl;
	cout << "Workout Type: " << workoutType << endl;
	cout << "Duration:     " << duration << " minutes" << endl;
	cout << "Description:  " << description << endl;
}
void workout::pWorkoutVector(vector<workout>& workouts) {
	cout << "Workout History: " << endl;
	for (int i = 0; i < workouts.size(); i++) {
		cout << "=================  " << i << "  =================" << endl;
		workouts[i].printDetails();
	}
	cout << "==========================================" << endl;
}
void workout::pWorkoutVectorWithoutDate(vector<workout>& workouts) {
	cout << "Workout History: " << endl;
	for (int i = 0; i < workouts.size(); i++) {
		cout << "=================  " << i << "  =================" << endl;
		workouts[i].pWorkoutWithoutDate();
	}
	cout << "==========================================" << endl;
}
void workout::addWorkoutToMember(vector<workout>& workouts, vector<workout>& hestory) {
	pWorkoutVectorWithoutDate(workouts);
	cout << "Enter the number of the workout you want to add to your history: ";
	int index;
	cin >> index;
	if (index < 0 || index >= workouts.size()) {

		cout << FG_WHITE << BG_RED << u8"\t\t╔═════════════════════╗" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║   Invalid index!!   ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t║  Please try again   ║" << RESET << endl;
		cout << FG_WHITE << BG_RED << u8"\t\t╚═════════════════════╝" << RESET << endl << endl;
		Sleep(500);
		return;
	}
	hestory.push_back(workouts[index]);
	cout << FG_WHITE << BG_GREEN << u8"\t\t╔════════════════════════════════════╗" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t║  Workout added to member's history ║" << RESET << endl;
	cout << FG_WHITE << BG_GREEN << u8"\t\t╚════════════════════════════════════╝" << RESET << endl << endl;
	Sleep(500);
}
// Getters and Setters
string workout::getWorkoutName() { return workoutName; }
string workout::getWorkoutType() { return workoutType; }
int workout::getDuration() { return duration; }
string workout::getDate() { return date; }
string workout::getDescription() { return description; }
void workout::setWorkoutName(string workoutName) { this->workoutName = workoutName; }
void workout::setWorkoutType(string workoutType) { this->workoutType = workoutType; }
void workout::setDuration(int duration) { this->duration = duration; }
void workout::setDate(string date) { this->date = date; }
void workout::setDescription(string description) { this->description = description; }

