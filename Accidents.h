#pragma once

#include <string>
#include <vector>
using namespace std;

class Accident {
public:
	Accident(vector<int> intVector, vector<string> stringVector, vector<double> doubleVector);
	void calculateSeverity(); 
private:
	int severity;
	int startYear;
	int startMonth;
	int startDay;
	int startHour;
	int endYear;
	int endMonth;
	int endDay;
	int endHour;
	int casualties; 
	int vehiclesInvolved; 
	string ID;
	string description;
	string city;
	string county;
	string state;
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