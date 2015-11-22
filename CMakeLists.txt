cmake_minimum_required (VERSION 2.8.9)

# name the project
project (vehicle-state-estimator)

# add add_subdirectories
# add_subdirectory (eigen)

include_directories (eigen)

set (SOURCE_FILES
		Common.h
		Gaussian.h
		Model.h
		Sensor.h
		Test.h

		App.cpp
		Gaussian.cpp
		Model.cpp
		Sensor.cpp
		Test.cpp )

# add executable
add_executable (vehicle-state-estimator ${SOURCE_FILES})

# set flag
set( CMAKE_CXX_FLAGS "-Wall -m64 -O3 -std=gnu++11 " )

# link to libraries
#target_link_libraries(vse-kalman common)
