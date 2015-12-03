#include <iostream>
#include "Model.h"
#include "eigen/Eigen/Dense"
#include <cmath>

using namespace Eigen;
using namespace std;

#define deltaT 0.05

/*
	Lecture notes: https://pingpong.chalmers.se/courseId/4620/node.do?id=2646568&ts=1447065023559&u=33775507
	SPACE STATE REPRESENTATION: xdot = Ax + Bu
	                               y = Cx + Du


*/

void Model::setTheta(float theta)
{
	this->theta = theta;
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

void Model::setSpeed(float velx, float vely)
{
	this->Sx = velx;
	this->Sy = vely;
}

float Model::getSpeedX() const
{
	return this->Sx;
}
float Model::getSpeedY() const
{
	return this->Sy;
}

void Model::setAcc(float accx, float accy)
{
	this->Ax = accx;
	this->Ay = accy;
}

float Model::getAccX() const
{
	return this->Ax;
}
float Model::getAccY() const
{
	return this->Ay;
}

void Model::setPos(float posx, float posy)
{
	this->x = posx;
	this->y = posy;
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
	this->Sx = 0;
	this->Sy = 0;
	this->Ax = 0;
	this->Ay = 0;
	this->theta = 0;
	this->omega = 0;

    VectorXf temp(matSize);
	//Dont consider acceleration yet
	//temp << this->x, this->y, this->Vx, this->Vy, this->Ax, this->Ay;
	temp << this->x, this->y, this->Sx, this->Sy, this->theta, this->omega;
    
    /* update the initial state */
    this->state = temp;
    
//	cout << "Model(P = "  << x << " , "  << y
//		 << " , V = "     << Vx << " , " << Vy
//		 << " , A = "     << Ax << " , " << Ay
//		 << ")"           << endl        << endl;
}

Model::Model(float x, float Vx, float y, float Vy, float Ax, float Ay, float theta, float omega)
{
	this->x = x;
	this->y = y;
	this->Sx = Vx;
	this->Sy = Vy;
	this->Ax = Ax;
	this->Ay = Ay;
	this->theta = theta;
	this->omega = omega;

    VectorXf temp(matSize);
	//Dont consider acceleration yet
    //temp << this->x, this->y, this->Vx, this->Vy, this->Ax, this->Ay;
	temp << this->x, this->y, this->Sx, this->Sy, this->theta, this->omega;

    /* update the initial state */
    this->state = temp;
    
//	cout << "Model(P = " << x << " , " << y 
//		 << " , V = "    << Vx << " , " << Vy
//		 << " , A = "    << Ax << " , " << Ay
//		 << ")"          << endl        << endl;
}

Model::~Model(void)
{
	cout << "Destroying Model object" << endl;
}

// T is the sampling rate we want to use.
MatrixXf Model::constVeloModel(float T)
{
	//Get the state vector containing position, velocity and acceleration
	VectorXf stateVector = getStateVector();
	
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

VectorXf Model::getStateVector()
{
	VectorXf v(matSize);

	v << this->getPosVector(this->getPosX(), this->getPosY()), 
		 this->getVelVector(this->getSpeedX(), this->getSpeedY()), 
		 this->getAccVector(this->getAccX(), this->getAccY());
	return v;
}

Vector2f Model::getPosVector(float x, float y)
{
	Vector2f v;
	v << x,y;
	return v;
}

Vector2f Model::getVelVector(float Vx, float Vy)
{
	Vector2f v;
	v << Vx, Vy;
	return v;
}

Vector2f Model::getAccVector(float Ax, float Ay)
{
	Vector2f v;
	v << Ax, Ay;
	return v;
}

void Model::computeState(float duration, float dt) {
    float runningTime = 0;
    
    while (runningTime < duration) {
        this->state = this->constVeloModel(timestep) * this->state;
        runningTime+=dt;
        
        cout << this->state << std::endl;
    }
}

Eigen::VectorXf Model::returnState() {
    return this->state;
}

std::ostream& operator<<(std::ostream &strm, const Model &model) 
{
	return strm << "Model(P = " << model.x << " , " << model.y
		<< " , V = " << model.Sx << " , " << model.Sy
		<< " , A = " << model.Ax << " , " << model.Ay
		<< ")" << endl << endl;
}

void Model::updateX()
{
	this->x += deltaT * this->getSpeedX() * cos(getTheta());
}
void Model::updateXdot(float vLongi)
{
	float U = vLongi;
	this->Sx = U * cos(getTheta());
}
void Model::updateY()
{
	this->y += deltaT * this->getSpeedY() * sin(getTheta());
}
void Model::updateYdot(float vLongi)
{
	float U = vLongi;
	this->Sy = U * sin(getTheta());
}
void Model::updateTheta()
{
	setTheta(getTheta() + (deltaT * getOmega()));
}