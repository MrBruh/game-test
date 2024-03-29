#include "../include/window.h"

using namespace glm;

int window::init()
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	main_window = glfwCreateWindow( 1024, 768, "Playground", NULL, NULL);
	if( main_window == NULL )
	{
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(main_window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(main_window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
}

void window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void window::swap()
{
	glfwSwapBuffers(main_window);
	glfwPollEvents();
}

bool window::esc()
{
	if (glfwGetKey(main_window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(main_window) == 0)
	{
		return true;
	} else {
		return false;
	}

}

void window::terminate()
{
	glfwTerminate();
}