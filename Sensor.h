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
    
    std::pair<float, float> readFile();
	std::pair<float, float> readFile(int linenumber);

	void openFile(std::string filepath);
    
private:
	std::vector<std::pair<double, double>> track;
	std::ifstream datafile;


};

#endif