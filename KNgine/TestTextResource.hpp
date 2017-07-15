#pragma once

#include "TestResource.hpp"

class TextResource : public Resource
{
public:
	TextResource ();
	~TextResource ();

	virtual void initilize(std::string definitionLocation);
	const std::string& getText();

private:

	std::string _text;

};

typedef std::weak_ptr<TextResource> WeakTextResourcePtr;
typedef std::shared_ptr<TextResource> TextResourcePtr;