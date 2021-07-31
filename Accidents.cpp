#include "Accidents.h"

Accident::Accident(vector<int> intVector, vector<string> stringVector, vector<double> doubleVector) {

	startYear = intVector.at(0);
	startMonth = intVector.at(1);
	startDay = intVector.at(2);
	startHour = intVector.at(3);
	endYear = intVector.at(4);
	endMonth = intVector.at(5);
	endDay = intVector.at(6);
	endHour = intVector.at(7);
	severity = intVector.at(8);
	casualties = intVector.at(9);
	vehiclesInvolved = intVector.at(10); 

	ID = stringVector.at(0);
	description = stringVector.at(1);
	city = stringVector.at(2);
	county = stringVector.at(3);
	state = stringVector.at(4);
	timeZone = stringVector.at(5);
	windDirection = stringVector.at(6);
	weatherCondition = stringVector.at(7);
	night_day = stringVector.at(8);

	start_lat = doubleVector.at(0);
	start_long = doubleVector.at(1);
	end_lat = doubleVector.at(2);
	end_long = doubleVector.at(3);
	distance = doubleVector.at(4);
	temperature = doubleVector.at(5);
	windChill = doubleVector.at(6);
	humidity = doubleVector.at(7);
	pressure = doubleVector.at(8);
	visibility = doubleVector.at(9);
	windSpeed = doubleVector.at(10);
	precipitation = doubleVector.at(11);
	timeDifference = doubleVector.at(12); 
}

void Accident::calculateSeverity()
{
	double weightedCasualty = (casualties / 16.0f) * 0.2f;
	double weightedVehicles = (vehiclesInvolved / 43.0f) * 0.2f;
	double weightedDistance = (distance / 106.4485f) * 0.2f;
	double weightedTime = (timeDifference / 123.0f) * 0.2f;
	double maxSeverity = (severity/ 10.0f) * 0.2f;

	weightedSeverity = weightedCasualty + weightedVehicles + weightedDistance + weightedTime + maxSeverity;
	
}