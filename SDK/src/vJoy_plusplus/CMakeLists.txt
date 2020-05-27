#set(Boost_USE_STATIC_LIBS ON)
find_package( Boost REQUIRED COMPONENTS date_time filesystem program_options regex )
message(STATUS "Found the following boost libraries: ${Boost_LIBRARIES}")
set(${PROJECT_NAME}_SOURCES src/vjoy.cpp)
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
target_link_directories(${PROJECT_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${VJOY_LIB_DIR}>
  $<INSTALL_INTERFACE:lib/vjoyinterface>
)
target_link_libraries(${PROJECT_NAME}
 PUBLIC
 ${VJOY_LIB}
 #$<BUILD_INTERFACE:${VJOY_LIB}>
 #$<INSTALL_INTERFACE:\${_IMPORT_PREFIX}/lib/${VJOY_LIB}.lib>
)
target_include_directories(${PROJECT_NAME} 
  PUBLIC
  $<INSTALL_INTERFACE:include>    
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
)
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_debug")
if(BUILD_SHARED_LIBS AND MSVC)
  target_compile_definitions(${PROJECT_NAME} PRIVATE "VJOY_BUILDING_DLL=__declspec(dllexport)")
  target_compile_definitions(${PROJECT_NAME} INTERFACE "VJOY_BUILDING_DLL=__declspec(dllimport)")
else()
  target_compile_definitions(${PROJECT_NAME} PUBLIC VJOY_BUILDING_DLL)
endif()


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
