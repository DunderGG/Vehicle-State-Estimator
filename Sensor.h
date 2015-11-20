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

	std::vector<std::pair<int, int>> getTrack();

private:
	std::vector<std::pair<int, int>> track;

};

#endif