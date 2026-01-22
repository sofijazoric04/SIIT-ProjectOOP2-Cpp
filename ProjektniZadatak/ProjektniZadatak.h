#pragma once
#include <string>
#include <sstream>
#include <map>

void loadMap(std::map<int, double>& lookUpTable);
const double& getSine(const int& key, const std::map<int, double>& lookUpTable);
