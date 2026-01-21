#include "ProjektniZadatak.h"
#include <iostream>
#include <fstream>

int main()
{
    std::map<int, double> lookUpTable;
    loadMap(lookUpTable);
    std::cout << "Vrednost sinusa za kljuc 90 je " << lookUpTable[90] << std::endl;
    std::cout << "Vrednost sinusa za kljuc 359 je " << lookUpTable[359] << std::endl;

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


