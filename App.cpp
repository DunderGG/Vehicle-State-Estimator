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

#include "Model.h" 				// model
#include "Sensor.h" 			// sensor
#include "Gaussian.h"
#include "Test.h"

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
    Test Test1;
    Test Test2;
    
    Test1.simpleTestOne();
    Test2.simpleTestTwo();
    
  	return 0;
}
