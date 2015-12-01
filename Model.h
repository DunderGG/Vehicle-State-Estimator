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
	void setVel(float Vx, float Vy);
	void setAcc(float Ax, float Ay);
	void setTheta(float theta);
	void setOmega(float omega);
	
	//GETTERS
	float getTheta() const;
	float getOmega() const;
	std::pair<float, float> getPos() const;
	std::pair<float, float> getVel() const;
	std::pair<float, float> getAcc() const;

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
	Model(std::pair<float, float> pos, std::pair<float, float> vel, std::pair<float, float> acc, std::pair<float, float> angles);
	Model(float x, float Vx, float y, float Vy, float Ax, float Ay, float theta, float omega);
	~Model();

private:
	float x, y, Vx, Vy, Ax, Ay, theta, omega;
    
    Eigen::VectorXf state;
	Eigen::Vector2f getPosVector(std::pair<float, float>);
	Eigen::Vector2f getVelVector(std::pair<float, float>);
	Eigen::Vector2f getAccVector(std::pair<float, float>);

	friend std::ostream& operator<<(std::ostream&, const Model&);
};


#endif