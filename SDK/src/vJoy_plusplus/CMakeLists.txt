#set(Boost_USE_STATIC_LIBS ON)
find_package( Boost REQUIRED COMPONENTS date_time filesystem program_options regex )
message(STATUS "Found the following boost libraries: ${Boost_LIBRARIES}")
set(${PROJECT_NAME}_SOURCES src/vjoy.cpp)
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
target_link_libraries(${PROJECT_NAME}
 PUBLIC
 $<BUILD_INTERFACE:${VJOY_LIB}>
 $<INSTALL_INTERFACE:\${_IMPORT_PREFIX}/lib/vJoyInterface.lib>    
 )
target_include_directories(${PROJECT_NAME} 
    PUBLIC
    $<INSTALL_INTERFACE:include>    
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_debug")



set(${PROJECT_NAME}_testapp_SOURCES src/${PROJECT_NAME}_testapp.cpp)
add_executable(${PROJECT_NAME}_testapp ${${PROJECT_NAME}_testapp_SOURCES})
target_link_libraries(${PROJECT_NAME}_testapp ${PROJECT_NAME})


install(DIRECTORY include/${PROJECT_NAME}
		DESTINATION include
        FILES_MATCHING PATTERN "*.h"
        )
install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-export
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin COMPONENT runtime
)
install(EXPORT ${PROJECT_NAME}-export
  FILE
  ${PROJECT_NAME}Targets.cmake
  NAMESPACE
    vjoy::
  DESTINATION
    cmake
)
