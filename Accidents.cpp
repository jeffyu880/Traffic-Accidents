#include "Accidents.h"

Accident::Accident(vector<int> intVector, vector<string> stringVector, vector<double> doubleVector) {

	
	severity = intVector.at(0);
	casualties = intVector.at(1);
	vehiclesInvolved = intVector.at(2); 

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
	calculateSeverity(); 
}

void Accident::calculateSeverity()
{
	double weightedCasualty = ((double)casualties / 16.0f) * 0.2f;
	double weightedVehicles = ((double)vehiclesInvolved / 43.0f) * 0.2f;
	double weightedDistance = ((double)distance / 106.4485f) * 0.2f;
	double weightedTime = ((double)timeDifference / 123.0f) * 0.2f;
	double maxSeverity = ((double)severity/ 10.0f) * 0.2f;

	weightedSeverity = weightedCasualty + weightedVehicles + weightedDistance + weightedTime + maxSeverity;
	
}