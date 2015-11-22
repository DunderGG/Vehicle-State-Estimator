#ifndef MODEL_H
#define MODEL_H
#include <Vector>
#include "Common.h"
#include "eigen/Eigen/Dense"


class Model
{
public:
	std::pair<float, float> getPos();

	void setPos(float x, float y);	
	std::pair<float, float> getVel();
	std::pair<float, float> getAcc();
	void setVel(float Vx, float Vy);
	void setAcc(float Ax, float Ay);
    void computeState(float duration, float dt);
    Eigen::VectorXf returnState();
    
	Eigen::MatrixXf constVeloModel(float T);
	Eigen::VectorXf getStateVector();

	Model();
	Model(std::pair<float, float> pos, std::pair<float, float> vel, std::pair<float, float> acc);
	Model(float x, float y, float Vx, float Vy, float Ax, float Ay);
	~Model();

private:
	float x, y, Vx, Vy, Ax, Ay;
    
    Eigen::VectorXf state;
	Eigen::Vector2f getPosVector(std::pair<float, float>);
	Eigen::Vector2f getVelVector(std::pair<float, float>);
	Eigen::Vector2f getAccVector(std::pair<float, float>);

	friend std::ostream& operator<<(std::ostream&, const Model&);
};


#endif