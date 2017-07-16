#ifndef __K_RESOURCEHEADER_HPP__
#define __K_RESOURCEHEADER_HPP__


#include "K_Resource.hpp"
#include "K_Logger.hpp"

#include <string>

template<typename T>
class K_ResourceHeader
{
public:
	K_ResourceHeader(std::string location);
	~K_ResourceHeader();

	void initilizeResource();

	std::shared_ptr<T> getResource();
	long getReferenceCount();	

private:

	std::string _location;
	std::shared_ptr<T> _resource;

};

template<typename T>
K_ResourceHeader<T>::K_ResourceHeader(std::string location) : _location(location), _resource()
{
}


template<typename T>
K_ResourceHeader<T>::~K_ResourceHeader()
{
}


template<typename T>
void K_ResourceHeader<T>::initilizeResource()
{
	K_PRINTLN_DEBUG("RESOURCE %s COUNT: %d", _location.c_str(), _resource.use_count());
	_resource.reset(new T());
	K_PRINTLN_DEBUG("RESOURCE %s COUNT: %d", _location.c_str(), _resource.use_count());
	_resource->initilize(_location);
}


template<typename T>
std::shared_ptr<T> K_ResourceHeader<T>::getResource()
{
	return _resource;
}


template<typename T>
long K_ResourceHeader<T>::getReferenceCount()
{
	return _resource.use_count();
}

#endif // __K_RESOURCEHEADER_HPP__
