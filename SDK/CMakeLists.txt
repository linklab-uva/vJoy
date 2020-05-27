cmake_minimum_required(VERSION 3.10)
project(vJoy_plusplus)
if(NOT WIN32)
	message(STATUS "Currently, only windows is supported. project will not be built.")
	return()
endif(NOT WIN32)
if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 14)
endif(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_SHARED_LIBS ON)
option(STATIC_CRT "Use static MSVC runtime" OFF)

if((NOT BUILD_SHARED_LIBS) AND MSVC AND STATIC_CRT)
	foreach(flag_var
		CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
		CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
		CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
		CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)

		if(${flag_var} MATCHES "/MD")
		string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
		endif(${flag_var} MATCHES "/MD")
	endforeach(flag_var)
endif()

option(BUILD_PYTHON_BINDING "Generate pybind11 bindings" OFF)
option(BUILD_TEST_CLIENT "Build the test executable" OFF)
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install CACHE PATH "..." FORCE)
endif()
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(VJOY_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/amd64)
else(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(VJOY_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
endif()
set(VJOY_LIB vJoyInterface)

install(DIRECTORY include/vJoy
		DESTINATION include
        FILES_MATCHING PATTERN "*.h"
		)
install(FILES ${VJOY_LIB_DIR}/${VJOY_LIB}.lib
#EXPORT ${PROJECT_NAME}-export
DESTINATION lib/vjoyinterface
)
if(BUILD_TEST_CLIENT)
	add_subdirectory(src/test_client)
endif(BUILD_TEST_CLIENT)
add_subdirectory(src/${PROJECT_NAME})
if(BUILD_PYTHON_BINDING)
	add_subdirectory(python_binding)
endif()
set(${PROJECT_NAME}Targets ${PROJECT_NAME})
include(modules/GenerateCMakeConfig.cmake)
include(modules/CPackSettings.cmake)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake DESTINATION cmake/)
install(EXPORT ${PROJECT_NAME}-export
  FILE
  ${PROJECT_NAME}Targets.cmake
  NAMESPACE
    vjoy::
  DESTINATION
    cmake
)