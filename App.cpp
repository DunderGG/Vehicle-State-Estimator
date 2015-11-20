#include <iostream>
#include <cstdio>

#include "Common.h"				// system configuration
#include "Vehicle.h" 			// vehicle class (the model)
#include "Model.h" 				// model
#include "Sensor.h" 			// sensor

// TO COMPILE WITH EIGEN
//++ -I ~/Dropbox/Projects/C++/Vehicle-State-Estimator/eigen App.cpp Model.cpp Sensor.cpp Gaussian.cpp -o app
//#include "eigen/Eigen/Dense"

using namespace std;
using namespace Eigen;

int main()
{
	//The time between each sampling
	float samplingRate = 0.5;

	//Create a model, starting with:
	//               x,y                x,y                      x,y 
	//   Position = (0,0), Velocity = (10,5) and Acceleration = (0,0)
  	Model model(0,0, 10,5, 0,0);
	
	MatrixXf m = model.constVeloModel(samplingRate);
	cout << m << endl;

	
	
  	return 0;
}
