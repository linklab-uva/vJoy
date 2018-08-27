add_executable(vJoyClient
vJoyClient.cpp
)
target_link_libraries(vJoyClient ${VJOY_LIB})
add_custom_command(TARGET vJoyClient POST_BUILD 
               COMMAND ${CMAKE_COMMAND} -E copy_if_different
               ${VJOY_DLL}              
                $<TARGET_FILE_DIR:vJoyClient>
				)
install(TARGETS vJoyClient
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
		)
