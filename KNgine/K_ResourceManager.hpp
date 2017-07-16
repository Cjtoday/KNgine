#ifndef __K_RESOURCEMANAGER_HPP__
#define __K_RESOURCEMANAGER_HPP__


#include "K_Resource.hpp"
#include "K_TextResource.hpp"
#include "K_MeshResource.hpp"
#include "K_ShaderResource.hpp"
#include "K_TextureResource.hpp"
#include "K_EntityTemplateResource.hpp"

#include "K_ResourceCache.hpp"

#include <string>


class K_ResourceManager
{
public:
	K_ResourceManager();
	~K_ResourceManager();

	K_TextResourcePtr getTextResource(std::string id);
	K_EntityTemplateResourcePtr getEntityTemplateResource(std::string id);
	K_MeshResourcePtr getMeshResource(std::string id);
	K_ShaderResourcePtr getShaderResource(std::string id);
	K_TextureResourcePtr getTextureResource(std::string id);

private:

	K_ResourceCache<K_TextResource> _textResourceCache;
	K_ResourceCache<K_EntityTemplateResource> _entityTemplateResourceCache;
	K_ResourceCache<K_MeshResource> _meshResourceCache;
	K_ResourceCache<K_ShaderResource> _shaderResourceCache;
	K_ResourceCache<K_TextureResource> _textureResourceCache;

};


#endif // __K_RESOURCEMANAGER_HPP__
