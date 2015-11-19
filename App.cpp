#include <iostream>

#include "Common.h"				// system configuration
#include "Vehicle.h" 			// vehicle class (the model)
#include "Model.h" 				// model
#include "Sensor.h" 			// sensor

// TO COMPILE WITH EIGEN
//++ -I ~/Dropbox/Projects/C++/Vehicle-State-Estimator/eigen App.cpp Model.cpp Sensor.cpp Gaussian.cpp -o app
#include "eigen/Eigen/Dense"

using namespace std;
using namespace Eigen;

int main()
{

	float T = 2.0;
  	Model model(52.0, 0);
	Matrix4f m = model.constVeloModel(5.9);
  	cout << m << endl;
  	
//  Eigen::MatrixXd m(2,2);
//  m(0,0) = 3;
//  m(1,0) = 2.5;
//  m(0,1) = -1;
//  m(1,1) = m(1,0) + m(0,1);
//  cout << m << std::endl;

  	/* construct the Vehicle */
    Vehicle volvo (initVector(posX, posY), initVector(velX, velY), initVector(accelX, accelY));
    
    /* init the vehicle model */
    volvo.initMat();
    
    /* update (10 second), we will have 10/timestep samples of position */
    volvo.computePos(simDuration);

  	return 0;
}
