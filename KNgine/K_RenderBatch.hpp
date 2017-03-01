#ifndef __K_RENDERBATCH_HPP__
#define __K_RENDERBATCH_HPP__

#include "K_VertexBuffer.hpp"

class K_RenderBatch
{
public:
	K_RenderBatch();
	~K_RenderBatch();

private:

	K_VertexBuffer _batchVertexBuffer;

	
};


#endif