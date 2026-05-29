#include "reportGenerator.h"

reportGenerator::reportGenerator() {}
reportGenerator::~reportGenerator() {}

string reportGenerator::Counts(map<int, coach>& coaches, map<int, receptionist>& receptionists, map<int, member>& members) {

	int coachCount = coaches.size();
	int receptionistCount = receptionists.size();
	int memberCount = members.size();

	return "The count of the members is " + to_string(memberCount) + "\n" +
		"The count of the coach is " + to_string(coachCount) + "\n" +
		"The count of the receptionist is " + to_string(receptionistCount) + "\n";
}
string reportGenerator::classReport(vector<vector<classSession>>& classSessions) {
	int maxDemand = 0;
	classSession mostDemandedSession;
	for (auto& sessionRow : classSessions) {
		for (auto& session : sessionRow) {
			int registeredCount = session.getRegisteredMembers().size();
			int waitingListCount = session.getWaitingList().size();
			int vipWaitingListCount = session.getVIPWaitingList().size();

			int totalDemand = registeredCount + waitingListCount + vipWaitingListCount;

			if (totalDemand > maxDemand) {
				maxDemand = totalDemand;
				mostDemandedSession = session;
			}
		}
	}
	return "The most demanded classSession is with ID: " + to_string(mostDemandedSession.getID()) +
		" having total demand of: " + to_string(maxDemand) + " (Registered + Waiting List).\n";
}
string reportGenerator::getTopPadelCourtBooker(vector<booking>& bookings) {
	unordered_map<int, int> bookingCount;
	for (auto& b : bookings) {
		bookingCount[b.getMemberID()]++;
	}
	int maxBookings = 0;
	int topMemberID = -1;
	for (auto& entry : bookingCount) {
		if (entry.second > maxBookings) {
			maxBookings = entry.second;
			topMemberID = entry.first;
		}
	}
	if (topMemberID != -1) {
		return "The top padel booker member: " + to_string(topMemberID) + "\n"; // Assuming this function exists
	}
	return "N";
}


























