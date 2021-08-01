#pragma once

#include <string>
#include <vector>
using namespace std;

class Accident {
public:
	Accident(vector<int> intVector, vector<string> stringVector, vector<double> doubleVector);
	Accident(const Accident& rhs);
	Accident() {

	}
	bool operator<(const Accident& rhs);
	bool operator>(const Accident& rhs);
	Accident& operator=(const Accident& rhs);
	void calculateSeverity();
	double getWeightedSeverity();
	string state;
	string city;
private:
	int severity;
	int casualties;
	int vehiclesInvolved;
	string ID;
	string description;
	string county;
	string timeZone;
	string windDirection;
	string weatherCondition;
	string night_day;
	double start_lat;
	double start_long;
	double end_lat;
	double end_long;
	double distance;
	double temperature;
	double windChill;
	double humidity;
	double pressure;
	double visibility;
	double windSpeed;
	double precipitation;
	double weightedSeverity;
	double timeDifference;
};