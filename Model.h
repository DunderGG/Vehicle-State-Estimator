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
	void setSpeed(float Vx, float Vy);
	void setAcc(float Ax, float Ay);
	void setTheta(float theta);
	void setOmega(float omega);
	
	//GETTERS
	float getTheta() const;
	float getOmega() const;
	float getPosX() const;
	float getPosY() const;
	float getSpeedX() const;
	float getSpeedY() const;
	float getAccX() const;
	float getAccY() const;

    void computeState(float duration, float dt);
    
	void updateX();
	void updateXdot(float vLongi);
	void updateY();
	void updateYdot(float vLongi);
	void updateTheta();

	Eigen::VectorXf returnState();
	Eigen::MatrixXf constVeloModel(float T);
	Eigen::VectorXf getStateVector();

	Model();
	Model(float x, float Vx, float y, float Vy, float Ax, float Ay, float theta, float omega);
	~Model();

private:
	float x, y, Sx, Sy, Ax, Ay, theta, omega;
    
    Eigen::VectorXf state;
	Eigen::Vector2f getPosVector(float, float);
	Eigen::Vector2f getVelVector(float, float);
	Eigen::Vector2f getAccVector(float, float);

	friend std::ostream& operator<<(std::ostream&, const Model&);
};


#endif