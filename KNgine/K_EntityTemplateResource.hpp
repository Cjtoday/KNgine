#ifndef __K_ENTITYTEMPLATERESOURCE_HPP__
#define __K_ENTITYTEMPLATERESOURCE_HPP__

#include "K_IResourceType.hpp"
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


#endif // __K_ENTITYTEMPLATERESOURCE_HPP__
