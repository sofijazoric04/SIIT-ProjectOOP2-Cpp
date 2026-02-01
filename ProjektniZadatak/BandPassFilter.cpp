#include "BandPassFilter.h"

std::vector<double> BandPassFilter::filterSignal(const std::map<int, double>& lookUpTable, const double& alpha, const int& mod_deg, const std::vector<double>& signal) {
	std::vector<double> pass1 = LowPassFilter::filterSignal(lookUpTable, alpha, mod_deg, signal);
	std::vector<double> pass2 = HighPassFilter::filterSignal(lookUpTable, alpha, mod_deg, pass1);
	return pass2;
}