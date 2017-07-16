#ifndef __K_RESOURCE_HPP__
#define __K_RESOURCE_HPP__


#include <memory>
#include <string>


class K_Resource
{
public:
	K_Resource() {};
	virtual ~K_Resource() {};

	virtual void initilize(std::string definitionLocation) = 0;

private:


};


typedef std::shared_ptr<K_Resource> K_ResourcePtr;
typedef std::weak_ptr<K_Resource> K_WeakResourcePtr;


#endif // __K_RESOURCE_HPP__