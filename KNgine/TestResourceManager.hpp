#pragma once

#include "TestResource.hpp"
#include "TestTextResource.hpp"
#include "TestResourceCache.hpp"

#include <string>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	TextResourcePtr getTextResource(std::string id);

private:

	ResourceCache<TextResource> _textResourceCache;

};


