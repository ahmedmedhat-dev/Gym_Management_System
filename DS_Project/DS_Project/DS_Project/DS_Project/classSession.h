#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "Date.h"
#include <map>
#include "colors.h"
using namespace std;
class member;
class classSession {
	int ID, capacity, coachID;
	string date, time, duration, type, Location;
	vector<int> registeredMembers;
	queue<int> waitingList;
	queue<int> VIPwaitingList;
public:
	// == Constructors and Destructor ===================
	classSession();
	classSession(int id, string d, string t, string dur, string ty, string loc, int cId, int cap);
	~classSession();
	// == Functions =====================================
	void printDetails();
	void printWaitingList();
	void printRegisteredMembers();
	static void printClassVector(vector<vector<classSession>>& classSessions);
	static void addMember(int memberID, vector<vector<classSession>>& classSessions, map<int, member>& members);
	static void removeMember(int memberID, vector<vector<classSession>>& classSessions, map<int, member>& members);
	void addToWaitingList(int memberID, map<int, member>& members);
	void removeFromWaitingList(int memberID);
	// == Getters and Setters ============================
	int getID();
	string getDate();
	string getTime();
	string getDuration();
	string getType();
	string getLocation();
	int getCoachID();
	int getCapacity();
	vector<int> getRegisteredMembers();
	queue<int> getWaitingList();
	queue<int> getVIPWaitingList();
	void setID(int id);
	void setDate(string& d);
	void setTime(string& t);
	void setDuration(string& dur);
	void setType(string& ty);
	void setLocation(string& loc);
	void setCoachID(int& cId);
	void setCapacity(int cap);
	void setRegisteredMembers(vector<int>& members);
	void setWaitingList(queue<int>& waiting);
	void setVIPWaitingList(queue<int>& waiting);
};

