#include "K_RenderableObject.hpp"

K_RenderableObject::K_RenderableObject(K_Mesh mesh) : _mesh(mesh)
{
}

K_RenderableObject::~K_RenderableObject()
{
}

K_RenderID K_RenderableObject::getVertexBufferID()
{
	return _vertexBufferID;
}

K_RenderID K_RenderableObject::getShaderID()
{
	return _shaderID;
}

K_RenderID K_RenderableObject::getTextureID()
{
	return _textureID;
}

K_VertexBuffer * K_RenderableObject::getMeshData()
{
	return _mesh->getVertexData();
}
