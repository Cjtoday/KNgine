#ifndef __K_RESOURCEMANAGER_HPP__
#define __K_RESOURCEMANAGER_HPP__



#include "K_ResourceCache.hpp"
#include "K_Resource.hpp"
#include "K_TextResource.hpp"

typedef K_Resource<K_TextResource> K_Text; 


class K_ResourceManager
{
public:
	K_ResourceManager();
	~K_ResourceManager();

	K_Text getTextResource(std::string id);

private:
	
	K_ResourceCache<K_TextResource> _textResourceCache;
};


#endif // __K_RESOURCEMANAGER_HPP__

