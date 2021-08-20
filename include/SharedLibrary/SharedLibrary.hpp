#pragma once

#ifdef _MSC_VER
	#ifdef SHARED_LIBRARY_EXPORT_DEFINE
		#define SHARED_LIBRARY_EXPORT __declspec(dllexport)
	#else
		#define SHARED_LIBRARY_EXPORT __declspec(dllimport)
	#endif
#else
	#define SHARED_LIBRARY_EXPORT
#endif

#include <string>

namespace SharedLibrary
{
	SHARED_LIBRARY_EXPORT void hello_world();

	SHARED_LIBRARY_EXPORT std::string hello_world_str();
}