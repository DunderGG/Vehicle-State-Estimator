#include <iostream>
#include "Model.h"
#include "eigen/Eigen/Dense"
#include <cmath>

using namespace Eigen;
using namespace std;

#define deltaT 0.5f

/*
	Lecture notes: https://pingpong.chalmers.se/courseId/4620/node.do?id=2646568&ts=1447065023559&u=33775507
	SPACE STATE REPRESENTATION: xdot = Ax + Bu
	                               y = Cx + Du


*/

void Model::setTheta(float theta)
{
	this->theta = theta;
	cout << "Theta set to " << this->theta << endl;
}
float Model::getTheta() const
{
	return this->theta;
}

void Model::setOmega(float omega)
{
	this->omega = omega;
}
float Model::getOmega() const
{
	return this->omega;
}

void Model::setSpeed(float s)
{
	this->speed = s;
	cout << "Speed set to " << this->speed << endl;
}

float Model::getSpeed() const
{
	return this->speed;
}


void Model::setPos(float posx, float posy)
{
	this->x = posx;
	cout << "X set to " << this->x << endl;
	this->y = posy;
	cout << "Y set to " << this->y << endl;
}

float Model::getPosX() const
{
	return this->x;
}
float Model::getPosY() const
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

    VectorXf temp(5);
	//Dont consider acceleration yet
	//temp << this->x, this->y, this->Vx, this->Vy, this->Ax, this->Ay;
	temp << this->x, this->y, this->speed, this->theta, this->omega;
    
    /* update the initial state */
    this->state = temp;

	float Q1 = 1;
	float Q2 = 1;
	Matrix4f noiseMatrix;
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
MatrixXf Model::constVeloModel(float T)
{
	
	MatrixXf motionMatrix(6,6);
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

Eigen::Vector3f Model::updateState()
{
	updateX();
	updateY();
	updateTheta();
	cout << "T = " << this->theta << endl << endl;

	Vector3f ret(3);
	ret << this->x, this->y, this->theta;
	return ret;
}
void Model::updateX()
{
	cout << "Updating X" << endl;
	cout << this->x << " + " << deltaT << " * " << this->speed << " * cos(" << this->theta << ") = ";

	this->x += deltaT * this->speed * cos(this->theta);

	cout << this->x << endl;
}
/*
void Model::updateXdot(float vLongi)
{
	float U = vLongi;
	this->Sx = U * cos(getTheta());
}*/
void Model::updateY()
{
	cout << "Updating Y" << endl;
	cout << this->y << " + " << deltaT << " * " << this->speed << " * sin(" << this->theta << ") = ";

	this->y += deltaT * this->speed * sin(this->theta);

	cout << this->y << endl;
}
/*
void Model::updateYdot(float vLongi)
{
	float U = vLongi;
	this->Sy = U * sin(getTheta());
}*/

void Model::updateTheta()
{
	this->theta += (deltaT * getOmega());
}