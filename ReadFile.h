#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Accidents.h"
#include <ctype.h>
using namespace std; 

//Parses the time difference and stores it in units of hours
double ParseTimeDifference(string time) {
	int index = 0; 
	string days = "";
	double hours;
	string minutes = "";
	string temp = "";
	//Gets the number of days and converts it to hours
	while (isdigit(time.at(index))) {
		days += time.at(index); 
		index += 1; 
	}
	hours = stod(days) * 60; 
	//Gets any spaces and characters between day and hours
	while (!isdigit(time.at(index))) {
		index += 1; 
	}
	//Gets the number of hours
	while (isdigit(time.at(index))) {
		temp += time.at(index); 
		index += 1; 
	}
	hours += stod(temp); 

	//Gets any spaces and characters between hours and minutes
	while (!isdigit((time.at(index)))) {
		index += 1; 
	}

	//Gets the number of minutes and converts them to hours
	while (index < time.size() && isdigit(time.at(index))) {
		minutes += time.at(index);
		index += 1; 
	}
	hours += stod(minutes) / 60; 

	return hours;
}

//Parses the Time Strings and stores a year, month, day, and time in an integer vector
void ParseTime(string input, vector<int>& output) {
	string temp = "";
	string temp1 = "";
	string temp2 = "";
	string temp3 = "";
	int tempInt;
	//Parses the year
	for (int ii = 0; ii < 4; ii += 1) {
		temp += input.at(ii);
	}
	tempInt = stoi(temp);
	output.push_back(tempInt);

	//Parses the month
	for (int ii = 5; ii < 7; ii += 1) {
		temp1 += input.at(ii);
	}
	tempInt = stoi(temp1);
	output.push_back(tempInt);

	//Parses the day
	for (int ii = 8; ii < 10; ii += 1) {
		temp2 += input.at(ii);
	}
	tempInt = stoi(temp2);
	output.push_back(tempInt);

	//Parses the time
	for (int ii = 11; ii < 13; ii += 1) {
		if (isdigit(input.at(ii))) {
			temp3 += input.at(ii);
		}
	}
	tempInt = stoi(temp3);
	output.push_back(tempInt);
}

//Parses Zip-Code (We only need the first 5 values)
int ParseZip(string input) {
	string temp = "";
	int tempInt;
	for (int ii = 0; ii < 5; ii += 1) {
		temp += input.at(ii);
	}
	tempInt = stoi(temp);
	return tempInt;
}

//Function to read in data from CSV file
void ReadFile(string filename, vector<Accident>& accidentVector) {
	ifstream inFile(filename);

	if (inFile.is_open()) {
		string line;
		//Reading the top two lines which are header files
		getline(inFile, line);
		getline(inFile, line);
		int N = 1;

		//Reading in data and creating A LOT of variables to store it all (Created vectors to more easily pass in data into the accident object constructor)
		while (getline(inFile, line)) {
			istringstream stream(line);

			int severity;
			int casualties;
			int vehiclesInvolved; 
			string temp;
			string ID;
			string startTime;
			string endTime;
			string description;
			string city;
			string county;
			string state;
			string timeZone;
			string windDirection;
			string weatherCondition;
			string night_day;
			double timeDifference; 
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
			vector<int> intVector;
			vector<string> stringVector;
			vector<double> doubleVector;

			//Reading in all data in a line
			getline(stream, ID, ',');
			getline(stream, temp, ',');
			severity = stoi(temp);
			getline(stream, startTime, ',');
			ParseTime(startTime, intVector);
			getline(stream, endTime, ',');
			ParseTime(endTime, intVector);
			getline(stream, temp, ','); 
			timeDifference = ParseTimeDifference(temp); 
			getline(stream, temp, ',');
			start_lat = stod(temp);
			getline(stream, temp, ',');
			start_long = stod(temp);
			getline(stream, temp, ',');
			end_lat = stod(temp);
			getline(stream, temp, ',');
			end_long = stod(temp);
			getline(stream, temp, ',');
			casualties = stoi(temp); 
			getline(stream, temp, ','); 
			vehiclesInvolved = stoi(temp); 
			getline(stream, temp, ',');
			distance = stod(temp);
			getline(stream, description, ',');
			getline(stream, city, ',');
			getline(stream, county, ',');
			getline(stream, state, ',');
			getline(stream, timeZone, ',');
			getline(stream, temp, ',');
			temperature = stod(temp);
			getline(stream, temp, ',');
			windChill = stod(temp);
			getline(stream, temp, ',');
			humidity = stod(temp);
			getline(stream, temp, ',');
			pressure = stod(temp);
			getline(stream, temp, ',');
			visibility = stod(temp);
			getline(stream, windDirection, ',');
			getline(stream, temp, ',');
			windSpeed = stod(temp);
			getline(stream, temp, ',');
			precipitation = stod(temp);
			getline(stream, weatherCondition, ',');
			getline(stream, night_day, ',');

			//Pushing data into vectors to make it easier to pass into a constructor
			intVector.push_back(severity);
			intVector.push_back(casualties);
			intVector.push_back(vehiclesInvolved); 

			stringVector.push_back(ID);
			stringVector.push_back(description);
			stringVector.push_back(city);
			stringVector.push_back(county);
			stringVector.push_back(state);
			stringVector.push_back(timeZone);
			stringVector.push_back(windDirection);
			stringVector.push_back(weatherCondition);
			stringVector.push_back(night_day);

			doubleVector.push_back(start_lat);
			doubleVector.push_back(start_long);
			doubleVector.push_back(end_lat);
			doubleVector.push_back(end_long);
			doubleVector.push_back(distance);
			doubleVector.push_back(temperature);
			doubleVector.push_back(windChill);
			doubleVector.push_back(humidity);
			doubleVector.push_back(pressure);
			doubleVector.push_back(visibility);
			doubleVector.push_back(windSpeed);
			doubleVector.push_back(precipitation);
			doubleVector.push_back(timeDifference); 


			//Storing data in an Accident class object and pushing it into an Accident vector
			Accident accidentObj(intVector, stringVector, doubleVector);
			accidentVector.push_back(accidentObj);
		}
		cout << "File Read" << endl;
	}
	else {
		cout << "ERROR!!! THE FILE IS NOT OPEN! I REPEAT THE FILE IS NOT OPEN!!!! FIX ISSUE IMMEDIATELY!!!" << endl;
	}
}

