#ifndef __K_RENDERENGINE_HPP__
#define __K_RENDERENGINE_HPP__


#include "K_WindowConfig.hpp"
#include "K_ShaderResource.hpp"
#include "K_RenderableComponent.hpp"

#include <GL/glew.h>
#include <glm.hpp>
#include <string>
#include <vector>


class K_RenderEngine
{
public:
	K_RenderEngine();
	~K_RenderEngine();

	void initilize();
	K_RenderID createShaderProgram(K_Shader& vertexShader, K_Shader& fragmentShader);

	K_RenderID registerComponent(K_WeakRenderableComponentPtr renderableComponent);
	void render();

		
private:

	std::vector<K_WeakRenderableComponentPtr> _components;

	void compileShader(K_Shader& shader);
	void linkShaders(K_RenderID shaderProgramID, K_RenderID vertShaderID, K_RenderID fragShaderID);

};


#endif // __K_RENDERENGINE_HPP__
