add_executable(vJoyClient
vJoyClient.cpp
)
target_link_libraries(vJoyClient ${VJOY_LIB})
target_include_directories(vJoyClient
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    )
install(TARGETS vJoyClient
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
		)
