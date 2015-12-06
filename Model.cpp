#include <iostream>
#include "Model.h"
#include "eigen/Eigen/Dense"
#include <cmath>

using namespace Eigen;
using namespace std;

#define wheelBase 2.744
#define deltaT 0.05

/*
	Lecture notes: https://pingpong.chalmers.se/courseId/4620/node.do?id=2646568&ts=1447065023559&u=33775507
	SPACE STATE REPRESENTATION: xdot = Ax + Bu
	                               y = Cx + Du


*/

void Model::setTheta(double t)
{
	this->theta = t;
	cout << "Theta set to " << this->theta << endl;
}
double Model::getTheta() const
{
	return this->theta;
}

void Model::setOmega(double o)
{
	this->omega = o;
	cout << "Omega set to " << this->omega << endl;
}
double Model::getOmega() const
{
	return this->omega;
}

void Model::setSpeed(double s)
{
	this->speed = s;
	cout << "Speed set to " << this->speed << endl;
}

double Model::getSpeed() const
{
	return this->speed;
}


void Model::setPos(double posx, double posy)
{
	this->x = posx;
	cout << "X set to " << this->x << endl;
	this->y = posy;
	cout << "Y set to " << this->y << endl;
}

double Model::getPosX() const
{
	return this->x;
}
double Model::getPosY() const
{
	return this->y;
}

Model::Model()
{
	this->x = 0;
	this->y = 0;
	this->speed = 0;
	this->theta = 0;
	this->omega = 0;

    VectorXd temp(5);
	//Dont consider acceleration yet
	//temp << this->x, this->y, this->Vx, this->Vy, this->Ax, this->Ay;
	temp << this->x, this->y, this->speed, this->theta, this->omega;
    
    /* update the initial state */
    this->state = temp;

	double Q1 = 1;
	double Q2 = 1;
	Matrix4d noiseMatrix;
	noiseMatrix << (Q1*(pow(deltaT, 3)) / 3),  0,						  (Q1*(pow(deltaT, 2)) / 2), 0,
					0,						   (Q2*(pow(deltaT, 3)) / 3), 0,						 (Q2*(pow(deltaT, 2)) / 2),
					(Q1*(pow(deltaT, 2)) / 2), 0,					 	  Q1*deltaT,				 0,
											   0,						  (Q2*(pow(deltaT, 2)) / 2), 0,	Q2*deltaT;
    
}


Model::~Model(void)
{
	cout << "Destroying Model object" << endl;
}

// T is the sampling rate we want to use.
MatrixXd Model::constVeloModel(double T)
{
	
	MatrixXd motionMatrix(6,6);
	motionMatrix << 1, 0, T, 0, 0, 0,  // Position
  					0, 1, 0, T, 0, 0,
  					0, 0, 1, 0, 0, 0,  // Velocity
  					0, 0, 0, 1, 0, 0,
					0, 0, 0, 0, 0, 0,  // Acceleration
					0, 0, 0, 0, 0, 0;

	
/*
  	Matrix2f A;
  	A << 0, 1.0,
  		 0, 0;


  	RowVector2f H;
  	H << 1.0, 0;

*/

  	return motionMatrix;
}


std::ostream& operator<<(std::ostream &strm, const Model &model) 
{
	return strm << "Model(P = " << model.x << " , " << model.y
		<< " , Speed = " << model.speed << ")" << endl << endl;
}

Eigen::Vector3d Model::updateState()
{
	double T = updateTheta();
	double X = updateX();
	double Y = updateY();
	
	cout << endl;

	Vector3d ret(3);
	ret << X, Y, T;
	return ret;
}
double Model::updateX()
{
	cout << "Updating X" << endl;
	cout << this->x << " + " << deltaT << " * " << this->speed << " * cos(" << this->theta << ") = ";

	this->x += deltaT * this->speed * cos(this->theta);

	cout << this->x << endl;
	return this->x;
}
/*
void Model::updateXdot(double vLongi)
{
	double U = vLongi;
	this->Sx = U * cos(getTheta());
}*/
double Model::updateY()
{
	cout << "Updating Y" << endl;
	cout << this->y << " + " << deltaT << " * " << this->speed << " * sin(" << this->theta << ") = ";

	this->y += deltaT * this->speed * sin(this->theta);

	cout << this->y << endl;
	return this->y;
}
/*
void Model::updateYdot(double vLongi)
{
	double U = vLongi;
	this->Sy = U * sin(getTheta());
}*/

double Model::updateTheta()
{
	cout << "Updating theta" << endl;
	cout << this->theta << " + " << deltaT << " * (" << this->speed << " / " << wheelBase << ")" << " * tan(" << this->omega << ") = ";

	this->theta += deltaT * (this->speed / wheelBase) * tan(this->omega);

	cout << this->theta << endl;
	return this->theta;
}

double Model::degrees_to_radian(double deg)
{
	return deg * M_PI / 180.0;
}