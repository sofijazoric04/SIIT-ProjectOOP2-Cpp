#include "WavGenerator.h"
#include <fstream>
#include <algorithm>

void WavGenerator::writeWav(const std::string& filename, const std::vector<double>& signal) {
    std::ofstream wav;
    wav.open(filename, std::ios::binary);
    if (wav.is_open()) {
        //header podaci
        wav << chunkId;
        wav << chunkSize;
        wav << format;
        wav << subchunk1Id;
        writeAsBytes(wav, subchunk1Size, 4);
        writeAsBytes(wav, audioFormat, 2);
        writeAsBytes(wav, numChannels, 2);
        writeAsBytes(wav, sampleRate, 4);
        writeAsBytes(wav, byteRate, 4);
        writeAsBytes(wav, blockAlign, 2);
        writeAsBytes(wav, bitsPerSample, 2);

        wav << subchunk2Id;
        wav << subchunk2Size;

        int startAudio = wav.tellp();
        //audio podaci 
        for (double s : signal) {
            writeDoubleAsBytes(wav, s, 2); //prepisujemo ga u 2 zato sto je to 16 bita(velicina naseg pcm-a)
        }
        int endAudio = wav.tellp();

        int subchunk2Size = endAudio - startAudio;
        wav.seekp(startAudio - 4);
        writeAsBytes(wav, subchunk2Size, 4); //upisujemo velicinu podataka
        wav.seekp(4, std::ios::beg);
        writeAsBytes(wav, endAudio - 8, 4);
        wav.close();
    }
}

void WavGenerator::writeAsBytes(std::ofstream& file, int value, int byteSize){
    file.write(reinterpret_cast<const char*>(&value), byteSize);
}

void WavGenerator::writeDoubleAsBytes(std::ofstream& file, double value, int byteSize) {
    file.write(reinterpret_cast<const char*>(&value), byteSize);
}


