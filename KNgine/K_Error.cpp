#include "K_Error.hpp"
#include <cstdio>

K_Error::K_Error(std::string name,std::string data)
{
	_errorContextName.push(name);
	_errorContextData.push(data);
}

K_Error::~K_Error()
{
	_errorContextName.pop();
	_errorContextData.pop();
}




void K_Error::dump()
{

	printf("Critical error occurred:\n");
	while(!_errorContextData.empty())
	{
		printf("	%s: %s\n", _errorContextName.top().c_str(), _errorContextData.top().c_str());
		_errorContextName.pop();
		_errorContextData.pop();
	}

	printf("Press enter to exit...");
	getchar();

	exit(1);
}
