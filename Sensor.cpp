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

	//    NO LONGER USED, MAYBE IN FUTURE?                                            ________________________
	//         GROUND TRUTH / TEST TRACK                                     ________/                        \__________     
	//        Will be passed to Gaussian generator    ______________________/                                            \________
	//        to generate noise around it    ________/                                                                            \_______
	//        ______________________________/                                                                                             \_______
	track = { { 0,0 },{ 1,0 },{ 2,0 },{ 3,0 },
	{ 4,1 },{ 5,2 },{ 6,2 },{ 7,2 },
	{ 8,3 },{ 9,4 },{ 10,4 },{ 11,4 },
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

/*
The destructor
Close all files.
*/
Sensor::~Sensor()
{
	cout << "Destroying Sensor object" << endl;

	this->datafile.close();
	this->velFile.close();
	this->omegaFile.close();
}

/*
First file is velocity file, second is omega.
Maybe everything should be in one file?
*/
void Sensor::openFile(string filepath1, string filepath2)
{
	//We open the files (input mode) 
	// and close it when the Sensor object is destroyed.
	this->velFile.open(filepath1, ios::in);
	this->omegaFile.open(filepath2, ios::in);

}
void Sensor::closeFile()
{
	//We open the files (input mode) 
	// and close it when the Sensor object is destroyed.
	this->velFile.close();
	this->omegaFile.close();

}

int Sensor::readFile()
{
	//This is the input to our estimator (speed and steering)
	string velLine, omLine;
	double velocity, omega;

	//Make sure both files are open.
	if (this->velFile.is_open() && this->omegaFile.is_open())
	{
		if (!getline(velFile, velLine))
			return 0; //We ran out of lines
		if (!getline(omegaFile, omLine))
			return 0; //We ran out of lines

					  //Convert from the string we read to a double we can use.
		this->velocity = strtod(velLine.c_str(), NULL);
		this->omega = strtod(omLine.c_str(), NULL);

		//Everything went fine
		return 1;
	}
	else  //Something went horribly wrong
		return 0;
}
double Sensor::getVelocity()
{
	return this->velocity;
}
double Sensor::getOmega()
{
	return this->omega;
}
//Not currently used
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

	//THIS SHOULD CONTAIN THE X AND Y VALUES WE READ
	return make_pair(0.0f, 0.0f);
}