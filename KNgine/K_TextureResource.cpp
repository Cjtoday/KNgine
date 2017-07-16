#include "K_TextureResource.hpp"
#include "K_FileManager.hpp"
#include "K_ImageDecoder.hpp"
#include "K_Error.hpp"


K_TextureResource::K_TextureResource() : _width(0), _height(0)
{

}


K_TextureResource::~K_TextureResource()
{

}


void K_TextureResource::initilize(std::string definitionLocation)
{
	std::vector<unsigned char> rawTextureData;
	K_FileManager::instance()->readBinaryToBuffer(definitionLocation.c_str(), rawTextureData);

	int errorCode = K_ImageDecoder::decodePNG(_textureData, _width, _height, &(rawTextureData[0]), rawTextureData.size());
	if (errorCode != 0)
	{
		K_Error textureInitilizationError("Decoding image", definitionLocation);
		K_Error::dump();
	}
}


const std::vector<unsigned char>& K_TextureResource::getTextureData()
{
	return _textureData;
}


const unsigned long K_TextureResource::getWidth()
{
	return _width;
}


const unsigned long K_TextureResource::getHeight()
{
	return _height;
}

