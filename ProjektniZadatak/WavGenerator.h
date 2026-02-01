#pragma once
#include <vector>
#include <string>

class WavGenerator {
public:
	//koristimo tabelu wav formata za kreiranje wav-a: http://soundfile.sapp.org/doc/WaveFormat/

	//riff chunk
	const std::string chunkId = "RIFF";
	const std::string chunkSize = "----";
	const std::string format = "WAVE";

	//fmt subchunk
	const std::string subchunk1Id = "fmt "; //razmak zbog 4 neophodna bajta
	const int subchunk1Size = 16; //bajtova za pcm
	const int audioFormat = 1; 
	const int numChannels = 1;
	const int sampleRate = 44100; //broj signala po sekundi
	const int byteRate = sampleRate * numChannels * (subchunk1Size / 8);
	const int blockAlign = numChannels * (subchunk1Size / 8);
	const int bitsPerSample = 16;

	//data subchunk
	const std::string subchunk2Id = "data";
	const std::string subchunk2Size = "----";

	void writeWav(const std::string& filename, const std::vector<double>& signal);
	void writeAsBytes(std::ofstream& file, int value, int byteSize);
	void writeDoubleAsBytes(std::ofstream& file, double value, int byteSize);


};

