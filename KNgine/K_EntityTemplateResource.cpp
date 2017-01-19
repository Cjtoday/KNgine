#include "K_EntityTemplateResource.hpp"
#include "K_FileManager.hpp"
#include "K_Error.hpp"

K_EntityTemplateResource::K_EntityTemplateResource()
{
}

K_EntityTemplateResource::~K_EntityTemplateResource()
{
}

void K_EntityTemplateResource::initilize(std::string definitionLocation)
{
	std::string xmlText;
	K_FileManager::instance().readTextToString(definitionLocation.c_str(), xmlText);

	K_Error error("Error parsing std::string to tinyxml2::XMLDocument", definitionLocation);
	if (_entityTemplate.Parse(xmlText.c_str()) != tinyxml2::XML_SUCCESS)
	{
		K_Error::dump();
	}

}

const  tinyxml2::XMLDocument& K_EntityTemplateResource::getTemplate()
{
	return _entityTemplate;
}
