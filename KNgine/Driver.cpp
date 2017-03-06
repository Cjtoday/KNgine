#pragma comment(lib,"user32.lib") 


#include "K_ResourceManager.hpp"
#include "K_Resource.hpp"
#include "K_TextResource.hpp"
#include "K_TextureResource.hpp"
#include "K_EntityManager.hpp"
#include "K_Error.hpp"
#include "K_WinApiWindow.hpp"
#include "K_ShaderResource.hpp"


#include <cstdio>
#include <ctime>
#include <Windows.h>
#include <GL/glew.h>


K_ResourceManager _manager;


void inputCallback(K_WinApiWindow* window, K_KeyCode keyCode, unsigned int state)
{
	if (keyCode == K_KEY_ESCAPE && state == K_KEY_STATE_DOWN)
	{
		window->close();
	}
	else if (keyCode == K_KEY_LCTRL && state == K_KEY_STATE_DOWN)
	{
		_manager.dumpResourcesInfo();
	}
}


void openGLSetup()
{
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		K_Error glewInitError("openGL Error", "failed to initilize glew");
		K_Error::dump();
	}
	
	GLuint vertexArrayID;
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	GLfloat vertexBufferData[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);
}

int main(char** args)
{	

	K_EntityManager _entityManager(_manager);

	K_Texture texture_0 = _manager.getTextureResource("test");

	K_Text text_0 = _manager.getTextResource("Hello");
	K_Text text_1 = text_0;

	K_Text& text_ref = text_0;

	K_Shader vertShader = _manager.getShaderResource("testVert");
	K_Shader fragShader = _manager.getShaderResource("testFrag");

	//K_EntityID mob_0 = _entityManager.createEntityHandle("mob_goblin_0");

	K_WindowConfig _windowConfig =
	{
		false,
		480,
		270,
		960,
		540,
		"K_Window",
		"K_Window"
	};

	K_WinApiWindow* _window = K_WinApiWindow::createWindow(_windowConfig);//new K_WinApiWindow();
	_window->setInputCallback(&inputCallback);
	_window->showDefaultWindow();



	/**********************************************
	OPENGL STUFF 
	************************************************/
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		K_Error glewInitError("openGL Error", "failed to initilize glew");
		K_Error::dump();
	}

	GLuint vertexArrayID;
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	const GLfloat vertexBufferData[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	printf("openGL version: %s\n", glGetString(GL_VERSION));
	printf("GLSL version %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	/**********************************************
	OPENGL STUFF END
	************************************************/

	double t = 0.0;
	double deltaT = .016;

	double currentTime = time(0);
	double accumulatedTime = 0.0;

	
	while(!_window->shouldClose())
	{
		double newTime = time(0);
		double frameTime = newTime - currentTime;

		printf("\rFrame Time: %Lf", frameTime);

		currentTime = newTime;

		accumulatedTime += frameTime;
		//printf("\raccumulatedTime %f", accumulatedTime);

		
		while (accumulatedTime >= deltaT)
		{
			accumulatedTime -= deltaT;
			//printf("accumulatedTime %f\n", accumulatedTime);

			t += deltaT;
		}

		//printf("rendering\n");
		//Sleep(30);//16.6
		K_Text text_2 = _manager.getTextResource("Hello");
		MSG msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{


			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glVertexAttribPointer(
				0,
				3,
				GL_FLOAT,
				GL_FALSE,
				0,
				(void*)0
			);

			glDrawArrays(GL_TRIANGLES, 0, 3);
			glDisableVertexAttribArray(0);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


			_window->swapBuffers();

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	printf("\nProgram executed sucessfully press enter to terminate...");
	getchar();
}


