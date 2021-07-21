#include <vector>
#include <string>
using namespace std;
struct Node
{
    /*******************************ACCIDENT DATA**********************************/
    //All the data in an accident
    float severityIndex = 0.0f;
    int startTime = 0;
    int endTime = 0;
    int timeDifference = 0;
    float startLat = 0.0f;
    float startLong = 0.0f;
    float endLat = 0.0f;
    float endLong = 0.0f;
    int casualties = 0;
    int vehiclesInvolved = 0;
    float distance = 0.0f;
    string city = "";
    string state = "";
    float temperature = 0.0f;
    float windChill = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;
    int visibility = 0;
    string windDirection = "";
    //more data

    /*****************************TREE STRUCTURES**********************************/
    enum Color : bool
    {
        black = false,
        red = true,
    };
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
    Node(vector<string> InitialzationVector);
    float calculateSeverity();
};