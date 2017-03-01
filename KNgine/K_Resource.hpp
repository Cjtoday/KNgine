#ifndef __K_RESOURCE_HPP__
#define __K_RESOURCE_HPP__



template <typename T>
class K_Resource
{
public:

	//Constructor/Destructor
	///////////////////////////////////////
	K_Resource(unsigned int& referenceCount, T* resource);
	~K_Resource();


	//Public Functions
	///////////////////////////////////////
	T* getResourceData();

	T* operator->(void);

private:

	//Private Datamembers
	///////////////////////////////////////
	T* _resource;
	unsigned int& _referenceCount;

};




//Constructor/Destructor IMPL
///////////////////////////////////////
template<typename T>
K_Resource<T>::K_Resource(unsigned int& referenceCount, T* resource) : _referenceCount(referenceCount), _resource(resource)
{
	++_referenceCount;
}



template<typename T>
K_Resource<T>::~K_Resource()
{
	--_referenceCount;

	if (!_referenceCount)
	{
		delete _resource;
	}
}



//Public Functions IMPL
///////////////////////////////////////
template<typename T>
T* K_Resource<T>::getResourceData()
{
	return _resource;
}

template<typename T>
T* K_Resource<T>::operator->(void)
{
	return _resource;
}

#endif // __K_RESOURCE_HPP__
