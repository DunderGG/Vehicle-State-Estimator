#ifndef GAUSSIAN_H
#define GAUSSIAN_H
#include <vector>

class Gaussian
{
	
public:
	Gaussian();
	~Gaussian();

	std::vector<std::pair<int, int>> getNoise(std::pair<int,int>);

	double computeGaussian (double mu, double sigma);

private:


};


#endif