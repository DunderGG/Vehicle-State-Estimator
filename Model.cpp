#include <iostream>
#include "Model.h"
#include "eigen/Eigen/Dense"

using namespace Eigen;
using namespace std;


/*
	Lecture notes: https://pingpong.chalmers.se/courseId/4620/node.do?id=2646568&ts=1447065023559&u=33775507
	SPACE STATE REPRESENTATION: xdot = Ax + Bu
	                               y = Cx + Du


*/

void Model::setVel(float Vx, float Vy)
{
	this->Vx = Vx;
	this->Vy = Vy;
}

pair<float, float> Model::getVel()
{
	return make_pair(this->Vx, this->Vy);;
}

void Model::setAcc(float Ax, float Ay)
{
	this->Ax = Ax;
	this->Ay = Ay;
}

pair<float, float> Model::getAcc()
{
	return make_pair(this->Ax, this->Ay);
}

void Model::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

pair<float, float> Model::getPos()
{
	return make_pair(this->x, this->y);
}

Model::Model()
{
	this->x = 0;
	this->y = 0;
	this->Vx = 0;
	this->Vy = 0;
	this->Ax = 0;
	this->Ay = 0;

	cout << "Model(P = "  << x << " , "  << y
		 << " , V = "     << Vx << " , " << Vy
		 << " , A = "     << Ax << " , " << Ay
		 << ")"           << endl        << endl;
}
Model::Model(float x, float y, float Vx, float Vy, float Ax, float Ay)
{
	this->x = x;
	this->y = y;
	this->Vx = Vx;
	this->Vy = Vy;
	this->Ax = Ax;
	this->Ay = Ay;

	cout << "Model(P = " << x << " , " << y 
		 << " , V = "    << Vx << " , " << Vy
		 << " , A = "    << Ax << " , " << Ay
		 << ")"          << endl        << endl;
}
Model::Model(pair<float, float> pos, pair<float, float> vel, pair<float, float> acc)
{
	this->x = pos.first;
	this->y = pos.second;
	this->Vx = vel.first;
	this->Vy = vel.second;
	this->Ax = acc.first;
	this->Ay = acc.second;

	cout << "Model(P = " << pos.first << " , " << pos.second
		<< " , V = "     << vel.first << " , " << vel.second
		<< " , A = "     << acc.first << " , " << acc.second
		<< ")"           << endl      << endl;
}
Model::~Model(void)
{
	//cout << "Model is destroyed" << endl;
}

// T is the sampling rate we want to use.
MatrixXf Model::constVeloModel(float T)
{
	//Get the state vector containing position, velocity and acceleration
	VectorXf stateVector = getStateVector();
	
	// WHY DOES IT CRASH HERE?
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
	VectorXf v(this->getPosVector(this->getPos()).rows() +
			   this->getVelVector(this->getVel()).rows() +
			   this->getAccVector(this->getAcc()).rows());
	v << this->getPosVector(this->getPos()), this->getVelVector(this->getVel()), this->getAccVector(this->getAcc());
	return v;
}

Vector2f Model::getPosVector(pair<float, float> pos)
{
	Vector2f v;
	v << pos.first, pos.second;
	return v;
}
Vector2f Model::getVelVector(pair<float, float> vel)
{
	Vector2f v;
	v << vel.first, vel.second;
	return v;
}
Vector2f Model::getAccVector(pair<float, float> acc)
{
	Vector2f v;
	v << acc.first, acc.second;
	return v;
}




std::ostream& operator<<(std::ostream &strm, const Model &model) 
{
	return strm << "Model(P = " << model.x << " , " << model.y
		<< " , V = " << model.Vx << " , " << model.Vy
		<< " , A = " << model.Ax << " , " << model.Ay
		<< ")" << endl << endl;
}