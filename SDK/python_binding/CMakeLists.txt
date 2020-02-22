add_subdirectory(pybind11)
include_directories(${PYBIND11_INCLUDE_DIR})

set(_module_name pyvjoy)
add_library(${_module_name} MODULE pyvJoy.cpp)
target_link_libraries(${_module_name} pybind11::module ${VJOY_LIB} vJoy++)
target_compile_definitions(${_module_name} PRIVATE NOMINMAX=1)
target_compile_definitions(${_module_name} PRIVATE VERSION_INFO="1.0.0")
set_target_properties(${_module_name} PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
											 SUFFIX "${PYTHON_MODULE_EXTENSION}")
