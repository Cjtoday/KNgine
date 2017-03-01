#include "K_ResourceManager.hpp"


K_ResourceManager::K_ResourceManager() :
	_textResourceCache(K_TEXT_RESOURCE_LIST_LOCATION),
	_entityTemplateResourceCache(K_ENTITYTEMPLATE_RESOURCE_LIST_LOCATION),
	_textureResourceCache(K_TEXTURE_RESOURCE_LIST_LOCATION)
{
}



K_ResourceManager::~K_ResourceManager()
{
}



K_Text K_ResourceManager::getTextResource(std::string id)
{
	K_ResourceHeader<K_TextResource>* resourceHeader = _textResourceCache.getResourceHeader(id);

	if (!(resourceHeader->getReferenceCount()))
	{
		K_TextResource* resource = new K_TextResource();
		resource->initilize(resourceHeader->getResourceDefinitionLocation());

		resourceHeader->setResourceData(resource);
	}

	return K_Text(resourceHeader->getReferenceCount(), resourceHeader->getResourceData());
}



K_EntityTemplate K_ResourceManager::getEntityTemplateResource(std::string id)
{
	K_ResourceHeader<K_EntityTemplateResource>* resourceHeader = _entityTemplateResourceCache.getResourceHeader(id);

	if (!(resourceHeader->getReferenceCount()))
	{
		K_EntityTemplateResource* resource = new K_EntityTemplateResource();
		resource->initilize(resourceHeader->getResourceDefinitionLocation());

		resourceHeader->setResourceData(resource);
	}

	return K_EntityTemplate(resourceHeader->getReferenceCount(), resourceHeader->getResourceData());
}



K_Texture K_ResourceManager::getTextureResource(std::string id)
{
	K_ResourceHeader<K_TextureResource>* resourceHeader = _textureResourceCache.getResourceHeader(id);

	if (!(resourceHeader->getReferenceCount()))
	{
		K_TextureResource* resource = new K_TextureResource();
		resource->initilize(resourceHeader->getResourceDefinitionLocation());

		resourceHeader->setResourceData(resource);
	}

	return K_Texture(resourceHeader->getReferenceCount(), resourceHeader->getResourceData());
}


void K_ResourceManager::dumpResourcesInfo()
{

	printf("Text Resources\n");
	printf("---------------------------------------------\n");
	_textResourceCache.printResourceHeaderInfo();
	printf("---------------------------------------------\n\n");



	printf("Entity Template Resources\n");
	printf("---------------------------------------------\n");
	_entityTemplateResourceCache.printResourceHeaderInfo();
	printf("---------------------------------------------\n\n");



	printf("Texture Resurces\n");
	printf("---------------------------------------------\n");
	_textureResourceCache.printResourceHeaderInfo();
	printf("---------------------------------------------\n\n");

}