#ifndef SENSOR_H
#define SENSOR_H

#include <vector>

class Sensor
{
public:
	Sensor();
	~Sensor();

	int randomData();
	int realData();

	std::vector<std::pair<double, double>> getTrack();

private:
	std::vector<std::pair<double, double>> track;

};

#endif