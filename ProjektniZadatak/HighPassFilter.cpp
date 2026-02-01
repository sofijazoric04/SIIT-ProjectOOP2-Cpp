#include "HighPassFilter.h"

std::vector<double> HighPassFilter::filterSignal(const std::map<int, double>& lookUpTable, const double& alpha, const int& mod_deg, const std::vector<double>& signal) {
	std::cout << "Koristimo high pass metodu\n\n";
	std::vector<double> alteredSignal;
	alteredSignal.push_back(0.0);
	for (int n = 1; n < signal.size(); ++n) {
		double m = getM(lookUpTable, mod_deg, n);
		double val = alpha * (alteredSignal[n - 1] + m * signal[n] - m * signal[n-1]);
		alteredSignal.push_back(val);
	}

	return alteredSignal;

}
