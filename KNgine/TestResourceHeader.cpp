#include "TestResourceHeader.hpp"

ResourceHeader::ResourceHeader(std::string location): _location(location)
{
}

ResourceHeader::~ResourceHeader()
{
}

K_ResourcePtr ResourceHeader::getResource()
{
	return _resource;
}

long ResourceHeader::getReferenceCount()
{
	return _resource.use_count();
}
