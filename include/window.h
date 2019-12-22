#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class window
{
private:
	GLFWwindow* main_window;
public:
	window(GLFWwindow* Window):
		main_window(Window)
	{}
	int init();
	void clear();
	void swap();
	bool esc();
	void terminate();

};

#endif