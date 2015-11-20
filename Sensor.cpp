#include "Sensor.h"
#include <vector>
#include "Gaussian.h"
using namespace std;

int Sensor::randomData()
{
	vector<pair<int, int>> track;
	//                                                                                ________________________
	//         GROUND TRUTH / TEST TRACK                                     ________/                        \__________     
	//        Will be passed to Gaussian generator    ______________________/                                            \________
	//        to generate noise around it    ________/                                                                            \_______
	//        ______________________________/                                                                                             \_______
	track = { {0,0},{ 1,0 },{ 2,0 },{ 3,0 },{ 4,1 },{ 5,2 },{ 6,2 },{ 7,2 },{ 8,3 },{ 9,4 },{ 10,4 },{ 11,4 },{ 12,3 },{ 13,2 },{ 14,1 },{ 15,0 } };

	Gaussian gaussian;

	return 0;
}