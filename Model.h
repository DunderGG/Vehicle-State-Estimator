#ifndef MODEL_H
#define MODEL_H
#include <Vector>
#include "Common.h"
#include "eigen/Eigen/Dense"


class Model
{
public:

	void setPos(float x, float y);	
	
	//SETTERS
	void setSpeed(float s);
	void setAcc(float Ax, float Ay);
	void setTheta(float theta);
	void setOmega(float omega);
	
	//GETTERS
	float getTheta() const;
	float getOmega() const;
	float getPosX() const;
	float getPosY() const;
	float getSpeed() const;
	float getAccX() const;
	float getAccY() const;

	Eigen::Vector3f updateState();
    
	void updateX();
	void updateXdot(float vLongi);
	void updateY();
	void updateYdot(float vLongi);
	void updateTheta();

	Eigen::MatrixXf constVeloModel(float T);

	Model();
	~Model();

private:
	float x, y, speed, theta, omega;
    
    Eigen::VectorXf state;

	friend std::ostream& operator<<(std::ostream&, const Model&);
};


#endif