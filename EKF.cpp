#include "EKF.h"
#include <vector>
#include "eigen/Eigen/Dense"
#include <fstream>
#include <iostream>

using namespace std;

EKF::EKF()
{
	cout << "Creating Extended Kalman Filter" << endl;
	float dt = 0.5;

	// Assuming our state vector has 3 elements, A looks like this
	Eigen::Matrix3f A;
	A <<	1, dt, 0, 
			0, 1, dt,
			0, 0,  1;

	// Identity matrix
	Eigen::Matrix3f I;
	I <<	1, 0, 0,
			0, 1, 0,
			0, 0, 1;
}

EKF::~EKF()
{
	cout << "Destroying Extended Kalman Filter" << endl;
}

/*
	PREDICTION PHASE (' = estimation) 
	
	x'_k = A * x'_(k?1)
	P_k  = A * P_(k-1) * At    (At = A transposed)

*/
void EKF::predict()
{

}

/*
	UPDATE PHASE

	G_k = P_k*Ct * (C*p_k*Ct + R)^(-1)    (Ct = C transposed)
	x'_k = x'_k + g_k * ( z_k - C*x'_k)
	P_k  = (I - G_k*C) * P_k

*/
void EKF::update()
{

}

void EKF::updateJacobians()
{

}