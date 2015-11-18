#include <iostream>

#include "Common.h"				// system configuration
#include "Vehicle.h" 			// vehicle class (the model)
#include "Model.h"
#include "Sensor.h"

// TO COMPILE WITH EIGEN
//g++ -I ~/Dropbox/Projects/C++/VSE/eigen App.cpp Model.cpp Sensor.cpp
#include "eigen/Eigen/Dense"

using namespace std;

int main()
{
 //  	Eigen::MatrixXd m(2,2);
 //  	m(0,0) = 3;
 //  	m(1,0) = 2.5;
 //  	m(0,1) = -1;
 //  	m(1,1) = m(1,0) + m(0,1);
 //  	cout << m << std::endl;

  	/* construct the Vehicle */
    Vehicle volvo (initVector(posX, posY), initVector(velX, velY), initVector(accelX, accelY));
    
    /* init the vehicle model */
    volvo.initMat();
    
    /* update (10 second)*/
    volvo.computePos(simDuration);

    return 0;
}