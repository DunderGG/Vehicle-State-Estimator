/*	**** IMPORTANT NOTICE ****
*
*	Copyright 2015,
*	David Bennehag and Yanuar Tri Aditya Nugraha
*		This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*	**************************
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include "Model.h" 				// model
#include "Sensor.h" 			// sensor
#include "Gaussian.h"

// TO COMPILE WITH EIGEN
//g++ -I ~/Dropbox/Projects/C++/Vehicle-State-Estimator/eigen App.cpp Model.cpp Sensor.cpp Gaussian.cpp -o app -std=gnu++11
//#include "eigen/Eigen/Dense"


using namespace std;
using namespace Eigen;

int main()
{
    int i;
	Model model;
	Vector3d state;

	ifstream headFile("headingShorter.txt");
	ifstream velFile("velocity.txt");
	ifstream omegaFile("omega.txt");
	ifstream xFile("x.txt");
	ifstream yFile("y.txt");

	ofstream resultFile("result.txt");

	string headLine, velLine, omLine, xLine, yLine;
	double heading, velocity, omega, x, y;
	
	if (headFile.is_open())
	{
		cout << "Reading a line..." << endl;
		
		while (getline(headFile, headLine))
		{
			getline(velFile, velLine);
			getline(omegaFile, omLine);
			getline(xFile, xLine);
			getline(yFile, yLine);
			
			velocity = strtod(velLine.c_str(), NULL);
			heading = strtod(headLine.c_str(), NULL);
			omega = strtod(omLine.c_str(), NULL);
			x = strtod(xLine.c_str(), NULL);
			y = strtod(yLine.c_str(), NULL);
			
			model.setTheta(heading);
			model.setSpeed(velocity);
			model.setOmega(omega);

			state = model.updateState();

			cout << endl << "Computed: X = " << state(0) << "\t, Y = " << state(1) << endl
						 << "Measured: X = " << x	     << "\t, Y = " << y		   << endl << endl;

			resultFile << state(0) << "\t" << state(1) << "\t" << x << "\t" << y << "\n";
		}

	}

	headFile.close();
	velFile.close();
	omegaFile.close();
	xFile.close();
	yFile.close();

	
	Sensor sensor;
	int lineNumber = 0;

	sensor.openFile("gps-2column.txt");
	//pair<float, float> position = sensor.readFile(lineNumber++);
	for (int i = 0; i < 100; i++)
	{
		//pair<float, float> position = sensor.readFile();

		//cout << "X = " << position.first << ",\t Y = " << position.second << endl;
	}

	

    return 0;
}
