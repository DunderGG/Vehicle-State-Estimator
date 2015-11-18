#ifndef MODEL_H
#define MODEL_H
#include "eigen/Eigen/Dense"


class Model
{
public:
	float getVel();
	float getAcc();
	void setVel(float v);
	void setAcc(float a);

	Eigen::Matrix4f constVeloModel(float T);

	Model();
	Model(float v, float a);
	~Model();

private:
	float velocity;
	float acceleration;

	friend std::ostream& operator<<(std::ostream&, const Model&);
};


#endif