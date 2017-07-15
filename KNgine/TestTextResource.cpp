#include "TestTextResource.hpp"

TextResource::TextResource()
{
}

TextResource::~TextResource()
{
}

void TextResource::initilize(std::string definitionLocation)
{
	_text = "This is a test";
}

const std::string & TextResource::getText()
{
	// TODO: insert return statement here
	return _text;
}
