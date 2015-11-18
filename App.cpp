#include <iostream>
#include "Model.h"
#include "Sensor.h"

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
  	


  	return 0;
}
