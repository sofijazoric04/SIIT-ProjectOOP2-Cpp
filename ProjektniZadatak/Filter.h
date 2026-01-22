#pragma once
#include <iostream>
#include <vector>
#include <map>

class Filter
{
public:
	static int treshold;
	void filterSignal();
	double getM(const std::map<int, double>& lookUpTable, const int& mod_deg, const int& n);
	//~Filter();
};

