#ifndef __K_RENDERABLEOBJECT_HPP__
#define __K_RENDERABLEOBJECT_HPP__

#include "K_MeshResource.hpp"
#include "K_VertexBuffer.hpp"


typedef unsigned int K_RenderID;


class K_RenderableObject
{
public:
	K_RenderableObject(K_Mesh mesh);
	~K_RenderableObject();

	K_RenderID getVertexBufferID();
	K_RenderID getShaderID();
	K_RenderID getTextureID();

	K_VertexBuffer* getMeshData();

private:
	
	K_RenderID _vertexBufferID;
	K_RenderID _shaderID;
	K_RenderID _textureID;

	K_Mesh _mesh;

};


#endif // __K_RENDERABLEOBJECT_HPP__
