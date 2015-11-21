#ifndef GAUSSIAN_H
#define GAUSSIAN_H
#include <vector>

class Gaussian
{
	
public:
	Gaussian();
	~Gaussian();

	std::vector<std::pair<double, double> > getNoise(std::pair<double,double>, int nrOfPoints);

	double computeGaussian (double mu, double sigma);

private:


};


#endif