#include "K_VertexBuffer.hpp"

K_VertexBuffer::K_VertexBuffer()
{
}

K_VertexBuffer::~K_VertexBuffer()
{
}

void K_VertexBuffer::addVertex(K_Vertex vertex)
{
	_data.push_back(vertex);
}

void K_VertexBuffer::appendBuffer(K_VertexBuffer & buffer)
{
	std::vector<K_Vertex> newDataBuffer;
	newDataBuffer.reserve(_data.size() + buffer.getData().size());
	newDataBuffer.insert(newDataBuffer.end(), _data.begin(), _data.end());
	newDataBuffer.insert(newDataBuffer.end(), buffer.getData().begin(), buffer.getData().end());
	
	_data = newDataBuffer;
}

void K_VertexBuffer::clearBuffer(void)
{
	_data.clear();
	_data.shrink_to_fit();
}

std::vector<K_Vertex>& K_VertexBuffer::getData()
{
	return _data;
}
