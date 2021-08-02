#include "Node.h"

Node::Node(Accident value)
{
    key = value; 
}

Node::Node(vector<string> initializationVector)
{
}

double Node::calculateSeverity()
{
    return key.getWeightedSeverity(); 
}
