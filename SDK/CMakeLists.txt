cmake_minimum_required(VERSION 3.10)
project(vJoy++)
include_directories(include)
include_directories(src/vJoy++/include)

option(BUILD_PYTHON_BINDING "Generate pybind11 bindings" OFF)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(VJOY_LIB ${CMAKE_SOURCE_DIR}/lib/amd64/vJoyInterface.lib)
    set(VJOY_DLL ${CMAKE_SOURCE_DIR}/lib/amd64/vJoyInterface.dll)
else(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(VJOY_LIB ${CMAKE_SOURCE_DIR}/lib/vJoyInterface.lib)
    set(VJOY_DLL ${CMAKE_SOURCE_DIR}/lib/vJoyInterface.dll)
endif()

install(DIRECTORY include/
		DESTINATION include/vJoy
        FILES_MATCHING PATTERN "*.h"
		)
install(FILES ${VJOY_LIB} DESTINATION lib)
install(FILES ${VJOY_DLL} DESTINATION bin)

add_subdirectory(src/test_client)
add_subdirectory(src/vJoy++)
if(BUILD_PYTHON_BINDING)
	add_subdirectory(python_binding)
endif()
list(APPEND CMAKE_MODULE_PATH modules)
include(modules/CPackSettings.cmake)