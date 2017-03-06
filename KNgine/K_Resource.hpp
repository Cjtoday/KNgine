#ifndef __K_RESOURCE_HPP__
#define __K_RESOURCE_HPP__



template <typename T>
class K_Resource
{
public:

	//Constructor/Destructor
	///////////////////////////////////////
	K_Resource(unsigned int& referenceCount, T* resource);
	K_Resource(const K_Resource<T>& ref);
	~K_Resource();



	//Public Functions
	///////////////////////////////////////
	T* getResourceData();

	T* operator->(void);
	K_Resource<T> & K_Resource<T>::operator=(const K_Resource<T> & ref);
	


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
K_Resource<T>::K_Resource(const K_Resource<T>& ref) : _referenceCount(ref._referenceCount), _resource(ref._resource)
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

template<typename T>
K_Resource<T> & K_Resource<T>::operator=(const K_Resource<T> & ref)
{
	printf("ASSIGNEMNT CALLED!!!!")
	if (this == &ref)
	{
		++_referenceCount;
		return *this;
	}
	else
	{
		_resource = ref._resource;
		_referenceCount = ref._referenceCount;
		++_referenceCount;
		return *this;
	}
}

#endif // __K_RESOURCE_HPP__
