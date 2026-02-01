#pragma once
#include "Filter.h"
class HighPassFilter :
    public virtual Filter
{
public:
    std::vector<double> filterSignal(const std::map<int, double>& lookUpTable, const double& alpha, const int& mod_deg, const std::vector<double>& signal) override;
};

