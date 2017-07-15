#include "TestResourceManager.hpp"
#include "K_Config.hpp"
ResourceManager::ResourceManager(): _textResourceCache(K_TEXTURE_RESOURCE_LIST_LOCATION)
{

}

ResourceManager::~ResourceManager()
{
}

TextResourcePtr ResourceManager::getTextResource(std::string id)
{
	TextResourcePtr ptr = _textResourceCache.getResource("text_01");
	return ptr;
}
