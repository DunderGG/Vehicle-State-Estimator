#ifndef MODEL_H
#define MODEL_H
#include "eigen/Eigen/Dense"


class Model
{
public:
	std::pair<float, float> Model::getPos();
	void Model::setPos(float x, float y);
	std::pair<float, float> getVel();
	std::pair<float, float> getAcc();
	void setVel(float Vx, float Vy);
	void setAcc(float Ax, float Ay);

	Eigen::Matrix4f constVeloModel(float T);
	
	Eigen::VectorXf getStateVector(Eigen::Vector2f pos, Eigen::Vector2f vel, Eigen::Vector2f acc);
	Eigen::Vector2f getPosVector(std::pair<float, float>);
	Eigen::Vector2f getVelVector(std::pair<float, float>);
	Eigen::Vector2f getAccVector(std::pair<float, float>);

	Model();
	Model(float x, float y, float Vx, float Vy, float Ax, float Ay);
	~Model();

private:
	float x, y, Vx, Vy, Ax, Ay;

	friend std::ostream& operator<<(std::ostream&, const Model&);
};


#endif