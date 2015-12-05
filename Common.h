//
//  common.h
//  _cpp
//
//  Created by Yanuar Aditya on 11/16/15.
//  Copyright © 2015 Chalmers. All rights reserved.
//

#ifndef common_h
#define common_h

#include "eigen/Eigen/Dense"

using namespace Eigen;

#define posX            0
#define posY            0
#define velX            20      // 72 kph
#define velY            0       // 0 m/s
#define accelX          5       // 5m/s
#define accelY          0
#define timestep        0.001f   // 0.001 s or 1000 fps
#define constVel        false   // true = constant velocity, false = constant accel
#define matSize         6     	// 2 blocks for each object, there are 3: pos, vel, acc
#define simDuration     10		// duration of simulation in second

//Eigen::Vector2f initVector (float a, float b) {
//    Eigen::Vector2f temp(a, b);
//    return temp;
//}

#endif /* common_h */
