#include "Sensor.h"

#include <vector>
#include <iostream>
#include <fstream>

#include <sstream>
#include <string>
#include <iomanip>
#include <utility>


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

	this->datafile.close();
	cout << "datafile closed" << endl;
}

void Sensor::openFile(string filepath)
{
	//We open the file (input mode) 
	// and close it when the Sensor object is destroyed.
	this->datafile.open(filepath, ios::in);
}

pair<float,float> Sensor::readFile ()
{
    string line;
    
    //ifstream inputFile ("../gps-2column.txt");
    
    if (this->datafile.is_open())
    {
		getline(this->datafile, line);
        
		std::stringstream   linestream(line);
		std::string         value;

		double xVal = 0;
		double yVal = 0;

		int column = 0;
		while (getline(linestream, value, ',') && (column < 2))
		{
			if (column == 0)
				xVal = strtod(value.c_str(), NULL);
			else 
			{
				yVal = strtod(value.c_str(), NULL);
			}

			column++;
		}

        cout << setiosflags (ios::fixed) << setprecision(10) << xVal << "," << yVal << std::endl;
        
    }
    
    //THIS SHOULD CONTAIN THE X AND Y VALUES WE READ
	return make_pair(0.0f, 0.0f);
}
pair<float, float> Sensor::readFile(int linenumber)
{
	string line;

	//ifstream inputFile ("../gps-2column.txt");

	if (this->datafile.is_open())
	{
		while (getline(this->datafile, line))
		{
			std::stringstream   linestream(line);
			std::string         value;

			double xVal = 0;
			double yVal = 0;

			int column = 0;
			while (getline(linestream, value, ',') && (column < 2))
			{
				if (column == 0)
					xVal = strtod(value.c_str(), NULL);
				else
				{
					yVal = strtod(value.c_str(), NULL);
				}

				column++;
			}

			cout << setiosflags(ios::fixed) << setprecision(10) << xVal << "," << yVal << std::endl;
		}
	}


	return make_pair(0.0f, 0.0f);
}