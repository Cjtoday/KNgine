#pragma once

#include "TestResourceHeader.hpp"
#include "TestResource.hpp"
#include "K_FileManager.hpp"
#include "K_Error.hpp"
#include "K_Logger.hpp"

#include <type_traits>
#include <memory>
#include <string>
#include <map>

template<typename T>
class ResourceCache
{
	static_assert(std::is_base_of<Resource, T>::value, "T must be a decendent of type Resource");


public:
	ResourceCache(std::string resourceDirectory);
	~ResourceCache();

	std::shared_ptr<T> getResource(std::string id);
	void cleanCache();

private:

	void initilizeResourceHeaders(std::string resourceDirectory);

	std::string _resourceDirectory;
	std::map<std::string, ResourceHeader> _resourceHeaders;
	
};

template<typename T>
ResourceCache<T>::ResourceCache(std::string resourceDirectory) : _resourceDirectory(resourceDirectory)
{
	initilizeResourceHeaders(resourceDirectory);
}

template<typename T>
ResourceCache<T>::~ResourceCache()
{
}

template<typename T>
std::shared_ptr<T> ResourceCache<T>::getResource(std::string id)
{
	auto iter = _resourceHeaders.find(id);
	if (iter == _resourceHeaders.end())
	{
		//TODO Error
	}
	//initilize Resource
	ResourceHeader header = iter->second;
	if (header.getReferenceCount() == 0)
	{
		header.getResource().reset(new T());
	}
	return std::dynamic_pointer_cast<T>(iter->second.getResource());
}

template<typename T>
void ResourceCache<T>::cleanCache()
{

}

template<typename T>
void ResourceCache<T>::initilizeResourceHeaders(std::string resourceDirectory)
{
	std::string fileContents;

	//printf("Initilizing Resource Cache from resource directory: %s\n", resourceDirectory.c_str());

	K_FileManager fm = K_FileManager::instance();
	std::vector<std::string> files = fm.getDirectoryContents(resourceDirectory);

	for (const auto& file : files)
	{
		std::string id = fm.removeFileExtension(file);
		if (_resourceHeaders.find(id) == _resourceHeaders.end())
		{
			_resourceHeaders.insert(std::pair<std::string, ResourceHeader>(id, ResourceHeader(file)));
		}
	}
}