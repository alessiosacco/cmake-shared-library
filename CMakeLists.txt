cmake_minimum_required(VERSION 3.19)
# Version 3.19 is required when using CMakePresets.json

project(SharedLibrary VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
include(cmake/TargetPublicHeaders.cmake)

set(SharedLibrary_BUILD_TESTING ON CACHE BOOL "Enable tests for SharedLibrary")
set(SharedLibrary_INSTALL ON CACHE BOOL "Enable install of SharedLibrary")

add_library(SharedLibrary SHARED)

target_compile_definitions(SharedLibrary PRIVATE SHARED_LIBRARY_EXPORT_DEFINE)

target_public_headers(SharedLibrary
	include/SharedLibrary/SharedLibrary.hpp
)

target_sources(SharedLibrary
	PRIVATE
		src/SharedLibrary.cpp
)

target_include_directories(SharedLibrary
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
)

if (SharedLibrary_INSTALL)
	install(TARGETS SharedLibrary
		EXPORT SharedLibraryExport
		RUNTIME		  DESTINATION bin
		LIBRARY		  DESTINATION lib
		ARCHIVE		  DESTINATION lib
		PUBLIC_HEADER DESTINATION include/SharedLibrary
		INCLUDES      DESTINATION include
	)

	include(CMakePackageConfigHelpers)
	write_basic_package_version_file(
	    SharedLibraryVersion.cmake
	    VERSION ${PACKAGE_VERSION}
	    COMPATIBILITY AnyNewerVersion
	)

	install(EXPORT SharedLibraryExport
		FILE SharedLibrary.cmake
		NAMESPACE SharedLibrary::
		DESTINATION lib/CMake/SharedLibrary
	)
endif()

# Google Test library
if ((BUILD_TESTING) AND (SharedLibrary_BUILD_TESTING))
	include(FetchContent)
	FetchContent_Declare(
  		googletest
  		URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
	)
	# For Windows: Prevent overriding the parent project's compiler/linker settings
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest)

	add_executable(SharedLibrary.Tests
		tests/main.cpp
	)

	target_link_libraries(SharedLibrary.Tests
		PRIVATE
			SharedLibrary
			gtest_main
	)

	include(GoogleTest)
	gtest_discover_tests(SharedLibrary.Tests)
endif()