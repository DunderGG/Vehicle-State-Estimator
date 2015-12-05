#ifndef EKF_H
#define EKF_H

class EKF
{
public:
	EKF();
	~EKF();

	void predict();
	void update();

private:
	void updateJacobians();
};

#endif