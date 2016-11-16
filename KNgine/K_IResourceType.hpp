#ifndef __K_IRESOURCETYPE_HPP__
#define __K_IRESOURCETYPE_HPP__




class K_IResourceType
{
public:
	K_IResourceType() {};
	virtual ~K_IResourceType() {};

	virtual void initilize(std::string definitionLocation) = 0;

private:
};


#endif // __K_IRESOURCETYPE_HPP__

