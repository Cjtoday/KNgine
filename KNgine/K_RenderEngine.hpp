#ifndef __K_RENDERENGINE_HPP__
#define __K_RENDERENGINE_HPP__


#include "K_WindowConfig.hpp"
//Must include glew before glfw for now. hopefully replace glfw soonish
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class K_RenderEngine
{
public:
	K_RenderEngine();
	~K_RenderEngine();

	void initilize();

	void createWindow(const struct K_WindowConfig config);
	
	
private:

	GLFWwindow* _window;



};


#endif // __K_RENDERENGINE_HPP__
