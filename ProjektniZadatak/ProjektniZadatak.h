#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

void loadMap(std::map<int, double>& lookUpTable);
void loadVector(std::vector<double>& signal);
const double getSine(const int& key, const std::map<int, double>& lookUpTable);
