#include "Sensor.h"

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

Sensor::Sensor()
{
	
	//                                                                                ________________________
	//         GROUND TRUTH / TEST TRACK                                     ________/                        \__________     
	//        Will be passed to Gaussian generator    ______________________/                                            \________
	//        to generate noise around it    ________/                                                                            \_______
	//        ______________________________/                                                                                             \_______
    track = { 	{ 0,0 }, { 1,0 }, { 2,0 }, { 3,0 }, 
    			{ 4,1 }, { 5,2 }, { 6,2 }, { 7,2 }, 
    			{ 8,3 }, { 9,4 }, { 10,4 },{ 11,4 },
    			{ 12,3 },{ 13,2 },{ 14,1 },{ 15,0 } };
}

int Sensor::randomData()
{	
	return 0;
}


vector<pair<double, double>> Sensor::getTrack()
{
	return track;
}

Sensor::~Sensor()
{
	cout << "Destroying Sensors object" << endl;
}

pair<float,float> Sensor::readFile ()
{
    string line;
    
    ifstream inputFile ("gps.txt");
    
    bool exp = inputFile.is_open();
    
    if (inputFile.is_open())
    {
        while (getline (inputFile, line))
        {
            cout << line << "\n";
        }
        inputFile.close();
    }
    
    cout << "Done" << endl;
}
