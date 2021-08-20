#include <SharedLibrary/SharedLibrary.hpp>

#include <gtest/gtest.h>

TEST(SharedLibrary, HelloWorldStr)
{
	ASSERT_EQ("Hello world!", SharedLibrary::hello_world_str());
}