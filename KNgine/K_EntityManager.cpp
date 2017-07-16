#include "K_EntityManager.hpp"


K_EntityManager::K_EntityManager(K_ResourceManager& resourceManager) : _resourceManager(resourceManager)
{

}



K_EntityManager::~K_EntityManager()
{

}



K_EntityID K_EntityManager::createEntityHandle(std::string id)
{
	K_EntityTemplateResourcePtr entityTemplate = _resourceManager.getEntityTemplateResource(id);

	K_EntityID newEntityId = _nextID;

	if (_freeEntityIDs.empty())
	{
		++_nextID;
	}
	else
	{
		newEntityId = _freeEntityIDs.back();
		_freeEntityIDs.pop_back();
	}
	_entityVector[newEntityId] = _entityFactory.createEntity(entityTemplate->getTemplate().FirstChildElement());

	return newEntityId;

}



void K_EntityManager::removeEntity(K_EntityID id)
{
	delete _entityVector[id];
	_freeEntityIDs.push_back(id);
}



void K_EntityManager::addComponentToEntity(K_EntityID id, K_EntityComponentID componentID)
{
	
}



void K_EntityManager::clearAllEntities(void)
{
	for (const auto& entity : _entityVector)
	{
		delete entity;
	}

	_freeEntityIDs.clear();

	_nextID = 0;

}



