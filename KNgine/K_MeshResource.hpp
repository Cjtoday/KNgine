#ifndef __K_MESHRESOURCE_HPP__
#define __K_MESHRESOURCE_HPP__

#include "K_IResourceType.hpp"
#include "K_Resource.hpp"
#include "K_VertexBuffer.hpp"



class K_MeshResource : public K_IResourceType
{
public:
	K_MeshResource();
	~K_MeshResource();

	virtual void initilize(std::string definitionLocation);
	K_VertexBuffer* getVertexData();

private:

	K_VertexBuffer _vertexBuffer;
	
};

typedef K_Resource<K_MeshResource> K_Mesh;


#endif // __K_MESHRESOURCE_HPP__
