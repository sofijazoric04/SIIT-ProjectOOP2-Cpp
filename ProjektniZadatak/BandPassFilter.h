#pragma once
#include "LowPassFilter.h"
#include "HighPassFilter.h"

class BandPassFilter : 
	public LowPassFilter, public HighPassFilter 
{
public:
    std::vector<double> filterSignal(const std::map<int, double>& lookUpTable, const double& alpha, const int& mod_deg, const std::vector<double>& signal) override;
};

