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

	printf("opneGL version: %s\n", glGetString(GL_VERSION));
	printf("GLSL version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

K_RenderID K_RenderEngine::createShaderProgram(K_Shader & vertexShader, K_Shader & fragmentShader)
{

	K_RenderID programID = glCreateProgram();

	if (vertexShader->getShaderID() == 0)
	{
		K_RenderID vertShaderID = glCreateShader(GL_VERTEX_SHADER);

		if (glIsShader(vertShaderID) == GL_FALSE)
		{
			K_Error shaderError("openGL Error", "Could not create Vertex Shader.");
			K_Error::dump();
		}
		vertexShader->setShaderID(vertShaderID);
	}
	if (fragmentShader->getShaderID() == 0)
	{
		K_RenderID fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		if (glIsShader(fragShaderID) == GL_FALSE)
		{
			K_Error shaderError("openGL Error", "Could not create Fragment shader.");
			K_Error::dump();
		}
		fragmentShader->setShaderID(fragShaderID);
	}


	compileShader(vertexShader);
	compileShader(fragmentShader);

	linkShaders(programID, vertexShader->getShaderID(), fragmentShader->getShaderID());

	return programID;
}

K_RenderID K_RenderEngine::registerComponent(K_WeakRenderableComponentPtr renderableComponent)
{
	_components.push_back(renderableComponent);

	return K_RenderID();
}

void K_RenderEngine::render()
{
	for ( const auto& component : _components)
	{
		component.lock()->getVertexData();
	}
}

void K_RenderEngine::compileShader(K_Shader& shader)
{
	const char* shaderCode = shader->getShaderCode().c_str();

	glShaderSource(shader->getShaderID(), 1, &shaderCode, nullptr);
	glCompileShader(shader->getShaderID());

	GLint success = 0;
	glGetShaderiv(shader->getShaderID(), GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shader->getShaderID(), GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> errorLog(maxLength + 1);
		glGetShaderInfoLog(shader->getShaderID(), maxLength, &maxLength, &errorLog[0]);

		glDeleteShader(shader->getShaderID());
		shader->setShaderID(0);

		K_Error compileError("openGL Error", "Error Compiling Shaders");
		K_Error::dump();
	}
}

void K_RenderEngine::linkShaders(K_RenderID shaderProgramID, K_RenderID vertShaderID, K_RenderID fragShaderID)
{
	glAttachShader(shaderProgramID, vertShaderID);
	glAttachShader(shaderProgramID, fragShaderID);

	glLinkProgram(shaderProgramID);

	GLint isLinked = 0;
	glGetProgramiv(shaderProgramID, GL_LINK_STATUS, (int*)&isLinked);

	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(shaderProgramID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetProgramInfoLog(shaderProgramID, maxLength, &maxLength, &errorLog[0]);

		K_Error compileError("openGL Error", "Error Linking Shaders");
		K_Error::dump();
	}
}
