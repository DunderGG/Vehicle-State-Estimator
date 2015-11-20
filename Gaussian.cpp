#include "Gaussian.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <limits>

using namespace std;

Gaussian::Gaussian()
{
	cout << "Starting Gaussian" << endl;
}

vector<pair<int, int>> Gaussian::getNoise(pair<int,int> point)
{
	vector<pair<int, int>> v;

	return v;
}

double Gaussian::computeGaussian(double mu, double sigma)
{
	/*
		TODO: Change so that it returns the vector "points", containing the noise.
	*/
	//A vector cointaining all the points representing the noise
	vector<pair<int, int>> points;

    const double epsilon = std::numeric_limits<double>::min();
    const double two_pi = 2.0*3.1415926536;
    
    static double z0, z1;
    static bool generate;
    generate = !generate;
    
    if (!generate)
        return z1 * sigma + mu;
    
    double u1, u2;
    do
    {
        u1 = rand() * (1.0 / RAND_MAX);
        u2 = rand() * (1.0 / RAND_MAX);
    }
    while ( u1 <= epsilon );
    
    z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
    z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
    
    return z0 * sigma + mu;
}

Gaussian::~Gaussian()
{
	cout << "Destroying Gaussian object" << endl;
}