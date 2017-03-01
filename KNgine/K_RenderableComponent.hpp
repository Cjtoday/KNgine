#ifndef __K_RENDERABLECOMPONENT_HPP__
#define __K_RENDERABLECOMPONENT_HPP__

#include "K_EntityComponent.hpp"
#include "K_Resource.hpp"
#include "K_VertexBuffer.hpp"


class K_RenderableComponent : public K_EntityComponent
{
public:
	K_RenderableComponent() {};
	virtual ~K_RenderableComponent();

	virtual void update() = 0;
	virtual void initilize(const tinyxml2::XMLElement* descriptorElement) = 0;
	

	virtual const K_VertexBuffer& getVertexData();
	

private:

	K_VertexBuffer _vertexData;
	K_Texture _texture;

};


#endif // __K_RENDERABLECOMPONENT_HPP__
