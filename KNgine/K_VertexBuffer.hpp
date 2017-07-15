#ifndef __K_VERTEXBUFFER_HPP__
#define __K_VERTEXBUFFER_HPP__


#include "K_Vertex.hpp"

#include <vector>


class K_VertexBuffer
{
public:
	K_VertexBuffer();
	~K_VertexBuffer();

	void addVertex(K_Vertex vertex);

	void appendBuffer(K_VertexBuffer& buffer);
	void clearBuffer(void);
	std::vector<K_Vertex>& getData();

private:


	std::vector<K_Vertex>  _data;

};


#endif // __K_VERTEXBUFFER_HPP__
