#ifndef MODEL_H
#define MODEL_H

class Gaussian
{
	
public:
	Gaussian();
	~Gaussian();

	std::vector<std::pair<int, int>> getNoise(int x);

	double computeGaussian (double mu, double sigma);
private:


};


#endif