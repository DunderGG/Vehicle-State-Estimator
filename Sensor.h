#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "eigen/Eigen/Dense"

class Sensor
{
public:
	Sensor();
	~Sensor();

	int randomData();
	int realData();

	std::vector<std::pair<double, double>> getTrack();
    
    std::pair<float, float> readFile();
    
private:
	std::vector<std::pair<double, double>> track;

};

#endif