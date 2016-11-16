#ifndef __K_RESOURCECACHE_HPP__
#define __K_RESOURCECACHE_HPP__


#include <string>
#include <map>

#include "K_ResourceHeader.hpp"
#include "K_IResourceType.hpp"

#include "K_Error.hpp"
#include "K_FileManager.hpp"
#include "K_Config.hpp"


#include "tinyxml2.h"


template<typename T>
class K_ResourceCache
{
public:

	//Constructor/Destructor
	///////////////////////////////////////
	K_ResourceCache();
	~K_ResourceCache();



	//Public Functions
	///////////////////////////////////////
	K_ResourceHeader<T>* getResourceHeader(std::string id );	

private:

	//Private Functions
	///////////////////////////////////////
	void initilizeResourceHeaders();


	//Private DataMemebers
	///////////////////////////////////////
	std::map<std::string, K_ResourceHeader<T>*> _resourceHeaders;


};


//Constructor/Destructor IMPL
///////////////////////////////////////
template<typename T>
K_ResourceCache<T>::K_ResourceCache()
{
	initilizeResourceHeaders();
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



//Private Functions IMPL
///////////////////////////////////////
template<typename T>
void K_ResourceCache<T>::initilizeResourceHeaders()
{
	std::string fileContents;
	tinyxml2::XMLDocument doc;

	K_FileManager::instance().readTextToString(K_RESOURCE_LIST_FILE_LOC, fileContents);

	K_Error error1("Initilizing Resource Headers from", K_RESOURCE_LIST_FILE_LOC);
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
}

#endif // __K_RESOURCECACHE_HPP__

