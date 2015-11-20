#include "Gaussian.h"

using namespace std;

void Gaussian::getDistribution() {
    std::default_random_engine gen;
    std::normal_distribution<double> distrib(5.0, 1.0);
    
    int p[10] = {};
    
    for (int i=0; i<numOfExperiments; i++) {
        double num = distrib(gen);
        
        if ((num>=0.0)&&(num<10.0)) ++p[int(num)];
    }
    
    std::cout << "normal_distribution (5.0,2.0):" << std::endl;
    
    for (int i=0; i<10; ++i) {
        std::cout << i << "-" << (i+1) << ": ";
        std::cout << std::string(p[i]*estimatedPoints/numOfExperiments,'*') << std::endl;
    }
}

Gaussian::Gaussian() {
    
}

Gaussian::Gaussian(int points, int experiment) {
    estimatedPoints = points;
    numOfExperiments = experiment;
}

Gaussian::~Gaussian() {

}