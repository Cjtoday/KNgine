#include "K_TextResource.hpp"
#include "K_FileManager.hpp"

K_TextResource::K_TextResource()
{
}

K_TextResource::~K_TextResource()
{
}


const std::string& K_TextResource::getText()
{
	return _text;
}

void K_TextResource::initilize(std::string definitionLocation)
{
	K_FileManager::instance()->readTextToString(definitionLocation.c_str(), _text);
}
