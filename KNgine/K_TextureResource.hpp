#ifndef __K_TEXTURERESOURCE_HPP__
#define __K_TEXTURERESOURCE_HPP__


#include "K_IResourceType.hpp"
#include "K_Resource.hpp"


#include <vector>


class K_TextureResource : public K_IResourceType
{
public:
	K_TextureResource();
	~K_TextureResource();

	virtual void initilize(std::string definitionLocation);
	const std::vector<unsigned char>& getTextureData();
	const unsigned long getWidth();
	const unsigned long getHeight();

private:

	std::vector<unsigned char> _textureData;
	unsigned long _width;
	unsigned long _height;

};


typedef K_Resource<K_TextureResource> K_Texture;


#endif // __K_TEXTURERESOURCE_HPP__