//Function to read in 1000 data points to decrease compile time for testing
void MinReadFile(string filename, vector<Accident>& accidentVector) {
	ifstream inFile(filename);
	int N = 1;

	if (inFile.is_open()) {
		string line;
		//Reading the top two lines which are header files
		getline(inFile, line);
		getline(inFile, line);

		//Reading in data and creating A LOT of variables to store it all (Created vectors to more easily pass in data into the accident object constructor)
		while (getline(inFile, line) && N > 0) {
			istringstream stream(line);

			int severity;
			int casualties;
			int vehiclesInvolved;
			string temp;
			string ID;
			string startTime;
			string endTime;
			string description;
			string city;
			string county;
			string state;
			string timeZone;
			string windDirection;
			string weatherCondition;
			string night_day;
			double timeDifference;
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
			vector<int> intVector;
			vector<string> stringVector;
			vector<double> doubleVector;

			//Reading in all data in a line
			getline(stream, ID, ',');
			getline(stream, temp, ',');
			severity = stoi(temp);
			getline(stream, startTime, ',');
			ParseTime(startTime, intVector);
			getline(stream, endTime, ',');
			ParseTime(endTime, intVector);
			getline(stream, temp, ',');
			timeDifference = ParseTimeDifference(temp);
			getline(stream, temp, ',');
			start_lat = stod(temp);
			getline(stream, temp, ',');
			start_long = stod(temp);
			getline(stream, temp, ',');
			end_lat = stod(temp);
			getline(stream, temp, ',');
			end_long = stod(temp);
			getline(stream, temp, ',');
			casualties = stoi(temp);
			getline(stream, temp, ',');
			vehiclesInvolved = stoi(temp);
			getline(stream, temp, ',');
			distance = stod(temp);
			getline(stream, description, ',');
			getline(stream, city, ',');
			getline(stream, county, ',');
			getline(stream, state, ',');
			getline(stream, timeZone, ',');
			getline(stream, temp, ',');
			temperature = stod(temp);
			getline(stream, temp, ',');
			windChill = stod(temp);
			getline(stream, temp, ',');
			humidity = stod(temp);
			getline(stream, temp, ',');
			pressure = stod(temp);
			getline(stream, temp, ',');
			visibility = stod(temp);
			getline(stream, windDirection, ',');
			getline(stream, temp, ',');
			windSpeed = stod(temp);
			getline(stream, temp, ',');
			precipitation = stod(temp);
			getline(stream, weatherCondition, ',');
			getline(stream, night_day, ',');

			//Pushing data into vectors to make it easier to pass into a constructor
			intVector.push_back(severity);
			intVector.push_back(casualties);
			intVector.push_back(vehiclesInvolved);

			stringVector.push_back(ID);
			stringVector.push_back(description); 
			stringVector.push_back(city);
			stringVector.push_back(county);
			stringVector.push_back(state);
			stringVector.push_back(timeZone);
			stringVector.push_back(windDirection);
			stringVector.push_back(weatherCondition);
			stringVector.push_back(night_day);

			doubleVector.push_back(start_lat);
			doubleVector.push_back(start_long);
			doubleVector.push_back(end_lat);
			doubleVector.push_back(end_long);
			doubleVector.push_back(distance);
			doubleVector.push_back(temperature);
			doubleVector.push_back(windChill);
			doubleVector.push_back(humidity);
			doubleVector.push_back(pressure);
			doubleVector.push_back(visibility);
			doubleVector.push_back(windSpeed);
			doubleVector.push_back(precipitation);
			doubleVector.push_back(timeDifference);


			//Storing data in an Accident class object and pushing it into an Accident vector
			Accident accidentObj(intVector, stringVector, doubleVector);
			accidentVector.push_back(accidentObj);
			N -= 1;
		}
		cout << "File Has Been Read! Please Give Your Computer Praise For Completing This Task!" << endl;
	}
	else {
		cout << "ERROR!!! THE FILE IS NOT OPEN! I REPEAT THE FILE IS NOT OPEN!!!! FIX ISSUE IMMEDIATELY!!!" << endl;
	}
}



