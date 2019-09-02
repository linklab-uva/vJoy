cmake_minimum_required(VERSION 3.10)
project(vJoy++)
option(BUILD_SHARED_LIBS ON)
option(STATIC_CRT "Use static MSVC runtime" OFF)
if(BUILD_SHARED_LIBS AND MSVC)
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()
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
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install CACHE PATH "..." FORCE)
endif()
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(VJOY_LIB ${CMAKE_SOURCE_DIR}/lib/amd64/vJoyInterface.lib)
	link_directories(${CMAKE_SOURCE_DIR}/lib/amd64)
else(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(VJOY_LIB ${CMAKE_SOURCE_DIR}/lib/vJoyInterface.lib)
	link_directories(${CMAKE_SOURCE_DIR}/lib/amd64)
endif()

install(DIRECTORY include/vJoy
		DESTINATION include
        FILES_MATCHING PATTERN "*.h"
		)
install(FILES ${VJOY_LIB}
#EXPORT vJoy++-export
DESTINATION lib
)

add_subdirectory(src/test_client)
add_subdirectory(src/vJoy++)
# if(BUILD_PYTHON_BINDING)
# 	add_subdirectory(python_binding)
# endif()
set(${PROJECT_NAME}Targets vJoy++)
include(modules/GenerateCMakeConfig.cmake)
include(modules/CPackSettings.cmake)
install(FILES ${CMAKE_BINARY_DIR}/vJoy++-config.cmake DESTINATION cmake/)