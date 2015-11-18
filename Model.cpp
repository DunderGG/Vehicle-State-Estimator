#include <iostream>
#include "Model.h"
#include "eigen/Eigen/Dense"

using namespace Eigen;
using namespace std;

void Model::setVel(float v)
{
	velocity = v;
}

float Model::getVel()
{
	return velocity;
}

void Model::setAcc(float a)
{
	acceleration = a;
}

float Model::getAcc()
{
	return acceleration;
}

Model::Model()
{

}
Model::Model(float v, float a)
{
	velocity = v;
	acceleration = a;

	cout << "Created a Model (V = " << velocity << " , A = " << acceleration << ")" << endl;
}

Matrix4f Model::constVeloModel(float T)
{
	Matrix4f m;
  	m << 1.0,   0,   T,     0,
  	     0,     1.0, 0,     0,
  	     0,     0,   1.0,   0,
  	     0,     0,   0,     1.0;


  	Matrix2f A;
  	A << 0, 1.0,
  		 0, 0;

  	RowVector2f H;
  	A << 1.0, 0;


  	return m;
}



std::ostream& operator<<(std::ostream &strm, const Model &model) 
{
	return strm << "Model(V = " << model.velocity << " , A = " << model.acceleration << ")";
}