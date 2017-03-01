#ifndef __K_SHADERRESOURCE_HPP__
#define __K_SHADERRESOURCE_HPP__

#include "K_IResourceType.hpp"
#include "K_RendererObject.hpp"


class K_ShaderResource : public K_RendererObject, public K_IResourceType
{
{
public:
	K_ShaderResource();
	~K_ShaderResource();

	virtual void initilize(std::string definitionLocation);

private:

};

#endif // __K_SHADERRESOURCE_HPP__
