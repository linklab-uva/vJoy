cmake_minimum_required(VERSION 3.10)
project(vJoy)
include_directories(include)
link_directories(lib/amd64)

add_executable(vJoyClient
src/vJoyClient.cpp
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(VJOY_LIB ${CMAKE_SOURCE_DIR}/lib/amd64/vJoyInterface.lib)
    set(VJOY_DLL ${CMAKE_SOURCE_DIR}/lib/amd64/vJoyInterface.dll)
else(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(VJOY_LIB ${CMAKE_SOURCE_DIR}/lib/vJoyInterface.lib)
    set(VJOY_DLL ${CMAKE_SOURCE_DIR}/lib/vJoyInterface.dll)
endif()
add_custom_command(TARGET vJoyClient POST_BUILD 
               COMMAND ${CMAKE_COMMAND} -E copy_if_different
               ${VJOY_DLL}              
                $<TARGET_FILE_DIR:vJoyClient>
				)

target_link_libraries(vJoyClient ${VJOY_LIB})
install(TARGETS vJoyClient
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
		)
install(DIRECTORY include/
		DESTINATION include/vJoy
        FILES_MATCHING PATTERN "*.h"
		)
install(FILES ${VJOY_LIB} DESTINATION lib)
install(FILES ${VJOY_DLL} DESTINATION bin)
