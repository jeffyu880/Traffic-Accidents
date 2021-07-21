float severityIndexCalculation()
{
    float weightedCasualty = (Accident.Casualty/16.0f) * 0.2f;
    float weightedVehicles = (Accident.Vehicle/43.0f) * 0.2f;
    float weightedDistance = (Accident.Distance/106.4485f) * 0.2f;
    float weightedTime = (Accident.Time/MaxTime) * 0.2f;
    float maxSeverity = (Accident.Severity/10.0f) * 0.2f;

    return weightedCasualty + weightedVehicles + weightedDistance + weightedTime + maxSeverity;
}