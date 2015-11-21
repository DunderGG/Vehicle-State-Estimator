#define _USE_MATH_DEFINES
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

vector<pair<double, double> > Gaussian::getNoise(pair<double,double> point, int nrOfPoints)
{
	vector<pair<double, double> > v;
	pair<double, double> x = point;
	x.first = computeGaussian(10, 5);
	return v;
}

double Gaussian::computeGaussian(double mu, double sigma)
{
	/*
		TODO: Change so that it returns the vector "points", containing the noise.
	*/
	//A vector cointaining all the points representing the noise
	vector<pair<int, int> > points;

    const double epsilon = std::numeric_limits<double>::min();
	const double two_pi = 2.0*M_PI;
    
    static double z0, z1;
    static bool generate;
    generate = !generate;
    
    if (!generate)
        return z1 * sigma + mu;
    
	cout << endl << endl;
    double u1, u2;
    do
    {
        u1 = rand() * (1.0 / RAND_MAX);
        u2 = rand() * (1.0 / RAND_MAX);
		cout << "u1 = " << u1 << "   u2 = " << u2 << endl;
    }
    while ( u1 <= epsilon );
	cout << endl << endl;

    z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
    z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
	cout << "z0 = " << z0 << "   z1 = " << z1 << endl;

	

    return z0 * sigma + mu;
}

Gaussian::~Gaussian()
{
	cout << "Destroying Gaussian object" << endl;
}