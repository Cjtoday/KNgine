#ifndef __K_TEXTRESOURCE_HPP__
#define __K_TEXTRESOURCE_HPP__


#include "K_IResourceType.hpp"
#include "K_Resource.hpp"



class K_TextResource : public K_IResourceType
{
public:
	K_TextResource();
	~K_TextResource();

	virtual void initilize(std::string definitionLocation);
	const std::string& getText();

private:

	std::string _text;

};

typedef K_Resource<K_TextResource> K_Text;


#endif // __K_TEXTRESOURCE_HPP__

