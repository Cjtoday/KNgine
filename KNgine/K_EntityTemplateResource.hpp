#ifndef __K_ENTITYTEMPLATERESOURCE_HPP__
#define __K_ENTITYTEMPLATERESOURCE_HPP__

#include "K_Resource.hpp"
#include <tinyxml2.h>


class K_EntityTemplateResource : public K_Resource
{
public:
	K_EntityTemplateResource ();
	~K_EntityTemplateResource ();

	virtual void initilize(std::string definitionLocation);
	const tinyxml2::XMLDocument& getTemplate();

private:

	tinyxml2::XMLDocument _entityTemplate;
};


typedef std::shared_ptr<K_EntityTemplateResource> K_EntityTemplateResourcePtr;
typedef std::weak_ptr<K_EntityTemplateResource> K_WeakEntityTemplateResourcePtr;


#endif // __K_ENTITYTEMPLATERESOURCE_HPP__
