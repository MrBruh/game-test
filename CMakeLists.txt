cmake_minimum_required(VERSION 3.10.2)
project(game)
set(CMAKE_BUILD_TYPE Release)
 
add_subdirectory (external)

#Bring the headers,
include_directories(include)

include_directories(
	external/AntTweakBar-1.16/include/
	external/glfw-3.1.2/include/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	external/assimp-3.0.1270/include/
	external/bullet-2.81-rev2613/src/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
add_executable(main ${SOURCES})

target_link_libraries(main
	${ALL_LIBS}
)