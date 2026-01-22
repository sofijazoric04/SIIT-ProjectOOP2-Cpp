#include "ProjektniZadatak.h"
#include "LowPassFilter.h"
#include "HighPassFilter.h"
#include "BandPassFilter.h"


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

void loadVector(std::vector<double>& signal) {
    std::ifstream in("signal.txt");
    if (!in) {
        std::cout << "Greska prilikom otvaranja fajla!" << std::endl;
        return;
    }
    double x;
    while (in) {
        in >> x;
        signal.push_back(x);
    }
}

const double getSine(const int& key, const std::map<int, double>& lookUpTable) {
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

int main(int argc, char* argv[])
{
    std::map<int, double> lookUpTable;
    std::vector<double> signal;
    loadMap(lookUpTable);
    loadVector(signal);

    std::string method = argv[1];
    double alpha = std::stod(argv[2]);
    int mod_deg = std::stoi(argv[3]);
    if (method == "lowpass") {
        LowPassFilter lpf;
        lpf.filterSignal(lookUpTable, alpha, mod_deg, signal);
    }
    else if (method == "highpass") {
        HighPassFilter hpf;
        hpf.filterSignal();
    }
    else if (method == "bandpass") {
        BandPassFilter bpf;
        //bpf.filterSignal();
    }
    else {
        std::cout << "Pogresno uneti argumenti komandne linije!" << std::endl;
    }

}



