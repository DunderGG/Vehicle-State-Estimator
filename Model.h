#ifndef MODEL_H
#define MODEL_H
#include <Vector>
#include "Common.h"
#include "eigen/Eigen/Dense"


class Model
{
public:

	void setPos(double x, double y);	
	
	//SETTERS
	void setSpeed(double s);
	void setTheta(double theta);
	void setOmega(double omega);
	
	//GETTERS
	double getTheta() const;
	double getOmega() const;
	double getPosX() const;
	double getPosY() const;
	double getSpeed() const;

	Eigen::Vector3d updateState();
    
	double updateX();
	void updateXdot(double);
	double updateY();
	void updateYdot(double);
	double updateTheta();

	Eigen::MatrixXd constVeloModel(double T);

	Model();
	~Model();

	double degrees_to_radian(double);
private:
	double x, y, speed, theta, omega;
    
    Eigen::VectorXd state;

	friend std::ostream& operator<<(std::ostream&, const Model&);
};


#endif