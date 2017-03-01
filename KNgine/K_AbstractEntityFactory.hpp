#ifndef __K_ABSTRACTENTITYFACTORY_HPP__
#define __K_ABSTRACTENTITYFACTORY_HPP__


#include "K_Entity.hpp"
#include <tinyxml2.h>
#include <map>
#include <string>

class K_AbstractEntityFactory
{
public:
	friend class K_EntityManager;

	typedef K_EntityComponent* (K_AbstractEntityFactory::*CreatorFunction)(void);
	typedef std::map<std::string, CreatorFunction> CreatorFunctionMap;

	K_AbstractEntityFactory();
	~K_AbstractEntityFactory();


	K_Entity* createEntity(const tinyxml2::XMLElement* descriptorNode);

	

private:

	K_EntityComponent* createComponent(const tinyxml2::XMLElement* descriptorNode);
	K_EntityComponent* createSprite2D();

	CreatorFunctionMap _creatorFunctions;

};

#endif // __K_ABSTRACTENTITYFACTORY_HPP__
