#ifndef __K_RENDERENGINE_HPP__
#define __K_RENDERENGINE_HPP__


#include "K_WindowConfig.hpp"
#include "K_RenderableObject.hpp"
#include "K_ShaderResource.hpp"


#include <GL/glew.h>
#include <vector>


class K_RenderEngine
{
public:
	K_RenderEngine();
	~K_RenderEngine();

	void initilize();
	K_RenderID registerRenderableObject(K_RenderableObject& obj);
	K_RenderID createShaderObject(K_Shader& vertexShader, K_Shader& fragmentShader);

		
private:



};


#endif // __K_RENDERENGINE_HPP__
