#include "K_RenderEngine.hpp"
#include "K_Error.hpp"


K_RenderEngine::K_RenderEngine()
{
}

K_RenderEngine::~K_RenderEngine()
{
}

void K_RenderEngine::initilize()
{
	if (glewInit() == GLEW_OK)
	{
		printf("openGL version: %s\n", glGetString(GL_VERSION));
	}
	else
	{
		printf(" GLEW not initilized, openGL version: %s\n", glGetString(GL_VERSION));
	}
	glClearColor(1, 1, 0, 1);
}

void K_RenderEngine::createWindow(const K_WindowConfig config)
{
	K_Error glfwError("initilizing GLFW3", "init Failed");
	if (!glfwInit())
	{
		K_Error::dump();
	}

	_window = glfwCreateWindow(config._width, config._height, config._title, NULL, NULL);

	K_Error windowError("creating GLFW Window", "creation failed");
	if (!_window)
	{
		glfwTerminate();
		K_Error::dump();
	}

	glfwMakeContextCurrent(_window);
}
