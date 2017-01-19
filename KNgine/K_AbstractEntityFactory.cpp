#include "K_AbstractEntityFactory.hpp"

K_AbstractEntityFactory::K_AbstractEntityFactory()
{
}

K_AbstractEntityFactory::~K_AbstractEntityFactory()
{
}

K_Entity* K_AbstractEntityFactory::createEntity(const tinyxml2::XMLElement* descriptorNode)
{
	return nullptr;
}

K_EntityComponent* K_AbstractEntityFactory::createComponent(const tinyxml2::XMLElement* descriptorNode)
{
	return nullptr;
}
