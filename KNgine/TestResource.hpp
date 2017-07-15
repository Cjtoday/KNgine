#pragma once


#include <memory>
#include <string>

class Resource
{
public:
	Resource() {};
	virtual ~Resource() {};

	virtual void initilize(std::string definitionLocation) = 0;

private:


};

typedef std::weak_ptr<Resource> K_WeakResourcePtr;
typedef std::shared_ptr<Resource> K_ResourcePtr;