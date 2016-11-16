#include "K_ResourceManager.hpp"

K_ResourceManager::K_ResourceManager()
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
