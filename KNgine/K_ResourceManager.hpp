#ifndef __K_RESOURCEMANAGER_HPP__
#define __K_RESOURCEMANAGER_HPP__


#include "K_Config.hpp"
#include "K_ResourceCache.hpp"
#include "K_Resource.hpp"
#include "K_TextResource.hpp"
#include "K_TextureResource.hpp"
#include "K_EntityTemplateResource.hpp"
#include "K_ShaderResource.hpp"



class K_ResourceManager
{
public:
	K_ResourceManager();
	~K_ResourceManager();

	K_Text getTextResource(std::string id);
	K_EntityTemplate getEntityTemplateResource(std::string id);
	K_Texture getTextureResource(std::string id);
	K_Shader getShaderResource(std::string id);

	void dumpResourcesInfo();

private:
	
	K_ResourceCache<K_TextResource> _textResourceCache;
	K_ResourceCache<K_EntityTemplateResource> _entityTemplateResourceCache;
	K_ResourceCache<K_TextureResource> _textureResourceCache;
	K_ResourceCache<K_ShaderResource> _shaderResourceCache;
	
};


#endif // __K_RESOURCEMANAGER_HPP__

