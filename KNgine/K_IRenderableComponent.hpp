#ifndef __K_IRENDERABLECOMPONENT_HPP__
#define __K_IRENDERABLECOMPONENT_HPP__

#include "K_EntityComponent.hpp"


class K_IRenderableComponent : public K_EntityComponent
{
public:
	K_IRenderableComponent();
	virtual ~K_IRenderableComponent();

	virtual void update() = 0;
	virtual void initilize(tinyxml2::XMLElement descriptorElement) = 0;



private:

};



#endif // __K_IRENDERABLECOMPONENT_HPP__
