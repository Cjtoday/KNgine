#pragma once

#include <string>
#include "TestResource.hpp"

class ResourceHeader
{
public:
	ResourceHeader(std::string location);
	~ResourceHeader();

	K_ResourcePtr getResource();

	long getReferenceCount();	

private:

	std::string _location;
	K_ResourcePtr _resource;

};
