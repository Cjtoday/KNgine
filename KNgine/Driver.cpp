

#include "K_ResourceManager.hpp"
#include "K_Resource.hpp"
#include "K_TextResource.hpp"
#include "K_EntityManager.hpp"
#include "K_Error.hpp"

#include <cstdio>
#include <ctime>
#include <Windows.h>
#include <GL/glew.h>
#define GLFW_DLL
#include <GLFW\glfw3.h>


K_ResourceManager _manager;


void handleInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_ESCAPE)
		{
			glfwSetWindowShouldClose(window, 1);
		}
		if (key == GLFW_KEY_F1)
		{
			_manager.dumpResourcesInfo();
		}
	}
	else if (action == GLFW_RELEASE) {
	}
}



GLFWwindow* setupTempWindow()
{

	GLFWwindow* window;

	K_Error glfwError("initilizing GLFW3", "init Failed");
	if (!glfwInit())
	{
		K_Error::dump();
	}

	window = glfwCreateWindow(600, 400, "openGL test window", NULL, NULL);

	K_Error windowError("creating GLFW Window", "creation failed");
	if (!window)
	{
		glfwTerminate();
		K_Error::dump();
	}

	glfwMakeContextCurrent(window);

	if (glewInit() == GLEW_OK)
	{
		printf("openGL version: %s\n", glGetString(GL_VERSION));
	}
	else
	{
		printf(" GLEW not initilized, openGL version: %s\n", glGetString(GL_VERSION));
	}


	glfwSetKeyCallback(window, handleInput);

	return window;
}



int main(char** args)
{
	K_EntityManager _entityManager(_manager);

	K_Text text_0 = _manager.getTextResource("Hello");
	K_Text text_1 = _manager.getTextResource("Hello");


	GLFWwindow* _window = setupTempWindow();


	double t = 0.0;
	double deltaT = .016;

	double currentTime = time(0);
	double accumulatedTime = 0.0;

	while (!glfwWindowShouldClose(_window))
	{

		double newTime = time(0);
		double frameTime = newTime - currentTime;

		//printf("Frame Time: %lf\n", frameTime);

		currentTime = newTime;

		accumulatedTime += frameTime;
		//printf("accumulatedTime %f\n", accumulatedTime);

		
		while (accumulatedTime >= deltaT)
		{
			accumulatedTime -= deltaT;
			//printf("accumulatedTime %f\n", accumulatedTime);

			t += deltaT;
		}

		//printf("rendering\n");
		//Sleep(16.6);
		K_Text text_2 = _manager.getTextResource("Hello");

		glfwPollEvents();
	}




	glfwDestroyWindow(_window);

	printf("Program executed sucessfully press enter to terminate...");
	getchar();
}


