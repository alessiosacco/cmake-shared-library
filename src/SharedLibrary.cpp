#include "SharedLibrary/SharedLibrary.hpp"

#include <iostream>

using namespace std::string_literals;

namespace SharedLibrary
{
	void hello_world()
	{
		std::cout << hello_world_str() << std::endl;
	}

	std::string hello_world_str()
	{
		return "Hello world!"s;
	}
}