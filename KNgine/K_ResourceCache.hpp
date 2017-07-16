#ifndef __K_RESOURCECACHE_HPP__
#define __K_RESOURCECACHE_HPP__


#include "K_ResourceHeader.hpp"
#include "K_Resource.hpp"
#include "K_FileManager.hpp"
#include "K_Error.hpp"
#include "K_Logger.hpp"

#include <type_traits>
#include <memory>
#include <string>
#include <map>


template<typename T>
class K_ResourceCache
{
	static_assert(std::is_base_of<K_Resource, T>::value, "T must be a decendent of type Resource");


public:
	K_ResourceCache(std::string resourceDirectory);
	~K_ResourceCache();

	std::shared_ptr<T> getResource(std::string id);
	void cleanCache();

private:

	void initilizeResourceHeaders(std::string resourceDirectory);

	std::string _resourceDirectory;
	std::map<std::string, K_ResourceHeader<T>> _resourceHeaders;
	
};


template<typename T>
K_ResourceCache<T>::K_ResourceCache(std::string resourceDirectory) : _resourceDirectory(resourceDirectory)
{
	initilizeResourceHeaders(resourceDirectory);
}


template<typename T>
K_ResourceCache<T>::~K_ResourceCache()
{
}


template<typename T>
std::shared_ptr<T> K_ResourceCache<T>::getResource(std::string id)
{
	auto iter = _resourceHeaders.find(id);
	if (iter == _resourceHeaders.end())
	{
		K_PRINTLN_DEBUG("ERROR NO ID %s", id.c_str());//TODO Error
	}
	//initilize Resource
	K_ResourceHeader<T> header = iter->second;
	if (header.getReferenceCount() == 0)
	{
		header.initilizeResource();
	}
	return header.getResource();
}


template<typename T>
void K_ResourceCache<T>::cleanCache()
{

}


template<typename T>
void K_ResourceCache<T>::initilizeResourceHeaders(std::string resourceDirectory)
{
	K_PRINTLN_DEBUG("Initilizing Resource Cache from directory: %s", resourceDirectory.c_str());

	K_FileManagerPtr fm = K_FileManager::instance();
	std::vector<std::string> files;
	fm->getDirectoryContents(files, resourceDirectory);

	for (const auto& file : files)
	{
		std::string id = fm->removeFilePathAndExtension(file);
		if (_resourceHeaders.find(id) == _resourceHeaders.end())
		{
			K_PRINTLN_DEBUG("%10s: %s", "resource found:", id.c_str());
			_resourceHeaders.insert(std::pair<std::string, K_ResourceHeader<T>>(id, K_ResourceHeader<T>(file)));
		}
	}
}


#endif // __K_RESOURCECACHE_HPP__
