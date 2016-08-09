cmake_minimum_required(VERSION 2.8.3)
project(filters)
add_definitions(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  cmake_modules
)

find_package(Eigen REQUIRED)

catkin_package(
INCLUDE_DIRS include
LIBRARIES kalman
DEPENDS Eigen roscpp
)

include_directories(include/filters ${roscpp_INCLUDE_DIRS} ${Eigen_INCLUDE_DIRS})

add_library(kalman src/kalman.cpp)
target_link_libraries(kalman ${roscpp_LIBRARIES} ${Eigen_LIBRARIES})

add_executable(kalman_test src/kalman-test.cpp)
target_link_libraries(kalman_test ${roscpp_LIBRARIES} kalman)