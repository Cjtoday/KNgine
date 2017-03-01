#ifndef __K_TEXTURERESOURCE_HPP__
#define __K_TEXTURERESOURCE_HPP__


#include "K_RendererObject.hpp"
#include "K_IResourceType.hpp"

#include <vector>


class K_TextureResource : public K_RendererObject, public K_IResourceType
{
public:
	K_TextureResource();
	~K_TextureResource();

	virtual void initilize(std::string definitionLocation);
	const std::vector<unsigned char>& getTextureData();


private:

	std::vector<unsigned char> _textureData;
	

};



#endif // __K_TEXTURERESOURCE_HPP__
