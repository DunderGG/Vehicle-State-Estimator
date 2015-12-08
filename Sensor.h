#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "eigen/Eigen/Dense"
#include <fstream>


class Sensor
{
public:
	Sensor();
	~Sensor();

	int randomData();
	int realData();

	std::vector<std::pair<double, double>> getTrack();

	int readFile();
	std::pair<float, float> readFile(int linenumber);

	void openFile(std::string, std::string);
	void closeFile();

	double getOmega();
	double getVelocity();

private:
	std::vector<std::pair<double, double>> track;
	std::ifstream datafile, velFile, omegaFile;

	double omega = 0, speed = 0;

};

#endif