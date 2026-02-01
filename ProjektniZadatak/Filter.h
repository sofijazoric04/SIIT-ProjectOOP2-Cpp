#pragma once
#include <iostream>
#include <vector>
#include <map>

class Filter
{
public:
	virtual std::vector<double> filterSignal(const std::map<int, double>& lookUpTable, const double& alpha, const int& mod_deg, const std::vector<double>& signal) = 0;
	double getM(const std::map<int, double>& lookUpTable, const int& mod_deg, const int& n);
	virtual ~Filter() = default;
};

