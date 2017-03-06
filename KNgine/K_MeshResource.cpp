#include "K_MeshResource.hpp"
#include "K_FileManager.hpp"

K_MeshResource::K_MeshResource()
{
}

K_MeshResource::~K_MeshResource()
{
}

void K_MeshResource::initilize(std::string definitionLocation)
{
	std::vector<unsigned char> fileData;
	K_FileManager::instance().readBinaryToBuffer(definitionLocation.c_str(), fileData);
}

K_VertexBuffer * K_MeshResource::getVertexData()
{
	return &_vertexBuffer;
}
