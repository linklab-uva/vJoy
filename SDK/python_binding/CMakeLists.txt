cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_subdirectory(pybind11)
include_directories(${PYBIND11_INCLUDE_DIR})

set(_module_name pyvjoy)
add_library(${_module_name} MODULE pyvJoy.cpp)
target_link_libraries(${_module_name} pybind11::module ${VJOY_LIB} vJoy++)
target_compile_definitions(${_module_name} PRIVATE NOMINMAX=1)
target_compile_definitions(${_module_name} PRIVATE VERSION_INFO="1.0.0")
set_target_properties(${_module_name} PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
											 SUFFIX "${PYTHON_MODULE_EXTENSION}")
