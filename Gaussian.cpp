#define _USE_MATH_DEFINES
#include "Gaussian.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <random>
#include <chrono>
#include <functional>
#include <assert.h>

using namespace std;

#define NUMBER_OF_NOISEPOINTS 100

Gaussian::Gaussian()
{
	cout << "Starting Gaussian" << endl;
}

vector<pair<double, double>> Gaussian::getNoise(pair<double,double> point)
{
	vector<pair<double, double>> v;
	pair<double, double> x = point;
	//x.first = computeGaussian(10, 5);
	polarFormBoxMuller(NUMBER_OF_NOISEPOINTS);
	return v;
}

double Gaussian::computeGaussian(double mu, double sigma)
{
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


/*
	Taken from: http://www.design.caltech.edu/erik/Misc/Gaussian.html
	       and: http://stackoverflow.com/questions/10047215/uniform-random-number-generator-in-c
	Apparently both faster and more robust than the above.
*/
vector<double> Gaussian::polarFormBoxMuller(int nrOfNums)
{
	//float x1, x2, w, y1, y2;

	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_real_distribution<double> dist(0, 1);
	double rand;
	vector<double> randNums;
	for (int i = 0; i < nrOfNums; i++)
	{
		rand = dist(eng);
		randNums.push_back(rand);
		cout << "rand1: " << rand << endl;
	}

	assert(randNums.size() == nrOfNums && "Didn't generate correct number of numbers");
	
	return randNums;
}
double Gaussian::polarFormBoxMuller()
{
	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_real_distribution<double> dist(0, 1);
	
	return dist(eng);
}

double Gaussian::gaussianRandNum(int mean, int deviation)
{
	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
	std::normal_distribution<double> dist(mean, deviation);

	return dist(eng);
}
double Gaussian::gaussianRandNum()
{
	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
	std::normal_distribution<double> dist(0,1);

	return dist(eng);
}

Gaussian::~Gaussian()
{
	cout << "Destroying Gaussian object" << endl;
}