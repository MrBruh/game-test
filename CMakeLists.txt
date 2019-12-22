cmake_minimum_required(VERSION 3.10.2)
project(game)
set(CMAKE_BUILD_TYPE Release)
 
#Bring the headers,
include_directories(include)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
add_executable(main ${SOURCES})