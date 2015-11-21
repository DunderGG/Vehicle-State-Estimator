#ifndef GAUSSIAN_H
#define GAUSSIAN_H
#include <vector>
#include <utility>

class Gaussian
{
	
public:
	Gaussian();
	~Gaussian();

	std::vector<std::pair<double, double> > getNoise(std::pair<double,double>);

	double computeGaussian (double mu, double sigma);

	std::vector<std::pair<double,double> > polarFormBoxMuller(int nrOfNums);

private:


};


#endif