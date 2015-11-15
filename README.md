# Vehicle State Estimator (VSE) using Kalman Filtering [GCDC/MB]  

PROJECT DESCRIPTION  
The control of an autonomous vehicle may be far from trivial since a complete observation (i.e. direct measure) of all parameters involved in the system dynamic cannot be ensured, in particular in the case of non-linear systems. According to the VSE problem, this project aims at the estimation of the vehicle state (i.e., pose, velocity, etc.) starting from a dynamic model of a car-like vehicle. Ground truth positioning data can be automatically generated as a lane-change maneuver then Gaussian noise must be added to assess the filter performances in the noise reduction.   
The project should be done using C++ (external libraries can be used), and it will after this project be implemented into the GCDC challenge using real sensors (possibly on GPUs with OpenCL).

# Build using CMake

Navigate yourself to the root directory of the project. Then run:

`$ cmake .`

CMake will generate the makefile for the whole project. Then build using:

`$ make`

And you will see the executable file after that.

