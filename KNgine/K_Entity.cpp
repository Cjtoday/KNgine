#include "K_Entity.hpp"

K_Entity::K_Entity()
{

}


K_Entity::~K_Entity()
{

}


K_EntityID K_Entity::getEntityID()
{
	return _id;
}


void K_Entity::setID(K_EntityID id)
{
	_id = id;
}


void K_Entity::addComponent(K_EntityComponent* component)
{
	_componentList.push_back(component);
}

void K_Entity::removeComponent(K_EntityComponent* component)
{

}


