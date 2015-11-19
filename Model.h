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
	
	Eigen::VectorXf getStateVector();
	

	Model();
	Model(std::pair<float, float> pos, std::pair<float, float> vel, std::pair<float, float> acc);
	Model(float x, float y, float Vx, float Vy, float Ax, float Ay);
	~Model();

private:
	float x, y, Vx, Vy, Ax, Ay;
	Eigen::Vector2f getPosVector(std::pair<float, float>);
	Eigen::Vector2f getVelVector(std::pair<float, float>);
	Eigen::Vector2f getAccVector(std::pair<float, float>);
	friend std::ostream& operator<<(std::ostream&, const Model&);
};


#endif