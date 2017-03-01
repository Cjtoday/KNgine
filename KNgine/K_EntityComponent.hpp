#ifndef __K_ENTITYCOMPONENT_HPP__
#define __K_ENTITYCOMPONENT_HPP__


#include <tinyxml2.h>


typedef unsigned int K_EntityComponentID;

class K_EntityComponent
{
public:
	K_EntityComponent() {};
	virtual ~K_EntityComponent();

	virtual void update() = 0;
	virtual void initilize(const tinyxml2::XMLElement* descriptorElement) = 0;
	

};



#endif // __K_ENTITYCOMPONENT_HPP__
