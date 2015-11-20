#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>

#include "Common.h"
#include "eigen/Eigen/Dense"

using namespace Eigen;

/* class Vehicle */
class Vehicle {
private:
    Vector2f pos;
    Vector2f vel;
    Vector2f acc;
    
    VectorXf state;
    
    MatrixXf mat;

public:
    void initMat (void) {
        mat.resize (matSize, matSize);
        
        if (constVel) {
        mat << 1, 0, timestep, 0, 0, 0,
               0, 1, 0, timestep, 0, 0,
               0, 0, 1,        0, 0, 0,
               0, 0, 0,        1, 0, 0,
               0, 0, 0,        0, 0, 0,
               0, 0, 0,        0, 0, 0; }
        else {
        mat << 1, 0, timestep, 0, 0, 0,
               0, 1, 0, timestep, 0, 0,
               0, 0, 1, 0, timestep, 0,
               0, 0, 0, 1, 0, timestep,
               0, 0, 0,        0, 1, 0,
               0, 0, 0,        0, 0, 1; }

        
        std::cout << "the matrix model " << matSize << "x" << matSize << ": \n" << mat << std::endl << std::endl;;
        
    }
    
    void computePos (int duration) {
        float temp = 0;
        
        std::cout << "the state before computePos is:\n" << state << std::endl << std::endl;;

        while (temp < (float) duration)
        {
            /* update the state */
            state = mat*state;
            
            temp += timestep;
        }
    
        std::cout << "state after "<< duration <<" second:\n" << state << std::endl << std::endl;;
    }
    
    // constructor
    Vehicle (Vector2f A, Vector2f B, Vector2f C) {
        pos = A;
        vel = B;
        acc = C;
        
        VectorXf temp(matSize);
        temp << pos, vel, acc;
        
        state = temp;
        
        std::cout << "the state after initialisation is:\n" << state << std::endl << std::endl;
    }
};

#endif