#include "ProjektniZadatak.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <cmath>

int main()
{
    std::map<int, double> lookUpTable;
    loadMap(lookUpTable);
    double sine = getSine(342, lookUpTable);
    std::cout << sine << std::endl;
}

void loadMap(std::map<int, double>& lookUpTable) {
    std::ifstream in("sine_table.txt");
    if (!in) {
        std::cout << "Greska prilikom otvaranja fajla!";
        return;
    }

    std::string key, value;

    while (in) {
        in >> key >> value;
        lookUpTable.insert({ std::stoi(key), std::stod(value) });
    }
}

const double& getSine(const int& key, const std::map<int, double>& lookUpTable) {
    //koristimo at da bismo znali pristupamo li postojecem ili novom elementu
    double sine = -2; //van opsega sinusa da bismo znali postoji li u nasoj lookuptabeli ili ne
    try {
        sine = lookUpTable.at(key % 360);
    }
    catch(std::out_of_range){
        std::cout << "Kljuc " << key%360 << " ne postoji!" << std::endl;
        std::map<int, double>::const_iterator it = lookUpTable.lower_bound(key % 360); //moramo koristitii const iterator jer prosledjujemo lookup tabelu po referenci
        double upper_sine = it->second;
        --it;
        double lower_sine = it->second;
        //std::cout << "Najblize vrednosti su mu: " << lower_sine << " i " << upper_sine << std::endl;
        double new_sine = std::lerp(lower_sine, upper_sine, 0.5); //morala sam prebaciti na c++20
        return new_sine;
    }
    return sine;

}



