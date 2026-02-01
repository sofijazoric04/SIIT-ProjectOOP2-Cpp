#include "Filter.h"
#include "ProjektniZadatak.h"

double Filter::getM(const std::map<int, double>& lookUpTable, const int& mod_deg, const int& n) {
	int deg = (n * mod_deg) % 360;
	double m = 1.0 + 0.1 * getSine(deg, lookUpTable);
	return m;
}
