#ifndef __K_ABSTRACTENTITYFACTORY_HPP__
#define __K_ABSTRACTENTITYFACTORY_HPP__


#include "K_Entity.hpp"
#include <tinyxml2.h>


class K_AbstractEntityFactory
{
public:
	friend class K_EntityManager;

	K_AbstractEntityFactory();
	~K_AbstractEntityFactory();


	K_Entity* createEntity(const tinyxml2::XMLElement* descriptorNode);

	

private:

	K_EntityComponent* createComponent(const tinyxml2::XMLElement* descriptorNode);


};

#endif // __K_ABSTRACTENTITYFACTORY_HPP__
