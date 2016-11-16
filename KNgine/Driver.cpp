

#include "K_ResourceManager.hpp"
#include "K_Resource.hpp"
#include "K_TextResource.hpp"

#include <cstdio>

int main(char** args)
{

	K_ResourceManager _manager;


	K_Resource<K_TextResource> text_0 = _manager.getTextResource("Hello");
	K_Resource<K_TextResource> text_2 = _manager.getTextResource("Hello");

	text_0.getResourceData()->getText();

	printf("Test Text Resource: \n %s\n", text_0.getResourceData()->getText().c_str());
	
	printf("Program executed sucessfully press enter to terminate...");
	getchar();
}