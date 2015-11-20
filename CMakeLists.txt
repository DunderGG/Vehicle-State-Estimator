cmake_minimum_required (VERSION 2.8.9)

#name the project
project (vehicle-state-estimator)

#add add_subdirectories
# add_subdirectory (eigen)

set (SOURCE_FILES
		App.cpp
		Gaussian.cpp
		Model.cpp
		Sensor.cpp
		Test.cpp )

#add executable
add_executable (vehicle-state-estimator ${SOURCE_FILES})

#link to libraries
#target_link_libraries(vse-kalman common)
