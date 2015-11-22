#include <iostream>
#include <vector>

#include "test.h"
#include "Common.h"
#include "Sensor.h"
#include "Gaussian.h"
#include "Model.h"

using namespace std;

void Test::simpleTestOne ( ) {
    Sensor sensor;
    Gaussian gaussian;
    
    //The time between each sampling
    float samplingRate = timestep;
    
    //Create a model, starting with:
    //               x,y                x,y                      x,y
    //   Position = (0,0), Velocity = (10,5) and Acceleration = (0,0)
    Model model(0,0, 10,5, 0,0);
    
    //Create the constant velocity model, with a given sampling rate
    MatrixXf m = model.constVeloModel(samplingRate);
    //cout << m << endl;
    
    vector<pair<double, double>> track = sensor.getTrack();
    //cout << "Track: " << endl;
    
    vector<pair<double, double>> noiseVector;
    for (pair<double,double> point : track)
    {
        cout << "X = " << point.first << " Y = " << point.second << endl;
        gaussian.getNoise(point);
    }
}

void Test::simpleTestTwo () {
    //The time between each sampling
    float samplingRate = timestep;
    
    //Create the model
    //               x,y                x,y                      x,y
    //   Position = (0,0), Velocity = (10,5) and Acceleration = (0,0)
    Model model(0,0, 10,5, 0,0);
    
    model.computeState(simDuration, samplingRate);
    
    cout << model.returnState();
}

