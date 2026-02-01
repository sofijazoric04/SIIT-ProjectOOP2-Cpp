#include "LowPassFilter.h"

std::vector<double> LowPassFilter::filterSignal(const std::map<int, double>& lookUpTable, const double& alpha, const int& mod_deg, const std::vector<double>& signal) {
	std::cout << "Koristimo low pass metodu\n\n";
	std::vector<double> alteredSignal;
	alteredSignal.push_back(signal[0]);
	for (int n = 1; n < signal.size(); ++n) {
		double m = getM(lookUpTable, mod_deg, n);
		double val = alteredSignal[n - 1] + alpha * (m * signal[n] - alteredSignal[n - 1]);
		alteredSignal.push_back(val);
	}
	
	return alteredSignal;

}
