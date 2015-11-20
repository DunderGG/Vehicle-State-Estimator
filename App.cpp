#include <iostream>
#include <cstdio>
#include <vector>

#include "Common.h"				// system configuration
#include "Vehicle.h" 			// vehicle class (the model)
#include "Model.h" 				// model
#include "Sensor.h" 			// sensor
#include "Gaussian.h"

// TO COMPILE WITH EIGEN
//++ -I ~/Dropbox/Projects/C++/Vehicle-State-Estimator/eigen App.cpp Model.cpp Sensor.cpp Gaussian.cpp -o app
//#include "eigen/Eigen/Dense"

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
	
	MatrixXf m = model.constVeloModel(samplingRate);
	cout << m << endl;

	vector<pair<int, int>> track = sensor.getTrack();
	for each (pair<int,int> point in track)
	{

	}



  	/* construct the Vehicle */
    //Vehicle volvo (initVector(posX, posY), initVector(velX, velY), initVector(accelX, accelY));
    
    /* init the vehicle model */
    //volvo.initMat();
    
    /* update (10 second), we will have 10/timestep samples of position */
    //volvo.computePos(simDuration);

	
  	return 0;
}
