#ifndef __K_TEXTRESOURCE_HPP__
#define __K_TEXTRESOURCE_HPP__


#include "K_Resource.hpp"


class K_TextResource : public K_Resource
{
public:
	K_TextResource();
	~K_TextResource();

	virtual void initilize(std::string definitionLocation);
	const std::string& getText();

private:

	std::string _text;

};


typedef std::shared_ptr<K_TextResource> K_TextResourcePtr;
typedef std::weak_ptr<K_TextResource> K_WeakTextResourcePtr;


#endif // __K_TEXTRESOURCE_HPP__

