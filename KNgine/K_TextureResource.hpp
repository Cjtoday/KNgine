#ifndef __K_TEXTURERESOURCE_HPP__
#define __K_TEXTURERESOURCE_HPP__


#include "K_Resource.hpp"

#include <vector>


class K_TextureResource : public K_Resource
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


typedef std::shared_ptr<K_TextureResource> K_TextureResourcePtr;
typedef std::weak_ptr<K_TextureResource> K_WeakTextureResourcePtr;


#endif // __K_TEXTURERESOURCE_HPP__
