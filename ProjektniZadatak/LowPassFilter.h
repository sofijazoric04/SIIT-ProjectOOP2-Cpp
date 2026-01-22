#pragma once
#include "Filter.h"
class LowPassFilter :
    public Filter
{
public:
    void filterSignal(const std::map<int, double>& lookUpTable, const double& alpha, const int& mod_deg, const std::vector<double>& signal);
};

