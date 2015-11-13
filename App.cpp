#include <iostream>
#include "Model.h"
#include "Sensor.h"

// TO COMPILE WITH EIGEN
//g++ -I ~/Dropbox/Projects/C++/VSE/eigen App.cpp Model.cpp Sensor.cpp
#include <Eigen/Dense>

using namespace std;

int main()
{
	Eigen::MatrixXd m(2,2);
  	m(0,0) = 3;
  	m(1,0) = 2.5;
  	m(0,1) = -1;
  	m(1,1) = m(1,0) + m(0,1);
  	cout << m << std::endl;
}