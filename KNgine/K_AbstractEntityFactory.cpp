#include "K_AbstractEntityFactory.hpp"
#include "K_Error.hpp"

K_AbstractEntityFactory::K_AbstractEntityFactory() : _creatorFunctions()
{
	//_creatorFunctions[K_Sprite2DComponent] = &K_AbstractEntityFactory::createSprite2D;
}

K_AbstractEntityFactory::~K_AbstractEntityFactory()
{
}

K_Entity* K_AbstractEntityFactory::createEntity(const tinyxml2::XMLElement* descriptorNode)
{
	K_Entity* newEntity = new K_Entity();
	const tinyxml2::XMLElement* componentElement = descriptorNode->FirstChildElement();
	while(componentElement != nullptr)
	{
		newEntity->addComponent(createComponent(componentElement));
		componentElement = componentElement->NextSiblingElement();
	}
	return newEntity;
}

K_EntityComponent* K_AbstractEntityFactory::createComponent(const tinyxml2::XMLElement* descriptorNode)
{

	K_EntityComponent* newComponent = nullptr;

	std::string type(descriptorNode->Attribute("type"));
	printf("componentType: %s\n", type.c_str());


	auto iter = _creatorFunctions.find(type);
	if (iter == _creatorFunctions.end())
	{
		K_Error componentError("Factory Function Does not exist for type", type);
		K_Error::dump();
	}

	CreatorFunction creator = iter->second;
	newComponent = (this->*creator)();

	newComponent->initilize(descriptorNode);

	return newComponent;
}


K_EntityComponent* K_AbstractEntityFactory::createSprite2D() 
{
	//return new K_Sprite2DComponent();
	return nullptr;
}