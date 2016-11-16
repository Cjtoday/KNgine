#ifndef __K_RESOURCEHEADER_HPP__
#define __K_RESOURCEHEADER_HPP__

#include <string>

#include "K_Error.hpp"


template <typename T>
class K_ResourceHeader
{
public:

	//Constructor/Destructor
	///////////////////////////////////////
	K_ResourceHeader(std::string location);
	~K_ResourceHeader();


	//Public Functions
	///////////////////////////////////////
	T* getResourceData();
	void setResourceData(T* resourceData);

	unsigned int& getReferenceCount();
	std::string getResourceDefinitionLocation();

private:


	//Private DataMembers
	///////////////////////////////////////
	std::string _location;

	unsigned int _referenceCount;

	T* _resource;

};



//Constructor/Destructor IMPL
///////////////////////////////////////
template <typename T>
K_ResourceHeader<T>::K_ResourceHeader(std::string location) : _location(location), _referenceCount(0)
{

}


template <typename T>
K_ResourceHeader<T>::~K_ResourceHeader()
{
	if (_resource)
	{
		delete _resource;
	}
}


//Public Functions
///////////////////////////////////////
template <typename T>
T* K_ResourceHeader<T>::getResourceData()
{
	return _resource;
}


template<typename T>
inline void K_ResourceHeader<T>::setResourceData(T* resourceData)
{

	K_Error error("Error setting data of resource header", _location);
	if (!_referenceCount)
	{
		_resource = resourceData;
	}
	else
	{
		K_Error::dump();
	}
}



template<typename T>
inline unsigned int& K_ResourceHeader<T>::getReferenceCount()
{
	return _referenceCount;
}



template <typename T>
std::string K_ResourceHeader<T>::getResourceDefinitionLocation()
{
	return _location;
}

#endif // __K_RESOURCEHEADER_HPP__

