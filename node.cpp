#include "node.h"

Node::Node(vector<string> initializationVector)
{
}

float Node::calculateSeverity()
{
    //find maxtimedifference
    float weightedCasualty = (casualties / 16.0f) * 0.2f;
    float weightedVehicles = (vehiclesInvolved / 43.0f) * 0.2f;
    float weightedDistance = (distance / 106.4485f) * 0.2f;
    float weightedTime = (timeDifference / 123.0f) * 0.2f;
    float maxSeverity = (severityIndex / 10.0f) * 0.2f;

    return weightedCasualty + weightedVehicles + weightedDistance + weightedTime + maxSeverity;
}
