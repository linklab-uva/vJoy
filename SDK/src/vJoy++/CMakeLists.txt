#set(Boost_USE_STATIC_LIBS ON)
find_package( Boost REQUIRED COMPONENTS date_time filesystem program_options regex )
message(STATUS "Found the following boost libraries: ${Boost_LIBRARIES}")
set(vJoy++_SOURCES src/vjoy.cpp)
add_library(vJoy++ ${vJoy++_SOURCES})
target_link_libraries(vJoy++
 PUBLIC
 $<BUILD_INTERFACE:${VJOY_LIB}>
 $<INSTALL_INTERFACE:\${_IMPORT_PREFIX}/lib/vJoyInterface.lib>    
 )
target_include_directories(vJoy++ 
    PUBLIC
    $<INSTALL_INTERFACE:include>    
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )
set_target_properties(vJoy++ PROPERTIES DEBUG_POSTFIX "_debug")



set(vjoy++_testapp_SOURCES src/vjoy++_testapp.cpp)
add_executable(vjoy++_testapp ${vjoy++_testapp_SOURCES})
target_link_libraries(vjoy++_testapp vJoy++)


install(DIRECTORY include/vJoy++
		DESTINATION include
        FILES_MATCHING PATTERN "*.h"
        )
install(
    TARGETS vJoy++
    EXPORT vJoy++-export
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin COMPONENT runtime
)
install(EXPORT vJoy++-export
  FILE
  vJoy++Targets.cmake
  NAMESPACE
    vjoy::
  DESTINATION
    cmake
)
