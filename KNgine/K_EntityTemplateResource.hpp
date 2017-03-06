#ifndef __K_ENTITYTEMPLATERESOURCE_HPP__
#define __K_ENTITYTEMPLATERESOURCE_HPP__

#include "K_IResourceType.hpp"
#include "K_Resource.hpp"
#include <tinyxml2.h>


class K_EntityTemplateResource : public K_IResourceType
{
public:
	K_EntityTemplateResource ();
	~K_EntityTemplateResource ();

	virtual void initilize(std::string definitionLocation);
	const tinyxml2::XMLDocument& getTemplate();

private:

	tinyxml2::XMLDocument _entityTemplate;
};

typedef K_Resource<K_EntityTemplateResource> K_EntityTemplate;

#endif // __K_ENTITYTEMPLATERESOURCE_HPP__
