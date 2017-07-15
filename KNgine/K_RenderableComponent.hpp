#ifndef __K_RENDERABLECOMPONENT_HPP__
#define __K_RENDERABLECOMPONENT_HPP__

#include "K_EntityComponent.hpp"
#include "K_Resource.hpp"
#include "K_VertexBuffer.hpp"
#include "K_Vector.hpp"

#include <memory>


class K_RenderableComponent : public K_EntityComponent
{
public:
	K_RenderableComponent() {};
	virtual ~K_RenderableComponent();

	virtual void update() = 0;
	virtual void initilize(const tinyxml2::XMLElement* descriptorElement) = 0;
	

	virtual const K_VertexBuffer& getVertexData();
	
	float _rotateX;
	float _rotateY;
	float _rotateZ;

	float _translateX;
	float _translateY;
	float _translateZ;

	float _scaleX;
	float _scaleY;
	float _scaleZ;

private:




	K_VertexBuffer _vertexData;

	


};

typedef std::weak_ptr<K_RenderableComponent> K_WeakRenderableComponentPtr;
typedef std::shared_ptr<K_RenderableComponent> K_RenderableComponentPtr;


#endif // __K_RENDERABLECOMPONENT_HPP__
