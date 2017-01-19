#ifndef __K_ENTITY_HPP__
#define __K_ENTITY_HPP__



#include <vector>

#include "K_EntityComponent.hpp"


typedef unsigned int K_EntityID;

class K_Entity
{
public:
	K_Entity();
	~K_Entity();



	K_EntityID getEntityID();
	void setID(K_EntityID id);

	void addComponent(K_EntityComponent* component);
	void removeComponent(K_EntityComponent* component);



private:

	std::vector<K_EntityComponent*> _componentList;

	K_EntityID _id;
};

#endif // __K_ENTITY_HPP__
