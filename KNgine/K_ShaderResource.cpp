#include "K_ShaderResource.hpp"
#include "K_FileManager.hpp"


K_ShaderResource::K_ShaderResource() : _shaderID(0)
{
}


K_ShaderResource::~K_ShaderResource()
{
}


void K_ShaderResource::initilize(std::string definitionLocation)
{
	K_FileManager::instance()->readTextToString(definitionLocation.c_str(), _shaderCode);
}


void K_ShaderResource::setShaderID(K_RenderID id)
{
	_shaderID = id;
}


K_RenderID K_ShaderResource::getShaderID()
{
	return _shaderID;
}


std::string & K_ShaderResource::getShaderCode()
{
	return _shaderCode;
}
