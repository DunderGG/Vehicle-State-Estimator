#ifndef GAUSSIAN_H
#define GAUSSIAN_H

#include <iostream>
#include <random>

class Gaussian {
private:
    int estimatedPoints;
    int numOfExperiments;
    
public:
    Gaussian();
    Gaussian(int points, int experiment);
    ~Gaussian();
    
    void getDistribution ();
};

#endif