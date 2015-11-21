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

#include "Common.h"				// system configuration
//#include "Vehicle.h" 			// vehicle class (the model)
#include "Model.h" 				// model
#include "Sensor.h" 			// sensor
#include "Gaussian.h"

// TO COMPILE WITH EIGEN
//g++ -I ~/Dropbox/Projects/C++/Vehicle-State-Estimator/eigen App.cpp Model.cpp Sensor.cpp Gaussian.cpp -o app -std=gnu++11
//#include "eigen/Eigen/Dense"

/*
	The base case is as follows:
	(1)	App creates a Sensor object. The Sensor object creates the track.
	(2)	App creates a Gaussian object. For each point (x,y) on the track,
			App calls getNoise(point, nrOfPoints) and expects back the generated noise.
	(3)	???

*/

using namespace std;
using namespace Eigen;

int main()
{
	Sensor sensor;
	Gaussian gaussian;

	//The time between each sampling
	float samplingRate = 0.5;

	//Create a model, starting with:
	//               x,y                x,y                      x,y 
	//   Position = (0,0), Velocity = (10,5) and Acceleration = (0,0)
  	Model model(0,0, 10,5, 0,0);
	
	//Create the constant velocity model, with a given sampling rate
	MatrixXf m = model.constVeloModel(samplingRate);
	//cout << m << endl;

	vector<pair<double, double> > track = sensor.getTrack();
	//cout << "Track: " << endl;

	for (pair<double,double> point : track)
	{
		//cout << "X = " << point.first << " Y = " << point.second << endl;
		gaussian.getNoise(point, 100);
	}



  	/* construct the Vehicle */
    //Vehicle volvo (initVector(posX, posY), initVector(velX, velY), initVector(accelX, accelY));
    
    /* init the vehicle model */
    //volvo.initMat();
    
    /* update (10 second), we will have 10/timestep samples of position */
    //volvo.computePos(simDuration);
	
  	return 0;
}
