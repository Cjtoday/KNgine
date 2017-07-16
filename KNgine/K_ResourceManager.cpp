#include "K_ResourceManager.hpp"
#include "K_Config.hpp"


K_ResourceManager::K_ResourceManager(): 
	_textResourceCache(K_TEXT_RESOURCE_DIR),
	_entityTemplateResourceCache(K_ENTITYTEMPLATE_RESOURCE_DIR),
	_meshResourceCache(K_MESH_RESOURCE_DIR),
	_shaderResourceCache(K_SHADER_RESOURCE_DIR),
	_textureResourceCache(K_TEXTURE_RESOURCE_DIR)
{

}


K_ResourceManager::~K_ResourceManager()
{
}


K_TextResourcePtr K_ResourceManager::getTextResource(std::string id)
{
	return _textResourceCache.getResource(id);
}

K_EntityTemplateResourcePtr K_ResourceManager::getEntityTemplateResource(std::string id)
{
	return _entityTemplateResourceCache.getResource(id);
}

K_MeshResourcePtr K_ResourceManager::getMeshResource(std::string id)
{
	return _meshResourceCache.getResource(id);
}

K_ShaderResourcePtr K_ResourceManager::getShaderResource(std::string id)
{
	return _shaderResourceCache.getResource(id);
}

K_TextureResourcePtr K_ResourceManager::getTextureResource(std::string id)
{
	return _textureResourceCache.getResource(id);
}
