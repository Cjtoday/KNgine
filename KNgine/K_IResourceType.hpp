#ifndef __K_IRESOURCETYPE_HPP__
#define __K_IRESOURCETYPE_HPP__

#include <memory>
#include <string>

class K_IResourceType
{
public:
	K_IResourceType() {};
	virtual ~K_IResourceType() {};

	virtual void initilize(std::string definitionLocation) = 0;

private:
};

//typedef std::weak_ptr<K_IResourceType> K_WeakResourcePtr;
//typedef std::shared_ptr<K_IResourceType> K_ResourcePtr;


#endif // __K_IRESOURCETYPE_HPP__

