#ifndef __K_VERTEXBUFFER_HPP__
#define __K_VERTEXBUFFER_HPP__


#include "K_Vertex.hpp"

#include <vector>


class K_VertexBuffer
{
public:
	K_VertexBuffer();
	~K_VertexBuffer();

private:


	std::vector<K_Vertex>  _data;

};


#endif // __K_VERTEXBUFFER_HPP__
