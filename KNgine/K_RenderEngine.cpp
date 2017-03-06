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
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		K_Error glewInitError("openGL Error", "failed to initilize glew");
		K_Error::dump();
	}

	glClearColor(1, 1, 0, 1);
}

K_RenderID K_RenderEngine::createShaderObject(K_Shader & vertexShader, K_Shader & fragmentShader)
{

	K_RenderID programID = glCreateProgram();
	K_RenderID vertShaderID = glCreateShader(GL_VERTEX_SHADER);

	if (!vertShaderID)
	{
		K_Error shaderError("openGL Error", "Could not create Vertex Shader.");
		K_Error::dump();
	}


	return programID;
}


