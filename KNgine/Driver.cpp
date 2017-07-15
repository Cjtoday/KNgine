#pragma comment(lib,"user32.lib") 

#include "K_ResourceManager.hpp"
#include "K_Resource.hpp"
#include "K_TextResource.hpp"
#include "K_TextureResource.hpp"
#include "K_EntityManager.hpp"
#include "K_Error.hpp"
#include "K_WinApiWindow.hpp"
#include "K_ShaderResource.hpp"

#include "K_RenderEngine.hpp"
#include "K_ImageDecoder.hpp"

#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <Windows.h>
#include <GL/glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "K_Logger.hpp"

K_ResourceManager _manager;

float camerax = 0.0f;
float cameray = 0.0f;
float cameraz = 4.0f;

void inputCallback(K_WinApiWindow* window, K_KeyCode keyCode, unsigned int state)
{
	if (keyCode == K_KEY_ESCAPE && state == K_KEY_STATE_DOWN)
	{
		window->close();
	}
	if (keyCode == K_KEY_LCTRL && state == K_KEY_STATE_DOWN)
	{
		_manager.dumpResourcesInfo();
	}
	if(keyCode == K_KEY_W && state == K_KEY_STATE_DOWN)
	{
		cameray += .1f;
	}
	if (keyCode == K_KEY_A && state == K_KEY_STATE_DOWN)
	{
		
		camerax -= .1f;
	}
	if (keyCode == K_KEY_S && state == K_KEY_STATE_DOWN)
	{
		cameray -= .1f;
	}
	if (keyCode == K_KEY_D && state == K_KEY_STATE_DOWN)
	{
		camerax += .1f;
	}
	if (keyCode == K_KEY_Q && state == K_KEY_STATE_DOWN)
	{
		cameraz -= .1f;
	}
	if (keyCode == K_KEY_E && state == K_KEY_STATE_DOWN)
	{
		cameraz += .1f;
	}

}


int main(int argc, char** args)
{	

	K_EntityManager _entityManager(_manager);

	K_Texture texture_0 = _manager.getTextureResource("remus");

	K_Text text_0 = _manager.getTextResource("Hello");
	K_Text text_1 = text_0;


	K_Text monkeyobj = _manager.getTextResource("monkey");
	K_Text squareObj = _manager.getTextResource("sprite");

	K_VertexBuffer vertexBuffer = K_FileManager::instance().decodeObjFileToVertexBuffer(squareObj->getText()); //= K_FileManager::instance().decodeObjFileToVertexBuffer(objMonkey->getText());

	/*
	for (auto vertex : vertexBuffer.getData())
	{
		printf("u %f\n",vertex._uv._u);
		printf("v %f\n\n", vertex._uv._v);
	}
	*/

	K_Text& text_ref = text_0;

	K_Shader vertShader = _manager.getShaderResource("testVert");
	K_Shader fragShader = _manager.getShaderResource("testFrag");


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

	K_WinApiWindow* _window = K_WinApiWindow::createWindow(_windowConfig);
	_window->setInputCallback(&inputCallback);
	_window->showDefaultWindow();


	K_RenderEngine _renderEngine;
	_renderEngine.initilize();
	K_RenderID shaderID = _renderEngine.createShaderProgram(vertShader, fragShader);


	/**********************************************
	OPENGL STUFF 
	************************************************/
	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, (vertexBuffer.getData().size() * sizeof(K_Vertex)), &(vertexBuffer.getData()[0]), GL_STATIC_DRAW);
	

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(K_Vertex), (void*)offsetof(K_Vertex, _position));
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(K_Vertex), (void*)offsetof(K_Vertex, _uv));

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(K_Vertex), (void*)offsetof(K_Vertex, _uv));
	glEnableVertexAttribArray(1);
	
	glActiveTexture(GL_TEXTURE0);

	GLuint location = glGetUniformLocation(shaderID, "myTextureSampler");
	glUniform1i(location, 0);

	GLuint newID;
	glGenTextures(1, &newID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, newID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_0->getWidth(), texture_0->getWidth(), 0, GL_RGBA, GL_UNSIGNED_BYTE, &(texture_0->getTextureData()[0]));

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D);

	GLuint text_loc = glGetUniformLocation(shaderID, "myTextureSampler");

	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)_windowConfig._width / (float)_windowConfig._height, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(camerax, cameray, cameraz), glm::vec3(0, 0, 0), glm::vec3(0, 1, 1));
	glm::mat4 model = glm::mat4(2.0f);

	glm::mat4 mvp = projection * view * model;

	GLuint matrixID = glGetUniformLocation(shaderID, "MVP");


	/**********************************************
	OPENGL STUFF END
	************************************************/


	/**********************************************
	Main Loop
	************************************************/
	bool swapper = false;

#define MS_PER_UPDATE .1666

	time_t previous = time(NULL);
	time_t current;
	double lag = 0.0;
	double elapsedTime = 0.0;
	while (true)

	while(!_window->shouldClose())
	{
		_window->swapBuffers();
	
		current = time(NULL);
		elapsedTime = difftime(current, previous);
		previous = current;
		lag += elapsedTime;
		
		K_REPRINT_DEBUG("Currnet lag: %g    ", lag);
		//printf("\rCurrnet lag: %g    ", lag);

		//_somethingManager.processInput()
		int i = 0;
		while (lag >= MS_PER_UPDATE)
		{
			//_processManager.tick(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
			i += 1;
		}
		K_PRINT_DEBUG("updates %d", i);
		//printf("updates %d", i);

		//_renderManager.render(lag / MS_PER_UPDATE);


		for (auto & vertex : vertexBuffer.getData())
		{
			if (swapper == false)
			{
				vertex.setUV(vertex._uv._u += .25, vertex._uv._v);
			}
			else if (swapper == true)
			{
				vertex.setUV(vertex._uv._u -= .25, vertex._uv._v);
			}
		}

		if (swapper == false)
		{
			swapper = true;
		}
		else if (swapper == true)
		{
			swapper = false;
		}
		glBufferData(GL_ARRAY_BUFFER, (vertexBuffer.getData().size() * sizeof(K_Vertex)), &(vertexBuffer.getData()[0]), GL_STATIC_DRAW);


		view = glm::lookAt(glm::vec3(camerax, cameray, cameraz), glm::vec3(0, 0, 0), glm::vec3(0, 1, 1));
		mvp = projection * view * model;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glUseProgram(shaderID);

		//bind Texture
		glBindTexture(GL_TEXTURE_2D, newID);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		glUniform1i(text_loc, 0);
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(K_Vertex), (void*)offsetof(K_Vertex, _position));
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(K_Vertex), (void*)offsetof(K_Vertex, _uv));


		glDrawArrays(GL_TRIANGLES, 0, vertexBuffer.getData().size());

		glBindTexture(GL_TEXTURE_2D, 0);

		MSG msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}

	K_PRINTLN_DEBUG("\nProgram executed sucessfully press enter to terminate...");
	//printf("\nProgram executed sucessfully press enter to terminate...");
	getchar();
}