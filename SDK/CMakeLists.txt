cmake_minimum_required(VERSION 3.10)
project(vJoy++)
include_directories(include)
include_directories(src/vJoy++/include)


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
install(FILES ${VJOY_LIB} DESTINATION lib)

add_subdirectory(src/test_client)
add_subdirectory(src/vJoy++)
if(BUILD_PYTHON_BINDING)
	add_subdirectory(python_binding)
endif()
set(${PROJECT_NAME}Targets vJoy++)
include(modules/GenerateCMakeConfig.cmake)
include(modules/CPackSettings.cmake)