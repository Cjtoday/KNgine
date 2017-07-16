#ifndef __K_MESHRESOURCE_HPP__
#define __K_MESHRESOURCE_HPP__


#include "K_Resource.hpp"
#include "K_VertexBuffer.hpp"


class K_MeshResource : public K_Resource
{
public:
	K_MeshResource();
	~K_MeshResource();

	virtual void initilize(std::string definitionLocation);
	K_VertexBuffer* getVertexData();

private:

	K_VertexBuffer _vertexBuffer;
	
};


typedef std::shared_ptr<K_MeshResource> K_MeshResourcePtr;
typedef std::weak_ptr<K_MeshResource> K_WeakMeshResourcetr;


#endif // __K_MESHRESOURCE_HPP__
