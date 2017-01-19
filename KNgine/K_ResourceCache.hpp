#ifndef __K_RESOURCECACHE_HPP__
#define __K_RESOURCECACHE_HPP__


#include <string>
#include <map>

#include "K_ResourceHeader.hpp"
#include "K_IResourceType.hpp"

#include "K_Error.hpp"
#include "K_FileManager.hpp"

#include <tinyxml2.h>



template<typename T>
class K_ResourceCache
{
public:

	//Constructor/Destructor
	///////////////////////////////////////
	K_ResourceCache(std::string resourceLocations);
	~K_ResourceCache();



	//Public Functions
	///////////////////////////////////////
	K_ResourceHeader<T>* getResourceHeader(std::string id);	

	void printResourceHeaderInfo();

private:

	//Private Functions
	///////////////////////////////////////
	void initilizeResourceHeaders(std::string resourceLocations);


	//Private DataMemebers
	///////////////////////////////////////
	std::map<std::string, K_ResourceHeader<T>*> _resourceHeaders;


};


//Constructor/Destructor IMPL
///////////////////////////////////////
template<typename T>
K_ResourceCache<T>::K_ResourceCache(std::string resourceLocations)
{
	initilizeResourceHeaders(resourceLocations);
}


template<typename T>
K_ResourceCache<T>::~K_ResourceCache()
{

}



//Public Functions IMPL
///////////////////////////////////////
template<typename T>
K_ResourceHeader<T>* K_ResourceCache<T>::getResourceHeader(std::string id)
{
	std::map<std::string, K_ResourceHeader<T>*>::iterator iter = _resourceHeaders.find(id);

	K_Error error1("Resource does not exist", id);
	if (iter == _resourceHeaders.end())
	{
		K_Error::dump();
	}
	

	return iter->second;
}

template<typename T>
void K_ResourceCache<T>::printResourceHeaderInfo()
{
	for (std::map<std::string, K_ResourceHeader<T>*>::iterator iter = _resourceHeaders.begin(); iter != _resourceHeaders.end(); ++iter)
	{
		printf("Resource: %s	Active References: %d\n", iter->first.c_str(), iter->second->getReferenceCount());
	}
}


//Private Functions IMPL
///////////////////////////////////////
template<typename T>
void K_ResourceCache<T>::initilizeResourceHeaders(std::string resourceLocations)
{
	std::string fileContents;
	tinyxml2::XMLDocument doc;

	printf("Initilizing Resource Cache from resource list: %s\n", resourceLocations.c_str());

	K_FileManager::instance().readTextToString(resourceLocations.c_str(), fileContents);

	K_Error error1("Initilizing Resource Headers from", resourceLocations);
	if (doc.Parse(fileContents.c_str()) != tinyxml2::XML_SUCCESS)
	{
		K_Error::dump();
	}

	tinyxml2::XMLElement* currentNode = doc.FirstChildElement();

	std::string id;
	std::string location;

	while (currentNode)
	{
		id = currentNode->Attribute("id");
		location = currentNode->GetText();

		printf("ID: %s, Location: %s \n", id.c_str(), location.c_str());
		
		K_ResourceHeader<T>* header = new K_ResourceHeader<T>(location);
		_resourceHeaders.insert(std::pair<std::string, K_ResourceHeader<T>*>(id, header));
		
		currentNode = currentNode->NextSiblingElement();
	}
	printf("\n");
}

#endif // __K_RESOURCECACHE_HPP__

