#ifndef __K_SHADERRESOURCE_HPP__
#define __K_SHADERRESOURCE_HPP__


#include "K_Resource.hpp"
#include "K_RenderID.hpp"

#include <string>


class K_ShaderResource : public K_Resource
{

public:
	K_ShaderResource();
	~K_ShaderResource();

	virtual void initilize(std::string definitionLocation);
	void setShaderID(K_RenderID id);
	K_RenderID getShaderID();
	std::string& getShaderCode();

private:

	K_RenderID _shaderID;
	std::string _shaderCode;

};


typedef std::shared_ptr<K_ShaderResource> K_ShaderResourcePtr;
typedef std::weak_ptr<K_ShaderResource> K_WeakShaderResourcePtr;


#endif // __K_SHADERRESOURCE_HPP__
