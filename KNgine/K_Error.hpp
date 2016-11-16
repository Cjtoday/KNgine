#ifndef __K_ERROR_HPP__
#define __K_ERROR_HPP__

#include <stack>
#include <string>

static std::stack<std::string> _errorContextName;
static std::stack<std::string> _errorContextData;

class K_Error
{
public:
	K_Error(std::string name, std::string data);
	~K_Error();

	static void dump();

private:



};




#endif // __K_ERROR_HPP__

