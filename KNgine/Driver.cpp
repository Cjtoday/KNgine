#pragma comment(lib,"user32.lib") 


#include "K_ResourceManager.hpp"
#include "K_Resource.hpp"
#include "K_TextResource.hpp"
#include "K_TextureResource.hpp"
#include "K_EntityManager.hpp"
#include "K_Error.hpp"
#include "K_WinApiWindow.hpp"


#include <cstdio>
#include <ctime>
#include <Windows.h>
#include <GL/glew.h>
#define GLFW_DLL
#include <GLFW\glfw3.h>


K_ResourceManager _manager;


void handleInput(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	/*

	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_ESCAPE)
		{
			glfwSetWindowShouldClose(window, 1);
		}
		if (key == GLFW_KEY_F1)
		{
			_manager.dumpResourcesInfo();
		}
		if (key == GLFW_KEY_1)
		{
			
		}
	}
	else if (action == GLFW_RELEASE) {
	}
	*/
}



K_WinApiWindow* setupTempWindow()
{



	//K_WinApiWindow* window;

	/*
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
	glClearColor(1, 1, 0, 1);

	glfwSetKeyCallback(window, handleInput);

	*/
	return nullptr;
	
}



int main(char** args)
{	
	K_EntityManager _entityManager(_manager);

	K_Texture texture_0 = _manager.getTextureResource("test");

	K_Text text_0 = _manager.getTextResource("Hello");
	K_Text text_1 = _manager.getTextResource("Hello");

	K_EntityID mob_0 = _entityManager.createEntityHandle("mob_goblin_0");

	K_WindowConfig _windowConfig =
	{
		false,
		200,
		200,
		200,
		200,
		"K_Window",
		"K_Window"
	};

	K_WinApiWindow* _window = new K_WinApiWindow();
	_window->createWindow(_windowConfig);
	_window->showDefaultWindow();


	double t = 0.0;
	double deltaT = .016;

	double currentTime = time(0);
	double accumulatedTime = 0.0;

	
	//while (!glfwWindowShouldClose(_window))
	while(true)
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
		MSG msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//glfwPollEvents();
	}




	//glfwDestroyWindow(_window);

	printf("Program executed sucessfully press enter to terminate...");
	getchar();
}


