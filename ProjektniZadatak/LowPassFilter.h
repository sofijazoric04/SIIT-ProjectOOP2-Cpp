#pragma once
#include "Filter.h"
class LowPassFilter :
    public virtual Filter //moramo staviti virtual da nam kasnije u bandu ne bi bila dvoznacna
{
public:
    std::vector<double> filterSignal(const std::map<int, double>& lookUpTable, const double& alpha, const int& mod_deg, const std::vector<double>& signal) override;
};

