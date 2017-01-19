#ifndef __K_ENTITYMANAGER_HPP__
#define __K_ENTITYMANAGER_HPP__

#include <string>
#include <vector>

#include "K_Entity.hpp"
#include "K_ResourceManager.hpp"
#include "K_AbstractEntityFactory.hpp"

class K_EntityManager
{
public:
	K_EntityManager(K_ResourceManager& resourceManager);
	virtual	~K_EntityManager();


	K_EntityID createEntityHandle(std::string id);
	void removeEntity(K_EntityID id);


	void addComponentToEntity(K_EntityID, K_EntityComponentID);
	void clearAllEntities(void);


private:

	K_ResourceManager& _resourceManager;

	K_AbstractEntityFactory _entityFactory;

	std::vector <K_Entity*> _entityVector;
	std::vector <K_EntityID> _freeEntityIDs;

	K_EntityID	_nextID;


};
#endif // __K_ENTITYMANAGER_HPP__
