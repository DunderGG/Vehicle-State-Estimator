#include <iostream>
#include "Model.h"
#include "eigen/Eigen/Dense"

using namespace Eigen;
using namespace std;

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

	cout << "Model(P = " << x << " , " << y
		<< " , V = " << Vx << " , " << Vy
		<< " , A = " << Ax << " , " << Ay
		<< ")" << endl << endl;
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
		 << " , V = " << Vx << " , " << Vy
		 << " , A = " << Ax << " , " << Ay
		 << ")" << endl << endl;
}
Model::~Model(void)
{
	cout << "Model is destroyed" << endl;
}

Matrix4f Model::constVeloModel(float T)
{
	Matrix4f m;
  	m << 1.0,   0,   T,     0,
  	     0,     1.0, 0,     0,
  	     0,     0,   1.0,   0,
  	     0,     0,   0,     1.0;
	cout << m << endl;

  	Matrix2f A;
  	A << 0, 1.0,
  		 0, 0;
	cout << A << endl;

  	RowVector2f H;
  	H << 1.0, 0;
	cout << H << endl;

  	return m;
}

VectorXf Model::getStateVector(Vector2f pos, Vector2f vel, Vector2f acc)
{
	VectorXf v(pos.rows() + vel.rows() + acc.rows());
	v << pos, vel, acc;
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